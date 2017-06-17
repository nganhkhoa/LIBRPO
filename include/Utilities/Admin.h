#ifndef ADMIN_H
#define ADMIN_H

#include <Utilities/Utilities.h>
// Admin
int AdminChoice();
void Admin();

typedef struct _verify {
	unsigned int add    = 0;
	unsigned int reject = 0;
} verify;

/**
 * Browse signup
 */
std::vector<unsigned int> SaveSignupRecord(std::vector<unsigned int>&);
nlohmann::json UpdateSignUpData(std::vector<unsigned int>&);
unsigned int ValidateUser();
void ShowSignUpData(nlohmann::json&);
verify VerifyNewUser();
// this one
void AddUser();

#endif