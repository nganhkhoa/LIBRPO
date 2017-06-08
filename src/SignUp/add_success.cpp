#include <modify.h>
#include <ReadDataJSON.h>

using namespace std;
using json = nlohmann::json;

bool add_success(NewUser& NewCreation) {
	system("cls");
	
	json& userdata = UserDataJSON;

	json new_user = json::object();
	json new_account = json::object();

	std::time_t now = time(0);
	tm* ltm         = localtime(&now);
	int year			= 1900 + ltm->tm_year;
	int month           = 1 + ltm->tm_mon;
	int day             = ltm->tm_mday;

	string Today = to_string(day) + "/" + to_string(month) + "/" + to_string(year);


	new_account["AccountName"] = NewCreation.Account.AccountName;
	
	unsigned int new_user_role = NewCreation.Account.AccountRoleMap.size();
	for (unsigned int i = 0; i < new_user_role; i++) {
		new_account["AccountRoleMap"][i] = NewCreation.Account.AccountRoleMap[i];
	}
	new_account["Lock"] = true;
	new_account["CreateDate"] = Today;


	new_user["AccountList"]= {new_account};
	new_user["Password"] = ""; // GeneratePwd();


	new_user["UserID"] = "004"; // GenerateID(); // need to generate ID
	new_user["Username"] = NewCreation.Username;
	new_user["UserFirstName"] = NewCreation.UserFirstName;
	new_user["UserLastName"] = NewCreation.UserLastName;
	new_user["DateOfBirth"] = NewCreation.DateOfBirth;
	new_user["Gender"] = NewCreation.Gender;
	new_user["Nationality"] = NewCreation.Nationality;
	new_user["Ethnic"] = NewCreation.Ethnic;
	new_user["IDNumber"] = NewCreation.IDNumber;
	new_user["IDValidDate"] = NewCreation.IDValidDate;
	new_user["UserAddress"] = NewCreation.UserAddress;
	new_user["PhoneNumber"] = NewCreation.PhoneNumber;
	new_user["Occupation"] = NewCreation.Occupation;
	new_user["Institute"] = NewCreation.Institute;
	new_user["InstituteAddress"] = NewCreation.InstituteAddress;


	userdata.at("SignUp")[userdata.at("SignUp").size()] = new_user;

	if(!UpdateUserDataJSON()) {
		cout << "Rat tiec, da xay ra loi" << endl;
		cout << "Moi ban thu lai sau" << endl;
		system("pause");
		return false;
	}

	// ShowNewUserInfo();
	//system("pause");
	return true;
}