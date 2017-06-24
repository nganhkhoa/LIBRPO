/*
 * @CreateTime: Jun 24, 2017 1:38 PM
 * @Author: undefined
 * @Contact: undefined
 * @Last Modified By: undefined
 * @Last Modified Time: Jun 24, 2017 2:46 PM
 * @Description: Modify Here, Please
 */


#include <Browse/Browse.h>
#include <Data/ReadDataJSON.h>

using namespace std;
using json = nlohmann::json;

void AddtoCart(json& bookdata, int& BookCart) {
	json this_user        = UserDataJSON.at("UserList")[CurrentUser.User_num];
	unsigned int cart_key = this_user.count("Cart");
	unsigned int cart_num = 0;
	if (cart_key == 0) { this_user["Cart"] = json::array(); }
	else {
		cart_num = this_user.at("Cart").size();
	}

	string ISBN = bookdata.at("BookLibrary")[BookCart - 1].at("ISBN");
	for (unsigned int index = 0; index < cart_num; index++) {
		string ISBN_data = this_user.at("Cart")[index];
		if (ISBN == ISBN_data) {
			cout << "Quyen nay hien da co trong gio sach" << endl;
			pausescreen();
			return;
		}
	}
	this_user.at("Cart")[cart_num]                    = ISBN;
	UserDataJSON.at("UserList")[CurrentUser.User_num] = this_user;
	UpdateUserDataJSON();
	return;
}

void AddtoFav(json& bookdata, int& BookFav) {
	json this_user       = UserDataJSON.at("UserList")[CurrentUser.User_num];
	unsigned int Fav_key = this_user.count("Fav");
	unsigned int Fav_num = 0;
	if (Fav_key == 0) { this_user["Fav"] = json::array(); }
	else {
		Fav_num = this_user.at("Fav").size();
	}

	string ISBN = bookdata.at("BookLibrary")[BookFav - 1].at("ISBN");
	for (unsigned int index = 0; index < Fav_num; index++) {
		string ISBN_data = this_user.at("Fav")[index];
		if (ISBN == ISBN_data) {
			cout << "Quyen nay hien da co trong bo suu tap" << endl;
			pausescreen();
			return;
		}
	}
	this_user.at("Fav")[Fav_num]                      = ISBN;
	UserDataJSON.at("UserList")[CurrentUser.User_num] = this_user;
	UpdateUserDataJSON();
	return;
}