#ifndef SINGUP_H
#define SIGNUP_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

#include <nlohmann\json.hpp>

#include <CommonLib.h>
#include <Data/modify.h>


void SignUp(); // this is a prompt
bool SignUpUser(NewUser&);
bool ValidateNew(NewUser&);


#endif