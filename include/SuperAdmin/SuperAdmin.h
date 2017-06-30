#ifndef SUPERADMIN
#define SUPERADMIN

#include <CommonLib.h>

void SuperAdminHiddenUsername();
void SuperAdminHiddenPassword();

void SuperAdmin();
void SuperAdminHideout();
bool CheckAdminUsername(std::string&);
bool CheckAdminPassword(std::string&);
void AdminHiddenLogin(std::string&, std::string&);

void ErasedSuperAdminTrace();

#endif