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
	this_user.at("Cart")[cart_num]                    = ISBN;
	UserDataJSON.at("UserList")[CurrentUser.User_num] = this_user;
	UpdateUserDataJSON();
	return;
}