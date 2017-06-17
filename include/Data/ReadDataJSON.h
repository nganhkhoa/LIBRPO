#ifndef LIBPRO_READDATA_JSON_H
#define LIBPRO_READDATA_JSON_H

#include <CommonLib.h>

bool ReadUserDataJSON();
bool UpdateUserDataJSON();
nlohmann::json readSignUp();
bool updateSignUp(nlohmann::json&);
nlohmann::json readRejected();
bool updateRejected(nlohmann::json&);

#endif