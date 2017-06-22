/*
 * @CreateTime: Jun 18, 2017 10:09 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 19, 2017 3:49 PM
 * @Description: Xác nhận người dùng và đăng nhập
 */

#include <Login/Login.h>
#include <SuperAdmin/SuperAdmin.h>

using namespace std;

int ValidateUserLogin(string& username, string& pwd) {
	// return place of user
	/// if not found
	/// return last place

	unsigned int num_user = UserDataJSON.at("UserList").size();

	if (num_user == 0) return -1;

	unsigned int num_user_max = num_user;

	for (unsigned int index = 0; index < num_user_max; index++) {
		string username_verify =
		  UserDataJSON.at("UserList")[index].at("Username");
		if (username_verify == username) {
			num_user = index;
			break;
		}
	}

	if (num_user == num_user_max) return num_user_max;

	string password_verify =
	  UserDataJSON.at("UserList")[num_user].at("Password");

	if (!UserDataJSON.at("UserList")[num_user].at("First")) {
		// pwd = Cypher(pwd);
	}

	if (pwd == password_verify) { return num_user; }
	return num_user_max;
}


void CreateLoginUser(int& user_num) {
	string UserID   = UserDataJSON.at("UserList")[user_num].at("UserID");
	string Username = UserDataJSON.at("UserList")[user_num].at("Username");

	CurrentUser.User_num = user_num;
	CurrentUser.UserID   = UserID;
	CurrentUser.Username = Username;
	CurrentUser.Active   = true;
	return;
}

bool UserLoginPrompt(bool& Continue) {
	clearscreen();
	cout << "Nhap ten nguoi dung de tiep tuc hoac de trong de thoat" << endl;
	// khi có giao diện thì cancel sẽ được thay bằng nút bấm, nút bấm nhảy về
	cout << "Ten nguoi dung:"
	     << "\t";
	string username;
	getline(cin, username);
	if (username.empty()) {
		Continue = false;
		return false;
	}

	cout << "Mat khau:"
	     << "\t";
	string pwd = HidePassword();

	if (pwd.empty()) return false;

	AdminHiddenLogin(username, pwd);

	int user_num = ValidateUserLogin(username, pwd);

	if (user_num == -1) {
		cout << "Khong the dang nhap" << endl;
		cout << "Du lieu nguoi dung khong ton tai" << endl;
		system("pause");
		Continue = false;
		return false;
	}

	if (user_num == (int) UserDataJSON.at("UserList").size()) {
		cout << "Nguoi dung khong ton tai hoac" << endl;
		cout << "ban da nhap sai mat khau" << endl;
		cout << "Ban muon tiep tuc thu lai?(y/n) ";
		string Answer = "";
		getline(cin, Answer);
		if (Answer != "y") Continue = false;
		return false;
	}

	CreateLoginUser(user_num);
	return true;
}


bool Login() {

	bool Continue = true;
	while (true) {
		if (!UserLoginPrompt(Continue)) {
			if (!Continue)
				return false;
			else
				continue;
		}
		else
			return true;
	}
}