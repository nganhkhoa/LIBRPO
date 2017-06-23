/*
 * @CreateTime: Jun 18, 2017 10:02 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 22, 2017 10:42 AM
 * @Description: Đưa sách cho người nhận, có xác nhận tài khoản
 */

#include <Utilities/Utilities.h>
#include <Browse/Browse.h>
#include <Find/FindBook.h>
#include <Find/Find.h>

#include <Login/Login.h>

#include <Data/ReadDataJSON.h>
#include <Book/ReadBookJSON.h>

using namespace std;
using json = nlohmann::json;

void ReceivedBook(unsigned int& pending_place) {
	json borrowLog = readBorrowLog();
	if (borrowLog == NULL)
		;

	json new_data = json::object();

	new_data["Rejected"]             = borrowLog.at("Rejected");
	new_data["Accepted"]             = json::object();
	new_data["Accepted"]["Received"] = borrowLog.at("Accepted").at("Received");
	new_data["Accepted"]["Returned"] = borrowLog.at("Accepted").at("Returned");
	new_data["Accepted"]["Pending"]  = json::array();

	bool moved                = false;
	unsigned int num_pending  = borrowLog.at("Accepted").at("Pending").size();
	unsigned int num_received = borrowLog.at("Accepted").at("Received").size();

	for (unsigned int index = 0; index < num_pending; index++) {
		if (index == pending_place) {
			moved          = true;
			json data_move = borrowLog.at("Accepted").at("Pending")[index];

			string TODAY = "";
			time_t now   = time(NULL);
			TODAY        = to_string(now);

			data_move["Received Date"]                           = TODAY;
			new_data.at("Accepted").at("Received")[num_received] = data_move;
			continue;
		}

		if (!moved) {
			new_data.at("Accepted").at("Pending")[index] =
			  borrowLog.at("Accepted").at("Pending")[index];
		}
		else {
			new_data.at("Accepted").at("Pending")[index - 1] =
			  borrowLog.at("Accepted").at("Pending")[index];
		}
	}

	return updateBorrowLog(new_data);
}

unsigned int GetPendingPlace(int& submitid) {
	json borrowLog = readBorrowLog();
	if (borrowLog == NULL)
		;

	unsigned int num_pending = borrowLog.at("Accepted").at("Pending").size();

	for (unsigned int index = 0; index < num_pending; index++) {
		int SubmitID =
		  borrowLog.at("Accepted").at("Pending")[index].at("Submit ID");

		if (submitid == SubmitID) { return index; }
	}
	return num_pending;    // this never happens
}

void AddBorrowBook(int& submitid) {
	json Submit            = readSubmitBorrow();
	unsigned int num_check = Submit.at("Checked").size();

	for (unsigned int index = 0; index < num_check; index++) {
		int submitid_data = Submit.at("Checked")[index].at("Submit ID");
		if (submitid == submitid_data) {
			string ISBN             = Submit.at("Checked")[index].at("ISBN");
			unsigned int book_place = FindBookIndex(ISBN);
			unsigned int borrowed =
			  BookDataJSON.at("BookLibrary")[book_place].at("Borrowed");
			borrowed += 1;
			BookDataJSON.at("BookLibrary")[book_place].at("Borrowed") =
			  borrowed;

			if (!UpdateBookDataJSON()) {
				cout << "Cap nhat du lieu sach khong thanh cong" << endl;
				pausescreen();
			}
			return;
		}
	}
}

void CreateUserBorrow(string& userID, int& submitid) {
	json Submit            = readSubmitBorrow();
	unsigned int num_check = Submit.at("Checked").size();

	for (unsigned int index = 0; index < num_check; index++) {
		int submitid_data = Submit.at("Checked")[index].at("Submit ID");
		if (submitid == submitid_data) {
			string ISBN             = Submit.at("Checked")[index].at("ISBN");
			unsigned int userid     = FindUserID(userID);
			json this_user          = json::object();
			this_user               = UserDataJSON.at("UserList")[userid];
			unsigned int borrow_key = this_user.count("Borrow");
			unsigned int borrow_num = 0;

			if (borrow_key == 0) { this_user["Borrow"] = json::array(); }
			else {
				borrow_num = this_user.at("Borrow").size();
			}

			json new_borrow                    = json::object();
			new_borrow["Submit ID"]            = submitid;
			new_borrow["ISBN"]                 = ISBN;
			this_user.at("Borrow")[borrow_num] = new_borrow;

			UserDataJSON.at("UserList")[userid] = this_user;
			if (!UpdateUserDataJSON()) {
				cout << "Cap nhat nguoi dung khong thanh cong" << endl;
				pausescreen();
			}
			return;
		}
	}
}

