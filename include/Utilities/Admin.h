#ifndef ADMIN_H
#define ADMIN_H

#include <CommonLib.h>
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

/**
 * Delete user
 */
nlohmann::json RemoveUser(unsigned int&);
void DeleteUserplace(unsigned int&);
// this one
void DeleteUser();


// password reset
void PwdReset();

/**
 * Lock or unlock user
 */
unsigned int LockPromptChoose(unsigned int&);
void LockPrompt(unsigned int&);
// this one
void UserLock();


/**
 * New ADMIN Group
 */
void NewADMINgroup(unsigned int);

#endif