#include <Utilities/Utilities.h>
#include <Data/ReadDataJSON.h>
#include <Find/Find.h>

using namespace std;

void PrintCheck(unsigned int& user_place, double MONEY) {
	clearscreen();
	nlohmann::json this_user = UserDataJSON.at("UserList")[user_place];

	string uid = this_user.at("UserID");
	string username = this_user.at("Username");
	double balance  = this_user.at("Balance");

	string firstname = this_user.at("UserFirstName");
	string lastname = this_user.at("UserLastName");

	cout << "Nguoi dung ma so: " << uid << endl;
	cout << "Ten nguoi dung: " << username << endl;
	cout << "\t" << firstname << " " << lastname << endl;
	cout << "Da nap thanh cong: " << MONEY << " VND" << endl;
	cout << "So tien hien co: " << balance << endl;
	pausescreen();
}

void Charge() {

	clearscreen();
	cout << "Nhap id nguoi dung muon nap tien:" << endl;
	cout << ">> ";
	string userid = "";
	getline(cin, userid);
	unsigned int user_place = FindUserID(userid);
	if (user_place == UserDataJSON.at("UserList").size()) {
		cout << "Ten nguoi dung khong tim thay" << endl;
		pausescreen();
		return;
	}

	cout << "Nhap so tien them vao" << endl;
	cout << "Don vi la VND" << endl;
	cout << ">> ";
	double MONEY = 0;
	cin >> MONEY;

	double balance = UserDataJSON.at("UserList")[user_place].at("Balance");
	balance += MONEY;
	UserDataJSON.at("UserList")[user_place].at("Balance") = balance;

	UpdateUserDataJSON();
	PrintCheck(user_place, MONEY);
}