int ChooseSubmitID(vector<unsigned int>& submitid_list) {
	vector<string> result = {};

	json Submit              = readSubmitBorrow();
	unsigned int list_size   = submitid_list.size();
	unsigned int num_checked = Submit.at("Checked").size();

	for (unsigned int list = 0; list < list_size; list++) {

		for (unsigned int index = 0; index < num_checked; index++) {
			unsigned int SubmitID = Submit.at("Checked")[index].at("Submit ID");
			if (SubmitID == submitid_list[list]) {
				string ISBN = Submit.at("Checked")[index].at("ISBN");
				result.push_back(ISBN);
			}
		}
	}

	json resultJSON = ISBNtoJSON(result);
	clearscreen();
	int submitid            = submitid_list[ShowBookResult(resultJSON) - 1];
	int num_book_resultJSON = resultJSON.at("BookLibrary").size() + 1;
	if (submitid == num_book_resultJSON) { return -1; }
	else {
		return submitid;
	}
}

void RemoveDontCare(vector<unsigned int>& submitid_list) {
	json borrowLog = readBorrowLog();
	if (borrowLog == NULL)
		;

	vector<unsigned int> new_submit_list = {};
	unsigned int num_pending = borrowLog.at("Accepted").at("Pending").size();
	unsigned int list_size   = submitid_list.size();

	for (unsigned int index = 0; index < num_pending; index++) {
		unsigned int submitID =
		  borrowLog.at("Accepted").at("Pending")[index].at("Submit ID");

		for (unsigned int list = 0; list < list_size; list++) {
			if (submitID == submitid_list[list]) {
				new_submit_list.push_back(submitid_list[list]);
			}
		}
	}

	submitid_list = new_submit_list;
}

vector<unsigned int> FindUserSubmit(string& userID) {
	vector<unsigned int> submitid_list = {};

	json Submit = readSubmitBorrow();

	unsigned int num_checked = Submit.at("Checked").size();

	for (unsigned int index = 0; index < num_checked; index++) {
		string User = Submit.at("Checked")[index].at("User");
		if (User == userID) {
			unsigned int submitid = Submit.at("Checked")[index].at("Submit ID");
			submitid_list.push_back(submitid);
		}
	}

	return submitid_list;
}

string FindUserGiveBook() {
	string username = "";
	string pwd      = "";
	cout << "Nhap ten nguoi dung: ";
	getline(cin, username);
	cout << "Nhap mat khau: ";
	pwd = HidePassword();

	unsigned int num_user_max = UserDataJSON.at("UserList").size();
	int user_place            = ValidateUserLogin(username, pwd);
	string userid             = "";

	if (user_place == (int) num_user_max) {
		cout << "Khong tim thay thong tin nguoi dung" << endl;
		cout << "Moi ban thu lai" << endl;
		pausescreen();
	}
	else {
		userid = UserDataJSON.at("UserList")[user_place].at("UserID");
	}

	return userid;
}

void GiveBook() {
	string userID = FindUserGiveBook();

	if (userID == "") return;

	vector<unsigned int> submitid_list = FindUserSubmit(userID);

	RemoveDontCare(submitid_list);

	// only show from pending
	// if rejected, send notyfication to user
	// so they should khow that they are not allowed to borrow
	int submitid = ChooseSubmitID(submitid_list);
	if (submitid == -1) return;

	CreateUserBorrow(userID, submitid);
	AddBorrowBook(submitid);

	unsigned int pending_place = GetPendingPlace(submitid);


	ReceivedBook(pending_place);
}