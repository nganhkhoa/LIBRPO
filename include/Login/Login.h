#ifndef LIBPRO_USERLOGIN_H
#define LIBPRO_USERLOGIN_H

#include <CommonLib.h>

int ValidateUserLogin(std::string&, std::string&);
void CreateLoginUser(unsigned int&);
bool UserLoginPrompt(bool&);
bool Login();
#endif