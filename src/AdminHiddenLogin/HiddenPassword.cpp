#include <SuperAdmin/SuperAdmin.h>
#include <SignUp/SignUp.h>

using namespace std;

void SuperAdminHiddenPassword() {
	ofstream ADMIN_FILE(FILEAdmin, ios::out | ios::trunc);
	if (!ADMIN_FILE.is_open()) {
		cout << "Admin file open failed" << endl;
		pausescreen();
	}
	string pwd = RandomPassword();
	ADMIN_FILE << pwd;
	return;
}