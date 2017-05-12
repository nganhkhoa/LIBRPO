#include "..\..\include\History.h"

using namespace std;

void LoginHistory(LoggedInUser CurrentUser) {
		//loggin user in
	ofstream logfile(FILELog, ios::out | ios::app);

	time_t now = time(0);
	char* currenttime = ctime(&now);

	logfile << 1 << " "
			<< "User_num: " 	<< CurrentUser.User_num 
			<< " Account_num: " << CurrentUser.Account_num
			<< " Login: " 		<< currenttime;
	
	logfile.close();
}


void LogoutHistory(LoggedInUser CurrentUser) {
		//open file and append to it
		//if you push exit button
		//if you logout
		//but if you press the red x in the corner?????
	ofstream logfile(FILELog, ios::out | ios::app);

	time_t now = time(0);
	char* currenttime = ctime(&now);

	logfile << 0 << " "
			<< "User_num: " 	<< CurrentUser.User_num 
			<< " Account_num: " << CurrentUser.Account_num
			<< " Logout: " 		<< currenttime;
	
	logfile.close();
}