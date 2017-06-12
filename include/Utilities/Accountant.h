#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H

#include <Utilities/Utilities.h>
// Accountant
int AccountantChoice();
void Accountant();


void updateBorrowLog(unsigned int&, bool);
void RejectSubmit(nlohmann::json&, unsigned int&);
void AcceptSubmit(nlohmann::json&, unsigned int&);

bool CheckedSubmition(nlohmann::json&, unsigned int&);
void ShowSubmitInfo(unsigned int&, unsigned int&);
void ValidateSubmition();
void BrowseBorrowBook();
// this one
void BrowseBorrowBook();

#endif