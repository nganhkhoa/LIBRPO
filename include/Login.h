#ifndef LIBPRO_USERLOGIN_H
#define LIBPRO_USERLOGIN_H

#include "CommonLib.h"

bool UserLoginPrompt(std::vector<User>&, int&);

void ShowRoleList(std::vector<User>&, UserAccount&);
void ShowAccountList(std::vector<User>&, int&);

int AccountLoginPrompt(std::vector<User>&, int&);
bool RightPassword(std::vector<User>&, UserAccount&, int&);
void CreateLoggedInUser(std::vector<User>&, UserAccount&);
bool LoggedIn(std::vector<User>&);

void LockAccount(std::string&);
bool ReadLock();
bool CheckLock(std::string&);

#endif