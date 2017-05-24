#ifndef LIBPRO_FIND_H
#define LIBPRO_FIND_H

#include "CommonLib.h"

int FindUserByName(std::string&);
int FindUser(std::string&);
UserAccount FindAccount(std::string&);
int FindBook(std::vector<Book>&, std::string&);
int FindUserBorrow(std::string&, std::string&, BorrowBookSubmit&); //not done

#endif