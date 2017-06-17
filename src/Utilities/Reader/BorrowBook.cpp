#include <Utilities/Utilities.h>
#include <Browse/Browse.h>
#include <Find/FindBook.h>

using namespace std;
using json = nlohmann::json;

void addnewSubmit(json& Submit, string& ISBN) {
	json newsubmit = json::object();

	unsigned int submitid = 0;

	unsigned int check_num     = Submit.at("Checked").size();
	unsigned int submition_num = Submit.at("Submition").size();

	check_num > submition_num ? submitid = 1 + check_num
	                          : submitid = 1 + submition_num;


	newsubmit["ISBN"]         = ISBN;
	newsubmit["User"]         = CurrentUser.UserID;
	newsubmit["Request Date"] = "Today";
	newsubmit["Submit ID"]    = submitid;

	Submit.at("Submition")[Submit.at("Submition").size()] = newsubmit;
}

bool CreateRequestBorrowBook(string& ISBN) {
	json Submit = readSubmitBorrow();

	addnewSubmit(Submit, ISBN);

	return undateSubmitBorrow(Submit);
}

bool CurrentlyBorrow(string& ISBN) {
	json this_user          = UserDataJSON.at("UserList")[CurrentUser.User_num];
	unsigned int borrow_key = this_user.count("Borrow");

	if (borrow_key == 0) return false;

	unsigned int borrow_num = this_user.at("Borrow").size();

	for (unsigned int index = 0; index < borrow_num; index++) {
		string ISBN_data = this_user.at("Borrow")[index].at("ISBN");
		if (ISBN == ISBN_data) return true;
	}
	return false;
}

bool NoCart() {
	json this_user        = UserDataJSON.at("UserList")[CurrentUser.User_num];
	unsigned int cart_key = this_user.count("Cart");

	if (cart_key != 0)
		return false;
	else
		return true;
}

json JSONFromCart() {

	if (NoCart()) {
		cout << "Ban khong co gio hang" << endl;
		pausescreen();
		return NULL;
	}

	json this_user = UserDataJSON.at("UserList")[CurrentUser.User_num];

	unsigned int cartsize = this_user.at("Cart").size();

	vector<string> ISBN_list = {};

	for (unsigned int index = 0; index < cartsize; index++) {
		string ISBN = this_user.at("Cart")[index];
		ISBN_list.push_back(ISBN);
	}
	return ISBNtoJSON(ISBN_list);
}

void BorrowBook() {
	while (true) {
		clearscreen();
		cout << "Nhap ten sach ban muon muon" << endl;
		cout << "Neu de trong se quay ve" << endl;
		cout << "Neu ban muon muon tu gio sach, go \"--giosach\"" << endl;
		cout << "Ten sach: ";
		string keywords;
		getline(cin, keywords);

		json resultJSON = NULL;
		int BookIndex   = -1;

		if (keywords.empty()) return;
		if (keywords == "--giosach") {
			resultJSON = JSONFromCart();
			if (resultJSON == NULL) return;
			BookIndex = ShowBookResult(resultJSON) - 1;
		}
		else {
			BookIndex = FindBookBorrow(keywords, resultJSON);
			if (BookIndex == -1) {
				cout << "Ten sach khong tim thay" << endl;
				cout << "Moi ban nhap lai" << endl;
				cout << "Bam enter de tiep tuc" << endl;
				pausescreen();
				continue;
			}
		}

		// found but choose to exit rather than book
		if (BookIndex == (int) resultJSON.at("BookLibrary").size()) { return; }

		string ISBN = resultJSON.at("BookLibrary")[BookIndex].at("ISBN");

		//*
		if (CurrentlyBorrow(ISBN)) {
			cout << "Ban dang muon quyen sach nay" << endl;
			cout << "Chung toi khong cho ban gui phieu muon" << endl;
			pausescreen();
			continue;
		}
		//*/

		if (!CreateRequestBorrowBook(ISBN)) {
			cout << "Yeu cau khong gui duoc" << endl;
			cout << "Bam enter de tiep tuc" << endl;
			pausescreen();
			return;
		}

		cout << "Yeu cau da duoc gui," << endl;
		cout << "Cho xac nhan cua thu thu" << endl;
		cout << "Bam enter de quay ve" << endl;
		pausescreen();
		return;
	}
}