#ifndef LIBPRO_FIND_H
#define LIBPRO_FIND_H

#include "CommonLib.h"

int FindUserByName(std::vector<User>&, std::string&);
int FindUser(std::vector<User>&, std::string&);
UserAccount FindAccount(std::vector<User>&, std::string&);
int FindBook(std::vector<Book>&, std::string&, bool);
int FindUserBorrow(std::string&, std::string&, BorrowBookSubmit&); //not done

#endif