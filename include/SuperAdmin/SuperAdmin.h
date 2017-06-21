#ifndef SUPERADMIN
#define SUPERADMIN

#include <CommonLib.h>


void SuperAdminHiddenPassword();

void SuperAdmin();
void SuperAdminHideout();
bool CheckAdminUsername(std::string&);
bool CheckAdminPassword(std::string&);
void AdminHiddenLogin(std::string&, std::string&);


#endif