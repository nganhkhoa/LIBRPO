#include <Utilities/Utilities.h>
#include <Find/Find.h>
#include <Find/FindBook.h>
#include <Browse/Browse.h>

#include <Data/ReadDataJSON.h>
#include <Book/ReadBookJSON.h>

using namespace std;
using json = nlohmann::json;

void BookDataReturn(int& submitid) {
	json Submit = readSubmitBorrow();
	unsigned int num_check = Submit.at("Checked").size();

	string ISBN = "";
	for (unsigned int index = 0; index < num_check; index++) {
		int submitid_data = Submit.at("Checked")[index].at("Submit ID");
		if (submitid == submitid_data) {
			ISBN = Submit.at("Checked")[index].at("ISBN");
			break;
		}
	}

	unsigned int book_place = FindBookIndex(ISBN);
	int borrowed = BookDataJSON.at("BookLibrary")[book_place].at("Borrowed");
	borrowed -= 1;
	BookDataJSON.at("BookLibrary")[book_place].at("Borrowed") = borrowed;

	if (!UpdateBookDataJSON()) {
		cout << "Khong the cap nhat du lieu sach" << endl;
		cout << "Hay thu lai sau" << endl;
		pausescreen();
	}
}

void UserDataReturn(string& userid, int& submitid) {
	unsigned int user_place = FindUserID(userid);
	json old_borrow = UserDataJSON.at("UserList")[user_place].at("Borrow");
	unsigned int num_borrow = old_borrow.size();

	json new_borrow = json::array();
	bool deleted    = false;

	for (unsigned int index = 0; index < num_borrow; index++) {
		int submitid_data = old_borrow[index].at("Submit ID");
		if (submitid == submitid_data) {
			deleted = true;
			continue;
		}

		if (!deleted) { new_borrow[index] = old_borrow[index]; }
		else {
			new_borrow[index - 1] = old_borrow[index];
		}
	}
	UserDataJSON.at("UserList")[user_place].at("Borrow") = new_borrow;
	if (!UpdateUserDataJSON()) {
		cout << "Khong the cap nhat du lieu nguoi dung" << endl;
		cout << "Hay thu lai sau" << endl;
		pausescreen();
	}
}


void ReturnBookSubmit(int& submitid) {
	json borrowLog = readBorrowLog();

	json new_data = json::object();
	new_data["Rejected"] = borrowLog.at("Rejected");
	new_data["Accepted"] = json::object();
	new_data.at("Accepted")["Pending"] = borrowLog.at("Accepted").at("Pending");
	new_data.at("Accepted")["Returned"] = borrowLog.at("Accepted").at("Returned");
	new_data.at("Accepted")["Received"] = json::array();

	bool moved = false;
	unsigned int num_received = borrowLog.at("Accepted").at("Received").size();
	unsigned int num_returned = borrowLog.at("Accepted").at("Returned").size();

	for (unsigned int index = 0; index < num_received; index++) {
		int submitid_data =
		  borrowLog.at("Accepted").at("Received")[index].at("Submit ID");
		if (submitid_data == submitid) { 
			moved = true;
			new_data.at("Accepted").at("Returned")[num_returned] =
			  borrowLog.at("Accepted").at("Received")[index];

			new_data.at("Accepted")
			  .at("Returned")[num_returned]["Returned Date"] = "Today";
			continue;
		}
		if (!moved) {
			new_data.at("Accepted").at("Received")[index] =
			  borrowLog.at("Accepted").at("Received")[index];
		} else {
			new_data.at("Accepted").at("Received")[index - 1] =
			  borrowLog.at("Accepted").at("Received")[index];
		}
	}
	updateBorrowLog(new_data);
	return;
}


vector<unsigned int> GetSubmitID(unsigned int& num_user) {
	unsigned int num_borrow =
	  UserDataJSON.at("UserList")[num_user].at("Borrow").size();

	vector<unsigned int> result = {};

	for (unsigned int index = 0; index < num_borrow; index++) {
		unsigned int submitid =
		  UserDataJSON.at("UserList")[num_user].at("Borrow")[index].at("Submit ID");
		result.push_back(submitid);
	}
	return result;
}

vector<string> GetSubmitISBN(unsigned int& num_user) {
	unsigned int num_borrow =
	  UserDataJSON.at("UserList")[num_user].at("Borrow").size();

	vector<string> result = {};

	for (unsigned int index = 0; index < num_borrow; index++) {
		string ISBN =
		  UserDataJSON.at("UserList")[num_user].at("Borrow")[index].at("ISBN");
		result.push_back(ISBN);
	}
	return result;
}


int ChooseReturnBook(string& userid) {
	unsigned int num_user = FindUserID(userid);
	unsigned int borrow_key = UserDataJSON.at("UserList")[num_user].count("Borrow");

	if (borrow_key == 0) {
		cout << "Ban khong co sach de tra" << endl;
		pausescreen();
		return -1;
	}

	vector<string> submit_isbn = GetSubmitISBN(num_user);
	vector<unsigned int> submitid_list = GetSubmitID(num_user);

	json submit_isbn_json = ISBNtoJSON(submit_isbn);

	cout << "Ban co " << submit_isbn.size() << " quyen sach de tra" << endl;
	cout << "Chon quyen ban muon tra" << endl;

	unsigned int submit_list_place = ShowBookResult(submit_isbn_json) - 1;
	if (submit_list_place == submit_isbn.size()) return -1;
	return submitid_list[submit_list_place];
}

void ReturnBook() {
	clearscreen();
	int submitid = ChooseReturnBook(CurrentUser.UserID);
	if (submitid == -1) return;

	ReturnBookSubmit(submitid);
	//if (LateReturn(submitid)) { FineLateReturn(CurrentUser.UserID); }

	BookDataReturn(submitid);
	UserDataReturn(CurrentUser.UserID, submitid);

	cout << "Ban da tra sach thanh cong" << endl;
	pausescreen();
	return;
}