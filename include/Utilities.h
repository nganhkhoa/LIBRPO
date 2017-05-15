#ifndef LIBPRO_UTILITIES_H
#define LIBPRO_UTILITIES_H

#include "CommonLib.h"

int ChooseUtilities(LoggedInUser);
void Utilities(LoggedInUser);

//Reader
int ReaderChoice();
void Reader(LoggedInUser);
bool CreateRequestBoorowBook(LoggedInUser, std::string);
void BorrowBook(LoggedInUser);

//Accountant


//Admin


//Money

#endif