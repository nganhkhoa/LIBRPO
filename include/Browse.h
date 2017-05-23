#ifndef LIBPRO_BROWSE_H
#define LIBPRO_BROWSE_H

#include "CommonLib.h"

bool ChooseBack(int&);
void ShowBookContent(std::string&);
void ChooseBookInformation(std::vector<Book>&, int&);
void ChooseBook(std::vector<Book>&, int&);


void ShowAllBook(std::vector<Book>&);
int BrowseOption();
void Browse(std::vector<Book>&);


#endif