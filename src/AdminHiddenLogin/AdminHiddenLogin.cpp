#include <SuperAdmin/SuperAdmin.h>
#include <Utilities/Utilities.h>

using namespace std;

void SuperAdmin() {
	return;
}

void SuperAdminHideout() {
	clearscreen();
	cout << "1.\t"
	     << "Normal Admin" << endl;
	cout << "2.\t"
	     << "Legendary Admin" << endl;
	cout << "3.\t"
	     << "Kill All (or exit maybe)" << endl;
	unsigned int Choice = 0;

	while (true) {
		cin >> Choice;
		switch (Choice) {
			case 1: Admin(); break;
			case 2: SuperAdmin(); break;
			case 3: exit(0);
			default: break;
		}
	}
}

bool CheckAdminUsername(string& username) {
	return false;
}

bool CheckAdminPassword(string& pwd) {
	return false;
}

void AdminHiddenLogin(string& username, string& pwd) {
	if (!CheckAdminUsername(username)) return;
	if (!CheckAdminPassword(pwd)) return;
	SuperAdminHideout();
}