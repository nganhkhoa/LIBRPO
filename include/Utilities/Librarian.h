#ifndef Librarian_H
#define Librarian_H

#include <CommonLib.h>
// Librarian
int LibrarianChoice();
void Librarian();

unsigned int FindCheckedPlace(unsigned int&);
void RejectSubmit(nlohmann::json&, unsigned int&);
void AcceptSubmit(nlohmann::json&, unsigned int&);

// browse borrow book
std::vector<unsigned int> GetSubmitIDPendingReceived();
bool AutoReject(std::string&, std::string&);


bool CheckedSubmition(nlohmann::json&, unsigned int&);
void ShowSubmitInfo(unsigned int&, unsigned int&);
void ValidateSubmition();
// this one
void BrowseBorrowBook();


// give book to user
void AddBorrowBook(int&);
void CreateUserBorrow(std::string&, int&);

void ReceivedBook(unsigned int&);
unsigned int GetPendingPlace(int&);
int ChooseSubmitID(std::vector<unsigned int>&);
void RemoveDontCare(std::vector<unsigned int>&);
std::vector<unsigned int> FindUserSubmit(std::string&);
std::string FindUserGiveBook();
// this one
void GiveBook();


// Add new book
std::vector<std::string> ExtractStatement();
nlohmann::json CreateNewBook(NewBook&);
void AddNewBook(std::string&);
void AddExistBook(std::string&);
bool book_exits(std::string&);
// this one
void ChoiceAddBook();


#endif