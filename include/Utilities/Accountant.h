#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H

#include <Utilities/Utilities.h>
// Accountant
int AccountantChoice();
void Accountant();


void RejectSubmit(nlohmann::json&, unsigned int&);
void AcceptSubmit(nlohmann::json&, unsigned int&);

// browse borrow book
bool CheckedSubmition(nlohmann::json&, unsigned int&);
void ShowSubmitInfo(unsigned int&, unsigned int&);
void ValidateSubmition();
void BrowseBorrowBook();
// this one
void BrowseBorrowBook();


// give book to user
void ReceivedBook(unsigned int&);
unsigned int GetPendingPlace(int&);
int ChooseSubmitID(std::vector<unsigned int>&);
void RemoveDontCare(std::vector<unsigned int>&);
std::vector<unsigned int> FindUserSubmit(std::string&);
std::string FindUserGiveBook();
// this one
void GiveBook();

#endif