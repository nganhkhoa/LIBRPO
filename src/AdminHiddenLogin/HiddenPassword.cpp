#include <SuperAdmin/SuperAdmin.h>
#include <SignUp/SignUp.h>

using namespace std;

void SuperAdminHiddenUsername() {
	ofstream ADMIN_FILE(FILEAdmin, ios::out | ios::trunc);
#ifndef NDEBUG
	if (!ADMIN_FILE.is_open()) {
		cout << "Admin file open failed" << endl;
		pausescreen();
	}
#endif
	string username = RandomPassword();
	ADMIN_FILE << username << endl;
	return;
}

void SuperAdminHiddenPassword() {
	ofstream ADMIN_FILE(FILEAdmin, ios::out | ios::app);
#ifndef NDEBUG
	if (!ADMIN_FILE.is_open()) {
		cout << "Admin file open failed" << endl;
		pausescreen();
	}
#endif
	string pwd = RandomPassword();
	ADMIN_FILE << pwd;
	return;
}

void ErasedSuperAdminTrace() {
	ofstream ADMIN_FILE(FILEAdmin, ios::out | ios::trunc);
	return;
}