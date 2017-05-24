#ifndef LIBPRO_READDATA_H
#define LIBPRO_READDATA_H

#include "CommonLib.h"

bool ReadUser();
bool ReadAccount();

bool ReadRole();


bool ReadData();

// Show Data

void ShowData();
void ShowUserData(int&);
void ShowAccountData(int&);
void ShowRoleData(int&, int&);

#endif