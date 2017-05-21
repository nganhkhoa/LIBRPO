#ifndef LIBPRO_USERLOGIN_H
#define LIBPRO_USERLOGIN_H

#include "CommonLib.h"

int FindUserByName(std::vector<User>&, std::string&);
bool UserLoginPrompt(std::vector<User>&, int&);

void ShowRoleList(std::vector<User>&, UserAccount&);
void ShowAccountList(std::vector<User>&, int&);

int AccountLoginPrompt(std::vector<User>&, int&);
bool RightPassword(std::vector<User>&, UserAccount&, int&);
LoggedInUser CreateLoggedInUser(std::vector<User>&, UserAccount&);
LoggedInUser Login(std::vector<User>&);

void LockAccount(std::string&);
bool ReadLock();
bool CheckLock(std::string&);

#endif