#ifndef LIBPRO_UTILITIES_H
#define LIBPRO_UTILITIES_H

#include "CommonLib.h"

int ChooseUtilities(LoggedInUser&);
void Utilities(LoggedInUser&, std::vector<Book>&);

// Reader
int ReaderChoice();
void Reader(LoggedInUser&);

bool CreateRequestBoorowBook(LoggedInUser&, std::string&);
void BorrowFromCart(LoggedInUser&, std::vector<Book>&);
// this one
void BorrowBook(LoggedInUser&);

// Accountant
int AccountantChoice();
void Accountant(LoggedInUser&, std::vector<Book>&);

bool GetBorrowData(std::vector<BorrowBookSubmit>&);
bool UpdateBorrowData(std::vector<BorrowBookSubmit>&);
bool CreateBorrowRecord(BorrowBookSubmit);
int ValidateBorrowBook(LoggedInUser&, std::vector<Book>&, BorrowBookSubmit);
// this one
void BrowseBorrowBook(LoggedInUser&, std::vector<Book>&);


// Admin


// Money

#endif