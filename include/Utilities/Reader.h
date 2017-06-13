#ifndef READER_H
#define READER_h

#include <Utilities/Utilities.h>
// Reader
int ReaderChoice();
void Reader();

////////////////////////////////////////////////////////
void addnewSubmit(nlohmann::json&, std::string&);
bool CreateRequestBoorowBook(std::string&);
void BorrowFromCart();
// this one
void BorrowBook();

/////////////////////////////////////////////////////////
void BookDataReturn(int&);
void UserDataReturn(std::string&, int&);

void ReturnBookSubmit(int&);
std::vector<unsigned int> GetSubmitID(unsigned int&);
std::vector<std::string> GetSubmitISBN(unsigned int&);
int ChooseReturnBook(std::string&);
// this one
void ReturnBook();
#endif