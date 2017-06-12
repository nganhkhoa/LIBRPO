#ifndef READER_H
#define READER_h

#include <Utilities/Utilities.h>
// Reader
int ReaderChoice();
void Reader();

void addnewSubmit(nlohmann::json&, std::string&);
bool CreateRequestBoorowBook(std::string&);
void BorrowFromCart();
// this one
void BorrowBook();

#endif