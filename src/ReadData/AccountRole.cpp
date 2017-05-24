#include <ReadData.h>
#include <Find.h>

using namespace std;



bool ReadRole() {
	// read file
	// find account
	// read the number on file
	// put in vector
	ifstream accountrolemapFile(FILEAccountRoleMap);
	if (!accountrolemapFile.is_open()) return false;

	string str;
	while (getline(accountrolemapFile, str)) {
		if (str.empty()) continue;
		stringstream scin(str);
		string Temp;
		scin >> Temp;

		UserAccount recordNum = FindAccount(Temp);

		int number;
		scin >> number;

		UserData[recordNum.User_num]
		  .AccountList[recordNum.Account_num]
		  .RoleId.push_back(number);
	}
	accountrolemapFile.close();
	return true;
}