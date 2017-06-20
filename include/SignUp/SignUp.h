#ifndef SINGUP_H
#define SIGNUP_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

#include <CommonLib.h>
#include <Data/modify.h>

bool AccountTypeExist(NewUser&, unsigned int);
void DefaultAccount(NewUser&);
unsigned int ChooseAccountType();
void AccountType();
void AccountCreation();
void AccountCreation(NewUser&);

std::string RandomPassword();
std::string GenerateUserID();


void AccountRoleMapAdjustment(NewUser&);
bool SignUpUser(NewUser&);
bool ValidateNew(NewUser&);
void ShowInfoAndBilling(NewUser&);
void SignUp();    // this is a prompt


#endif