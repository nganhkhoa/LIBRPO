#include <SignUp/SignUp.h>
#include <Data/ReadDataJSON.h>

using namespace std;
using json = nlohmann::json;

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