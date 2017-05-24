#include <History.h>

using namespace std;

void LoginHistory() {
	// loggin user in
	ofstream logfile(FILELog, ios::out | ios::app);

	time_t now        = time(0);
	char* currenttime = ctime(&now);

	logfile << 1 << " "
	        << "User_num: " << setw(5) << CurrentUser.User_num << setw(16)
	        << " Account_num: " << setw(5) << CurrentUser.Account_num
	        << setw(10) << " Login: " << setw(30) << right << currenttime;

	logfile.close();
}


void LogoutHistory() {
	// open file and append to it
	// if you push exit button
	// if you logout
	// but if you press the red x in the corner?????
	ofstream logfile(FILELog, ios::out | ios::app);

	time_t now        = time(0);
	char* currenttime = ctime(&now);

	logfile << 0 << " "
	        << "User_num: " << setw(5) << CurrentUser.User_num << setw(16)
	        << " Account_num: " << setw(5) << CurrentUser.Account_num
	        << setw(10) << " Login: " << setw(30) << right << currenttime;

	CurrentUser = {"", -1, -1, false, {}};
	logfile.close();
}