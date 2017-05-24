#include <ReadData.h>

using namespace std;

bool ReadData() {
	system("cls");

	if (!ReadUser()) {    // read user.txt
		cout << "Error in loading user data";
		return false;
	}

	if (!ReadAccount()) {    // read account.txt
		cout << "Error in loading account data";
		return false;
	}

	if (!ReadRole()) {    // read accountrolemap.txt
		cout << "Error in loading role data";
		return false;
	}

	if (debug) ShowData();
	// show if debug mode is on

	return true;
}