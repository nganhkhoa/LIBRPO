#ifndef LIBPRO_UTILITIES_H
#define LIBPRO_UTILITIES_H

#include "CommonLib.h"

int ChooseUtilities(LoggedInUser);
void Utilities(LoggedInUser);

//Reader
int ReaderChoice();
void Reader(LoggedInUser);
bool CreateRequestBoorowBook(LoggedInUser, std::string);
void BorrowFromCart(LoggedInUser, std::vector<Book> &);
void BorrowBook(LoggedInUser);

//Accountant
int AccountantChoice();
void Accountant(LoggedInUser);

//Admin


//Money

#endif