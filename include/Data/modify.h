#ifndef MODIFY_H
#define MODIFY_H

#include <iostream>
#include <nlohmann\json.hpp>
#include <cmath>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>

#include <CommonLib.h>

bool	add_success(NewUser&);
bool 	delete_success(std::string&);

#endif