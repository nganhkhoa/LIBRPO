#include <Find.h>

using namespace std;

int FindUserByName(string& str) {
	// find the f@#%@^@#^ user by his name
	// because user input in the username
	// we have to find it no matter what

	// this is different from FindUser which is by uid
	// I'm so lazy to change the name
	int num_Users = UserDataJSON.at("UserList").size();
	for (int i = 0; i < num_Users; i++) {
		string Username = UserDataJSON.at("UserList")[i].at("Username");
		if (debug) cout << Username << endl;
		if (Username == str) return i;
	}
	return num_Users;
}


int FindBook(string& BookId) {
	// find book by ISBN
	if (debug) cout << "Finding for book with ID: " << BookId << endl;
	for (int index = 0; index < BookData.size(); index++) {
		if (BookData[index].BookId == BookId) {
			if (debug) cout << "Book " << BookId << " found" << endl;
			return index;
		}
	}
	return BookData.size();
}

UserAccount FindAccount(string& AccId) {
	// we have the account name only
	// find the account place in vector
	UserAccount Num;
	Num.User_num = UserData.size();
	for (int User_num = 0; User_num < UserData.size(); User_num++) {
		for (int Account_num = 0;
		     Account_num < UserData[User_num].AccountList.size();
		     Account_num++) {
			if (UserData[User_num].AccountList[Account_num].AccId == AccId) {
				Num = {User_num, Account_num};
				return Num;
			}
		}
	}
	return Num;
}

int FindUser(string& uid) {    // we have the uid only, find by uid
	for (int i = 0; i < UserData.size(); i++) {
		if (UserData[i].uid == uid) return i;
	}
	return UserData.size();
}