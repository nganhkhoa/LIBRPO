#include <Utilities/Utilities.h>
#include <Find/Find.h>
#include <SignUp/SignUp.h>

using namespace std;

void PwdReset() {

	clearscreen();
	cout << "Nhap id nguoi dung muon reset mat khau:" << endl;
	cout << ">> ";
	string userid = "";
	getline(cin, userid);
	unsigned int user_place = FindUserID(userid);
	if (user_place == UserDataJSON.at("UserList").size()) {
		cout << "Ten nguoi dung khong tim thay" << endl;
		pausescreen();
		return;
	}

	UserDataJSON.at("UserList")[user_place].at("First")    = true;
	string pwd                                             = RandomPassword();
	UserDataJSON.at("UserList")[user_place].at("Password") = pwd;

	string username = UserDataJSON.at("UserList")[user_place].at("username");

	clearscreen();
	cout << "Dat lai mat khau cho nguoi dung, ket qua" << endl;
	cout << "________________________________________" << endl;
	cout << "Tai khoan so:  " << userid << endl;
	cout << "Ten tai khoan: " << username << endl;
	cout << "Mat khau moi:  " << pwd << endl;
	cout << "________________________________________" << endl;
	return;
}