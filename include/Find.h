#ifndef LIBPRO_FIND_H
#define LIBPRO_FIND_H

#include "CommonLib.h"

int FindUserByName(std::string&);
int FindUserBorrow(std::string&, std::string&, BorrowBookSubmit&); //not done

unsigned int FindBookIndex(std::string&);

#endif