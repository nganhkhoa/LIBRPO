#include <Utilities/Utilities.h>
#include <Browse/Browse.h>
#include <Find/FindBook.h>
#include <Login/Login.h>

using namespace std;
using json = nlohmann::json;

void RecieivedBook(unsigned int& pending_place) {
	json borrowLog = readBorrowLog();
	if (borrowLog == NULL)
		;

	json new_data = json::object();

	new_data["Rejected"] = borrowLog.at("Rejected");
	new_data["Accepted"] = json::object();
	new_data["Accepted"]["Received"] = borrowLog.at("Accepted").at("Received");
	new_data["Accepted"]["Returned"] = borrowLog.at("Accepted").at("Returned");
	new_data["Accepted"]["Pending"]  = json::array();

	bool moved = false;
	unsigned int num_pending  = borrowLog.at("Accepted").at("Pending").size();
	unsigned int num_received = borrowLog.at("Accepted").at("Received").size();

	for (unsigned int index = 0; index < num_pending; index++) {
		if (index == pending_place) { 
			moved = true;
			json data_move = borrowLog.at("Accepted").at("Pending")[index];
			new_data.at("Accepted").at("Received")[num_received] = data_move;
			continue;
		}
			 
		if (!moved) {
			new_data.at("Accepted").at("Pending")[index] =
			  borrowLog.at("Accepted").at("Pending")[index];
		} else {
			new_data.at("Accepted").at("Pending")[index - 1] =
			  borrowLog.at("Accepted").at("Pending")[index];
		}
	}

	return updateBorrowLog(new_data);
}

unsigned int GetPendingPlace(unsigned int& submitid) {
	json borrowLog = readBorrowLog();
	if (borrowLog == NULL)
		;

	unsigned int num_pending = borrowLog.at("Accepted").at("Pending").size();

	for (unsigned int index = 0; index < num_pending; index++) {
		unsigned int SubmitID =
		  borrowLog.at("Accepted").at("Pending")[index].at("Submit ID");

		if (submitid == SubmitID) { return index; }
	}
	return num_pending; // this never happens
}

unsigned int ChooseSubmitID(vector<unsigned int>& submitid_list) {
	vector<string> result = {};

	json Submit = readSubmitBorrow();
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

	unsigned int pending_place = submitid_list[ShowBookResult(resultJSON) - 1];
	return pending_place;
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
	getline(cin, pwd);

	unsigned int num_user_max     = UserDataJSON.at("UserList").size();
	int user_place                = ValidateUserLogin(username, pwd);
	string userid                 = "";

	if (user_place == (int)num_user_max) {
		cout << "Khong tim thay thong tin nguoi dung" << endl;
		cout << "Moi ban thu lai" << endl;
		system("pause");
	} else {
		userid  = UserDataJSON.at("UserList")[user_place].at("UserID");
	}

	return userid;
}

void GiveBook() {
	string userID = FindUserGiveBook();

	if (userID == "") return;

	vector<unsigned int> submitid_list = FindUserSubmit(userID);

	//RemoveReject(submitid_list);

	// only show from pending
	// if rejected, send notyfication to user
	// so they should khow that they are not allowed to borrow
	unsigned int submitid      = ChooseSubmitID(submitid_list);
	unsigned int pending_place = GetPendingPlace(submitid);

	RecieivedBook(pending_place);
}