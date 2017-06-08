#include <History.h>

using namespace std;

void LoginHistory() {
	// loggin user in
	ofstream logfile(FILELog, ios::out | ios::app);

	time_t now        = time(0);
	char* currenttime = ctime(&now);

	logfile << 1 << " "
	        << "UserID: " << setw(15) << CurrentUser.UserID 
		<< setw(10)
		<< " Login: " << setw(30) << right << currenttime;

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
	        << "UserID: " << setw(15) << CurrentUser.UserID
		<< setw(10)
		<< " Logout: " << setw(30) << right << currenttime;

	LoggedInUser CurrentUserReInit;
	CurrentUser = CurrentUser;
	logfile.close();
}


void LogoutAccount() {
	CurrentUser.AccountName = "";
	CurrentUser.Account_num = -1;
	CurrentUser.RoleId = {};
}