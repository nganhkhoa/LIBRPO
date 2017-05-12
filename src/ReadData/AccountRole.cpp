#include <ReadData.h>

using namespace std;

UserAccount FindAccount(vector<User>& UserData, string AccId) {
		//we have the account name only
		//find the account place in vector
	UserAccount Num;
	Num.User_num = UserData.size();
	for (int User_num = 0; User_num < UserData.size(); User_num++)
	{
		for (int Account_num = 0; Account_num < UserData[User_num].AccountList.size(); Account_num++)
		{
			if (UserData[User_num].AccountList[Account_num].AccId == AccId) {
				Num = {User_num, Account_num};
				return Num;
			}
		}
	}
	return Num;
}

bool ReadRole(vector<User>& UserData) {
		//read file
		//find account
		//read the number on file
		//put in vector
	ifstream accountrolemapFile(FILEAccountRoleMap);
	if (!accountrolemapFile.is_open()) return false;

	string str;
	while (getline(accountrolemapFile, str)) {
		if (str.empty()) continue;
		stringstream scin(str);
		string Temp;
		scin >> Temp;

		UserAccount recordNum = FindAccount(UserData, Temp);

		int number;
		scin >> number;
		
		UserData[recordNum.User_num].AccountList[recordNum.Account_num].RoleId.push_back(number);
	}
	accountrolemapFile.close();
	return true;
}