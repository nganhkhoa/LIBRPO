#ifndef LIBPRO_READDATA_H
#define LIBPRO_READDATA_H

#include "CommonLib.h"

bool ReadUser(std::vector<User>&);
bool ReadAccount(std::vector<User>&);

bool ReadRole(std::vector<User>&);


bool ReadData(std::vector<User>&);

// Show Data

void ShowData(std::vector<User>&);
void ShowUserData(std::vector<User>&, int&);
void ShowAccountData(std::vector<User>&, int&);
void ShowRoleData(std::vector<User>&, int&, int&);

#endif