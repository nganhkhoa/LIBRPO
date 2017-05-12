#include "..\..\include\ReadData.h"

using namespace std;

void ShowRoleData(vector<User>& UserData, UserAccount recordNum) {
		//show role just for in vector struct
	for (int Role_num = 0; 
		Role_num < UserData[recordNum.User_num].AccountList[recordNum.Account_num].RoleId.size(); 
		Role_num++) {

			int role = UserData[recordNum.User_num].AccountList[recordNum.Account_num].RoleId[Role_num] - 1;
			//number save in file from 1 to 3,
			//computer count from 0 to 2
			cout << LibraryRole[role].RoleName << ";\t";
	}
}

void ShowAccountData(vector<User>& UserData, int& User_num, bool debug) {
		//show availabel account
	for (int Account_num = 0; Account_num < UserData[User_num].AccountList.size(); Account_num++) {
		cout 	<< left << setw(5) << Account_num + 1 << "\t";
		cout 	<< UserData[User_num].AccountList[Account_num].AccId << "\t";

		if (debug) {//don't show pass and active if not debug
			cout	<< UserData[User_num].AccountList[Account_num].Password << "\t";
			cout	<< boolalpha << UserData[User_num].AccountList[Account_num].Active << "\t";
		}
		UserAccount recordNum = {User_num, Account_num};
		ShowRoleData(UserData, recordNum);
		cout 	<< endl;
	}
}


void ShowUserData(vector<User>& UserData, int& User_num) {
		//show user name
	cout << UserData[User_num].uid << "\t" << UserData[User_num].Username << "\n";
}


void ShowData(vector<User>& UserData) {
		//read above first please
	for (int User_num = 0; User_num < UserData.size(); User_num++) {
		ShowUserData(UserData, User_num);
		cout << "The user account list\n";
		ShowAccountData(UserData, User_num, true);
		cout << endl << endl;
	}
}