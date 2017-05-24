#ifndef LIBPRO_UTILITIES_H
#define LIBPRO_UTILITIES_H

#include "CommonLib.h"

int ChooseUtilities();
void Utilities();

// Reader
int ReaderChoice();
void Reader();

bool CreateRequestBoorowBook(std::string&);
void BorrowFromCart();
// this one
void BorrowBook();

// Accountant
int AccountantChoice();
void Accountant();

bool GetBorrowData(std::vector<BorrowBookSubmit>&);
bool UpdateBorrowData(std::vector<BorrowBookSubmit>&);
bool CreateBorrowRecord(BorrowBookSubmit);
int ValidateBorrowBook(BorrowBookSubmit);
// this one
void BrowseBorrowBook();


// Admin


// Money

#endif