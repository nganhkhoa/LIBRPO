/*
 * @CreateTime: Jun 18, 2017 10:05 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 18, 2017 10:05 PM
 * @Description: Chính sửa thêm vào signup.json
 */

#include <Data/modify.h>
#include <Data/ReadDataJSON.h>

using namespace std;
using json = nlohmann::json;

bool add_success(NewUser& NewCreation) {
	clearscreen();

	json Signup = readSignUp();

	json new_user    = json::object();
	json new_account = json::object();

	std::time_t now = time(0);
	tm* ltm         = localtime(&now);
	int year        = 1900 + ltm->tm_year;
	int month       = 1 + ltm->tm_mon;
	int day         = ltm->tm_mday;

	string Today =
	  to_string(day) + "/" + to_string(month) + "/" + to_string(year);


	new_account["AccountName"] = NewCreation.Account.AccountName;

	unsigned int new_user_role = NewCreation.Account.AccountRoleMap.size();
	for (unsigned int i = 0; i < new_user_role; i++) {
		new_account["AccountRoleMap"][i] =
		  NewCreation.Account.AccountRoleMap[i];
	}
	new_account["Lock"]       = true;
	new_account["CreateDate"] = Today;


	new_user["AccountList"] = {new_account};
	new_user["Password"]    = NewCreation.Password;


	new_user["UserID"]           = NewCreation.UserID;
	new_user["Username"]         = NewCreation.Username;
	new_user["UserFirstName"]    = NewCreation.UserFirstName;
	new_user["UserLastName"]     = NewCreation.UserLastName;
	new_user["DateOfBirth"]      = NewCreation.DateOfBirth;
	new_user["Gender"]           = NewCreation.Gender;
	new_user["Nationality"]      = NewCreation.Nationality;
	new_user["Ethnic"]           = NewCreation.Ethnic;
	new_user["IDNumber"]         = NewCreation.IDNumber;
	new_user["IDValidDate"]      = NewCreation.IDValidDate;
	new_user["UserAddress"]      = NewCreation.UserAddress;
	new_user["PhoneNumber"]      = NewCreation.PhoneNumber;
	new_user["Occupation"]       = NewCreation.Occupation;
	new_user["Institute"]        = NewCreation.Institute;
	new_user["InstituteAddress"] = NewCreation.InstituteAddress;
	new_user["Balance"]          = 0;


	Signup.at("SignUp")[Signup.at("SignUp").size()] = new_user;

	if (!updateSignUp(Signup)) {
		cout << "Rat tiec, da xay ra loi" << endl;
		cout << "Moi ban thu lai sau" << endl;
		pausescreen();
		return false;
	}

	// ShowNewUserInfo();
	// pausescreen();
	return true;
}