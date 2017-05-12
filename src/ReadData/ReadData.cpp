#include <ReadData.h>

using namespace std;

bool ReadData(vector<User>& UserData, bool debug) {
	system("cls");
	
	if (!ReadUser(UserData)) {//read user.txt
		cout << "Error in loading user data";
		return false;
	}

	if (!ReadAccount(UserData)) {//read account.txt
		cout << "Error in loading account data";
		return false;
	}

	if (!ReadRole(UserData)) {//read accountrolemap.txt
		cout << "Error in loading role data";
		return false;
	}

	if (debug) ShowData(UserData);
	//show if debug mode is on

	return true;
}