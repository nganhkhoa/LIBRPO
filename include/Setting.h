#include "CommonLib.h"
#include "History.h"

bool WriteAccountRoleMap(std::vector<User>&, bool);
bool WriteAccount(std::vector<User>&, bool);
bool WriteUser(std::vector<User>&, bool);

bool UpdatePassword(std::vector<User>&, LoggedInUser, std::string, bool);
bool ComparePassword(std::vector<User>&, LoggedInUser, std::string);
bool ChangePassword(std::vector<User>&, LoggedInUser, bool);

int SettingMenu();
void Setting(std::vector<User>&, LoggedInUser&, bool);