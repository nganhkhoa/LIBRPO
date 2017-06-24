#include <Utilities/Utilities.h>
#include <Browse/Browse.h>
#include <Find/FindBook.h>

using namespace std;
using json = nlohmann::json;

void ShowFav() {
	json this_user       = UserDataJSON.at("UserList")[CurrentUser.User_num];
	unsigned int Fav_key = this_user.count("Fav");
	if (Fav_key == 0) {
		cout << "Ban khong co sach trong bo suu tap" << endl;
		pausescreen();
		return;
	}

	unsigned int num_fav = this_user.at("Fav").size();
	if (num_fav == 0) {
		cout << "Ban khong co sach trong bo suu tap" << endl;
		pausescreen();
		return;
	}

	vector<string> result = {};

	for (unsigned int index = 0; index < num_fav; index++) {
		string ISBN = this_user.at("Fav")[index];
		result.push_back(ISBN);
	}
	json resultJSON = ISBNtoJSON(result);
	ShowAllBook(resultJSON);
	return;
}

void ShowCart() {
	json this_user        = UserDataJSON.at("UserList")[CurrentUser.User_num];
	unsigned int Cart_key = this_user.count("Cart");
	if (Cart_key == 0) {
		cout << "Ban khong co sach trong gio hang" << endl;
		pausescreen();
		return;
	}

	unsigned int num_Cart = this_user.at("Cart").size();
	if (num_Cart == 0) {
		cout << "Ban khong co sach trong gio hang" << endl;
		pausescreen();
		return;
	}

	vector<string> result = {};

	for (unsigned int index = 0; index < num_Cart; index++) {
		string ISBN = this_user.at("Cart")[index];
		result.push_back(ISBN);
	}
	json resultJSON = ISBNtoJSON(result);
	ShowAllBook(resultJSON);
	return;
}

void ShowBorrow() {
	json this_user          = UserDataJSON.at("UserList")[CurrentUser.User_num];
	unsigned int Borrow_key = this_user.count("Borrow");
	if (Borrow_key == 0) {
		cout << "Ban khong co sach dang muon" << endl;
		pausescreen();
		return;
	}

	unsigned int num_Borrow = this_user.at("Borrow").size();
	if (num_Borrow == 0) {
		cout << "Ban khong co sach dang muon" << endl;
		pausescreen();
		return;
	}

	vector<string> result = {};

	for (unsigned int index = 0; index < num_Borrow; index++) {
		string ISBN = this_user.at("Borrow")[index].at("ISBN");
		result.push_back(ISBN);
	}
	json resultJSON = ISBNtoJSON(result);
	ShowAllBook(resultJSON);
	return;
}