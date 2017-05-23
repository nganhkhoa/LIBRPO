#include "CommonLib.h"
#include "History.h"

bool WriteAccountRoleMap(std::vector<User>&);
bool WriteAccount(std::vector<User>&);
bool WriteUser(std::vector<User>&);

bool UpdatePassword(std::vector<User>&, std::string&);
bool ComparePassword(std::vector<User>&, std::string&);
bool ChangePassword(std::vector<User>&);

int SettingMenu();
void Setting(std::vector<User>&);