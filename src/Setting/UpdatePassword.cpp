#include <Setting.h>

using namespace std;

bool WriteUser(vector<User>& UserData) {
	ofstream userfile(FILEUser);

	if (!userfile.is_open()) {
		cout << "Cannot open userfile" << endl;
		if (debug) system("pause");
		return false;
	}

	for (int index = 0; index < UserData.size(); index++) {
		userfile << UserData[index].uid << "\t" << UserData[index].Username
		         << endl;
	}
	return true;
}


bool WriteAccount(vector<User>& UserData) {
	ofstream accountfile(FILEAccount);

	if (!accountfile.is_open()) {
		cout << "Cannot open accountfile" << endl;
		if (debug) system("pause");
		return false;
	}

	for (int index = 0; index < UserData.size(); index++) {
		for (int account = 0; account < UserData[index].AccountList.size();
		     account++) {
			accountfile << UserData[index].uid << "\t"
			            << UserData[index].AccountList[account].AccId << "\t"
			            << UserData[index].AccountList[account].Password << "\t"
			            << boolalpha
			            << UserData[index].AccountList[account].Active << endl;
		}
	}
	return true;
}


bool WriteAccountRoleMap(vector<User>& UserData) {
	ofstream accountrolemapfile(FILEAccountRoleMap);

	if (!accountrolemapfile.is_open()) {
		cout << "Cannot open accountrolemapfile" << endl;
		if (debug) system("pause");
		return false;
	}

	for (int index = 0; index < UserData.size(); index++) {
		for (int account = 0; account < UserData[index].AccountList.size();
		     account++) {
			for (int role = 0;
			     role < UserData[index].AccountList[account].RoleId.size();
			     role++) {
				accountrolemapfile
				  << UserData[index].AccountList[account].AccId << "\t"
				  << UserData[index].AccountList[account].RoleId[role] << endl;
			}
		}
	}
	return true;
}


bool UpdatePassword(
  vector<User>& UserData,
  LoggedInUser& CurrentUser,
  string& NewPassword) {

	// cypher here

	UserData[CurrentUser.User_num]
	  .AccountList[CurrentUser.Account_num]
	  .Password = NewPassword;

	if (!WriteUser(UserData)) {
		cout << "Failed to write in user file" << endl;
		if (debug) system("pause");
		return false;
	}

	if (!WriteAccount(UserData)) {
		cout << "Failed to write in account file" << endl;
		if (debug) system("pause");
		return false;
	}

	if (!WriteAccountRoleMap(UserData)) {
		cout << "Failed to write in account role map file" << endl;
		if (debug) system("pause");
		return false;
	}

	return true;
}