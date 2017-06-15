#ifndef LIBPRO_USERLOGIN_H
#define LIBPRO_USERLOGIN_H

#include <CommonLib.h>
/*
bool UserLoginPrompt(int&);

void ShowRoleList(UserAccount&);
void ShowAccountList(int&);

int AccountLoginPrompt(int&);
bool RightPassword(UserAccount&, int&);
void CreateLoggedInUser(UserAccount&);
bool LoggedIn();

void LockAccount(UserAccount&);
bool ReadLock();
bool CheckLock(std::string&);
//*/

int ValidateUserLogin(std::string&, std::string&);
void CreateLoginUser(unsigned int&);
bool UserLoginPrompt(bool&);
bool Login();
#endif