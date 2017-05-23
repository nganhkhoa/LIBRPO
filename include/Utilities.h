#ifndef LIBPRO_UTILITIES_H
#define LIBPRO_UTILITIES_H

#include "CommonLib.h"

int ChooseUtilities();
void Utilities(std::vector<Book>&);

// Reader
int ReaderChoice();
void Reader();

bool CreateRequestBoorowBook(std::string&);
void BorrowFromCart(std::vector<Book>&);
// this one
void BorrowBook();

// Accountant
int AccountantChoice();
void Accountant(std::vector<Book>&);

bool GetBorrowData(std::vector<BorrowBookSubmit>&);
bool UpdateBorrowData(std::vector<BorrowBookSubmit>&);
bool CreateBorrowRecord(BorrowBookSubmit);
int ValidateBorrowBook(std::vector<Book>&, BorrowBookSubmit);
// this one
void BrowseBorrowBook(std::vector<Book>&);


// Admin


// Money

#endif