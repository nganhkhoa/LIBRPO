#ifndef LIBPRO_BROWSE_H
#define LIBPRO_BROWSE_H

#include "CommonLib.h"

bool ChooseBack(int&);
void ShowBookContent(std::string);
void ChooseBookInformation(std::vector<Book>&, int&);
void ChooseBook(LoggedInUser, std::vector<Book>&, int&);


void ShowAllBook(LoggedInUser, std::vector<Book>&);
int BrowseOption();
void Browse(LoggedInUser, std::vector<Book>&);


#endif