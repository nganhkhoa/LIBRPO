#ifndef SINGUP_H
#define SIGNUP_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

#include <nlohmann\json.hpp>

#include <CommonLib.h>
#include <Data/modify.h>

bool AccountTypeExist(NewUser&, unsigned int);
void DefaultAccount(NewUser&);
unsigned int ChooseAccountType();
void AccountType();
void AccountCreation();
void AccountCreation(NewUser&);

bool SignUpUser(NewUser&);
bool ValidateNew(NewUser&);
void SignUp(); // this is a prompt


#endif