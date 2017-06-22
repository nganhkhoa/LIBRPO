#ifndef SETTING
#define SETTING

#include <CommonLib.h>
#include <History/History.h>

bool WriteAccountRoleMap();
bool WriteAccount();
bool WriteUser();

bool UpdatePassword(std::string&);
bool ComparePassword(std::string&);
bool ChangePassword();

int SettingMenu();
void Setting();

void UnLockAllAccount(unsigned int&);
void LockAllAccount(unsigned int&);
void LockAllAccount();


#endif