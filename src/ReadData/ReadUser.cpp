#include <ReadData.h>
#include <Find.h>
using namespace std;

bool ReadUser() {    // read user file
	ifstream userfile(FILEUser);
	if (!userfile.is_open()) return false;

	string str;
	while (getline(userfile, str)) {
		if (str.empty()) continue;
		stringstream scin(str);
		User Temp;
		scin >> Temp.uid;
		scin >> Temp.Username;
		UserData.push_back(Temp);
	}
	userfile.close();
	return true;
}

bool ReadAccount() {
	// the file account has uid,
	// use finduser to find and put in vector
	ifstream accountfile(FILEAccount);
	if (!accountfile.is_open()) return false;

	string str;
	while (getline(accountfile, str)) {
		if (str.empty()) continue;
		stringstream scin(str);
		Account Temp;
		scin >> Temp.uid;
		int user_no = FindUser(Temp.uid);
		// if there is no user found?
		// I think the file should always have enough user

		scin >> Temp.AccId;
		scin >> Temp.Password;
		scin >> Temp.Active;

		UserData[user_no].AccountList.push_back(Temp);
	}
	accountfile.close();
	return true;
}