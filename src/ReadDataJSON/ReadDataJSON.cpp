/*
 * @CreateTime: Jun 18, 2017 10:08 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: undefined
 * @Last Modified Time: Jun 24, 2017 3:20 PM
 * @Description: Đọc và ghi các dữ liệu về profile
 */

#include <Data/ReadDataJSON.h>
#include <Find/Find.h>

using namespace std;
using json = nlohmann::json;

bool ReadUserDataJSON() {
	ifstream userfile(FILEUser_focus_JSON, ios::in);

	if (!userfile.is_open()) {
		cout << "File userdata.json open failed" << endl;
#ifndef NDEBUG
		pausescreen();
#endif
		return false;
	}

	userfile >> UserDataJSON;
	return true;
}

bool UpdateUserDataJSON() {
	ofstream userfile(FILEUser_focus_JSON, ios::out);

	if (!userfile.is_open()) {
		cout << "File userdata.json open failed" << endl;
#ifndef NDEBUG
		pausescreen();
#endif
		return false;
	}

	userfile << UserDataJSON.dump(4);
	return true;
}

json readSignUp() {
	ifstream signupfile(FILESignUp_JSON, ios::in);
	json SignUp;

	if (!signupfile.is_open()) {
		cout << "File signup.json open failed" << endl;
#ifndef NDEBUG
		pausescreen();
#endif
		return NULL;
	}

	signupfile >> SignUp;
	return SignUp;
}

bool updateSignUp(json& SignUp) {
	ofstream signupfile(FILESignUp_JSON, ios::out);

	if (!signupfile.is_open()) {
		cout << "File signup.json open failed" << endl;
#ifndef NDEBUG
		pausescreen();
#endif
		return false;
	}

	signupfile << SignUp.dump(4);
	return true;
}

json readRejected() {
	ifstream rejectfile(FILERejected_JSON, ios::in);
	json Rejected = NULL;

	if (!rejectfile.is_open()) {
		cout << "File user_rejected.json open failed" << endl;
#ifndef NDEBUG
		pausescreen();
#endif
		return false;
	}

	rejectfile >> Rejected;
	return Rejected;
}

bool updateRejected(json& Rejected) {
	ofstream rejectfile(FILERejected_JSON, ios::out);

	if (!rejectfile.is_open()) {
		cout << "File rejected.json open failed" << endl;
#ifndef NDEBUG
		pausescreen();
#endif
		return false;
	}

	rejectfile << Rejected.dump(4);
	return true;
}

json readDeleted() {
	ifstream Deletefile(FILEDeleted_JSON, ios::in);
	json Deleted = NULL;

	if (!Deletefile.is_open()) {
		cout << "File user_Deleted.json open failed" << endl;
#ifndef NDEBUG
		pausescreen();
#endif
		return false;
	}

	Deletefile >> Deleted;
	return Deleted;
}

bool updateDeleted(json& Deleted) {
	ofstream Deletefile(FILEDeleted_JSON, ios::out);

	if (!Deletefile.is_open()) {
		cout << "File Deleted.json open failed" << endl;
#ifndef NDEBUG
		pausescreen();
#endif
		return false;
	}

	Deletefile << Deleted.dump(4);
	return true;
}


void RemoveFromCart(string& ISBN, string& userid) {
	unsigned int user_place = FindUserID(userid);
	json cart             = UserDataJSON.at("UserList")[user_place].at("Cart");
	json new_cart         = json::array();
	unsigned int num_cart = cart.size();

	for (unsigned int index = 0; index < num_cart; index++) {
		string ISBN_data = cart[index];
		if (ISBN == ISBN_data) continue;
		new_cart.push_back(ISBN_data);
	}
	UserDataJSON.at("UserList")[user_place].at("Cart") = new_cart;
	UpdateUserDataJSON();
	return;
}