#ifndef LIBPRO_BROWSE_H
#define LIBPRO_BROWSE_H

#include <CommonLib.h>

bool ChooseBack(int&);
void ShowBookContent(std::string&);
void ChooseBookInformation(nlohmann::json&, int&);
void ChooseBook(nlohmann::json&, int&);


void ShowAllBook(nlohmann::json&);
int ShowBookResult(nlohmann::json&);
int BrowseOption();
void Browse();

void AddtoCart(nlohmann::json&, int&);
#endif