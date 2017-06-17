#ifndef LOGGEDINUSER_H
#define LOGGEDINUSER_H

#include <string>

typedef struct _LoggedInUser {
	std::string UserID = "";

	int User_num    = -1;
	int Account_num = -1;

	std::string AccountName = "";
	std::string Username    = "";

	bool Active             = false;
	std::vector<int> RoleId = {};
} LoggedInUser;

#endif