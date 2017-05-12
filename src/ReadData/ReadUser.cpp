#include <ReadData.h>

using namespace std;

bool ReadUser(vector<User> &UserData) {//read user file
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

int FindUser(vector<User> &UserData, string uid) {//we have the uid only, find by uid
	for (int i = 0; i < UserData.size(); i++) {
		if (UserData[i].uid == uid) return i;
	}
	return UserData.size();
}

bool ReadAccount(vector<User> &UserData) {
		//the file account has uid, 
		//use finduser to find and put in vector
	ifstream accountfile(FILEAccount);
	if (!accountfile.is_open()) return false;

	string str;
	while (getline(accountfile, str)) {
		if (str.empty()) continue;
		stringstream scin(str);
		Account Temp;
		scin >> Temp.uid;
		int user_no = FindUser(UserData, Temp.uid);
		//if there is no user found?
		//I think the file should always have enough user

		scin >> Temp.AccId;
		scin >> Temp.Password;
		scin >> Temp.Active;

		UserData[user_no].AccountList.push_back(Temp);
	}
	accountfile.close();
	return true;
}