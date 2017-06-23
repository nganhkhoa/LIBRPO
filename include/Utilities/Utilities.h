#ifndef LIBPRO_UTILITIES_H
#define LIBPRO_UTILITIES_H

#include <CommonLib.h>
#include "Reader.h"
#include "Librarian.h"
#include "Admin.h"
#include "Money.h"

int ChooseUtilities();
void Utilities();

nlohmann::json readSubmitBorrow();
bool updateSubmitBorrow(nlohmann::json&);

nlohmann::json readBorrowLog();
void updateBorrowLog(unsigned int&, bool);
void updateBorrowLog(nlohmann::json&);
#endif