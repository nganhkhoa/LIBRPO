#ifndef NEWUSER_H
#define NEWUSER_H

#include <string>
#include <vector>

typedef struct _NewAccount {
	std::string AccountName;
	std::vector<unsigned int> AccountRoleMap;
} NewAccount;

typedef struct _NewUser {
	std::string Username;

	std::string UserLastName;
	std::string UserFirstName;
	std::string DateOfBirth; // change to Date
	std::string Gender;
	
	std::string Nationality;
	std::string IDNumber;
	std::string IDValidDate; // change to Date
	std::string Ethnic;

	std::string PhoneNumber;
	std::string UserAddress;
	std::string Occupation;
	
	std::string Institute;
	std::string InstituteAddress;

	NewAccount Account;
} NewUser;

#endif