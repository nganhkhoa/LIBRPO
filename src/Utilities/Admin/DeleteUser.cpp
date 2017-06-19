/*
 * @CreateTime: Jun 18, 2017 10:29 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 19, 2017 4:07 PM
 * @Description: Xoá người dùng
 */

#include <Utilities/Utilities.h>
#include <Data/ReadDataJSON.h>
#include <Find/Find.h>

using namespace std;
using json = nlohmann::json;

json RemoveUser(unsigned int& userplace) {
	bool removed            = false;
	unsigned int num_user   = UserDataJSON.at("UserList").size();
	json NewUserData        = json::object();
	NewUserData["UserList"] = json::array();

	for (unsigned int index = 0; index < num_user; index++) {
		if (index == userplace) {
			removed = true;
			continue;
		}

		if (!removed) {
			NewUserData.at("UserList")[index] =
			  UserDataJSON.at("UserList")[index];
		}
		else {
			NewUserData.at("UserList")[index - 1] =
			  UserDataJSON.at("UserList")[index];
		}
	}

	return NewUserData;
}

void DeleteUserplace(unsigned int& userplace) {
	json deleted                       = readDeleted();
	json user_delete                   = UserDataJSON.at("UserList")[userplace];
	unsigned int num_deleted           = deleted.at("Deleted").size();
	deleted.at("Deleted")[num_deleted] = user_delete;

	UserDataJSON = RemoveUser(userplace);
	UpdateUserDataJSON();
	updateDeleted(deleted);
	return;
}

void DeleteUser() {
	clearscreen();
	cout << "Nhap ma so nguoi dung muon xoa: ";
	string uid = "";
	getline(cin, uid);
	if (uid == "") return;

	unsigned int userplace = FindUserID(uid);

	if (userplace == UserDataJSON.at("UserList").size()) {
		cout << "Nguoi dung mang ma so " << uid << " khong ton tai" << endl;
		system("pause");
		return;
	}
	// ShowUserInfo(userplace);

	cout << "Ban muon xoa nguoi dung nay?(y/n) ";
	string Answer = "";
	getline(cin, Answer);
	if (Answer != "y") return;

	DeleteUserplace(userplace);
	cout << "Nguoi dung mang ma so: " << uid << " da bi xoa" << endl;
	system("pause");
	return;
}