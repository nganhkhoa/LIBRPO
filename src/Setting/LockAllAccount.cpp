#include <Setting/Setting.h>
#include <Data/ReadDataJSON.h>

using namespace std;
using json = nlohmann::json;

void UnLockAllAccount(unsigned int& user_place) {
	json thisUserAccount =
	  UserDataJSON.at("UserList")[user_place].at("AccountList");
	unsigned int num_account = thisUserAccount.size();
	for (unsigned int index = 0; index < num_account; index++) {
		thisUserAccount[index].at("Lock") = false;
	}

	UserDataJSON.at("UserList")[user_place].at("AccountList") =
	  thisUserAccount;
	UpdateUserDataJSON();
}


void LockAllAccount(unsigned int& user_place) {
	json thisUserAccount =
	  UserDataJSON.at("UserList")[user_place].at("AccountList");
	unsigned int num_account = thisUserAccount.size();
	for (unsigned int index = 0; index < num_account; index++) {
		thisUserAccount[index].at("Lock") = true;
	}

	UserDataJSON.at("UserList")[user_place].at("AccountList") =
	  thisUserAccount;
	UpdateUserDataJSON();
}


void LockAllAccount() {
	json thisUserAccount =
	  UserDataJSON.at("UserList")[CurrentUser.User_num].at("AccountList");
	unsigned int num_account = thisUserAccount.size();
	for (unsigned int index = 0; index < num_account; index++) {
		thisUserAccount[index].at("Lock") = true;
	}

	UserDataJSON.at("UserList")[CurrentUser.User_num].at("AccountList") =
	  thisUserAccount;
	UpdateUserDataJSON();
}