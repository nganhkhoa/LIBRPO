#include "CommonLib.h"
#include "History.h"

bool WriteAccountRoleMap(std::vector<User>&);
bool WriteAccount(std::vector<User>&);
bool WriteUser(std::vector<User>&);

bool UpdatePassword(std::vector<User>&, LoggedInUser&, std::string&);
bool ComparePassword(std::vector<User>&, LoggedInUser&, std::string&);
bool ChangePassword(std::vector<User>&, LoggedInUser&);

int SettingMenu();
void Setting(std::vector<User>&, LoggedInUser&);