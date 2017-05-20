#ifndef LIBPRO_READDATA_H
#define LIBPRO_READDATA_H

#include "CommonLib.h"

bool 		ReadUser(std::vector<User>&);
int 		FindUser(std::vector<User>&, std::string&);
bool 		ReadAccount(std::vector<User>&);

UserAccount	FindAccount(std::vector<User>&, std::string&);
bool 		ReadRole(std::vector<User>&);



bool 		ReadData(std::vector<User>&, bool);

//Show Data

void ShowData(std::vector<User>&);
void ShowUserData(std::vector<User>&, int&);
void ShowAccountData(std::vector<User>&, int&, bool);
void ShowRoleData(std::vector<User>&, int&, int&);

#endif