#include <Utilities/Utilities.h>
#include <Find/Find.h>
#include <Setting/Setting.h>
#include <Data/ReadDataJSON.h>

using namespace std;
using json = nlohmann::json;


unsigned int LockPromptChoose(unsigned int& user_place) {
	json this_user           = UserDataJSON.at("UserList")[user_place];
	unsigned int num_account = this_user.at("AccountList").size();

	return (unsigned int) ChoiceInput((int) num_account + 3);
}

void LockPrompt(unsigned int& user_place) {
	json this_user           = UserDataJSON.at("UserList")[user_place];
	unsigned int num_account = this_user.at("AccountList").size();

	cout << "Chon tai khoan nao thi tai khoan do bi dao nguoc lai" << endl;
	for (unsigned int index = 0; index < num_account; index++) {
		string account_name =
		  this_user.at("AccountList")[index].at("AccountName");
		bool lock = this_user.at("AccountList")[index].at("Lock");
		cout << index + 1 << "\t" << account_name << "\t" << boolalpha << lock
		     << endl;
	}

	cout << num_account + 1 << "\tMo khoa het" << endl;
	cout << num_account + 2 << "\tKhoa het" << endl;
	cout << num_account + 3 << "\tThoat" << endl;
	cout << "Lua chon: ";
}


void UserLock() {
	clearscreen();
	cout << "Nhap id nguoi dung muon quan ly khoa:" << endl;
	cout << ">> ";
	string userid = "";
	getline(cin, userid);
	unsigned int user_place = FindUserID(userid);
	if (user_place == UserDataJSON.at("UserList").size()) {
		cout << "Ten nguoi dung khong tim thay" << endl;
		pausescreen();
		return;
	}

	LockPrompt(user_place);

	unsigned int Choice = LockPromptChoose(user_place);
	unsigned int num_account =
	  UserDataJSON.at("UserList")[user_place].at("AccountList").size();

	if (Choice == num_account + 3) return;
	if (Choice == num_account + 2) { LockAllAccount(user_place); }

	if (Choice == num_account + 1) { UnLockAllAccount(user_place); }
	else {
		bool lock = UserDataJSON.at("UserList")[user_place]
		              .at("AccountList")[Choice - 1]
		              .at("Lock");

		UserDataJSON.at("UserList")[user_place]
		  .at("AccountList")[Choice - 1]
		  .at("Lock") = !lock;
	}

	UpdateUserDataJSON();
	return;
}