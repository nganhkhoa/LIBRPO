#ifndef LIBPRO_READBOOK_H
#define LIBPRO_READBOOK_H

#include "CommonLib.h"

bool ReadBookData(std::vector<Book>&, bool);
bool ReadAuthor(std::vector<Book>&, bool);
bool ReadGenre(std::vector<Book>&, bool);

int FindBook(std::vector<Book>&, std::string&, bool);

bool ReadBook(std::vector<Book>&, bool);

// Show Book

void ShowBook(std::vector<Book>&);
void ShowBookData(std::vector<Book>&, int&);
void ShowBookAuthor(std::vector<Book>&, int&);
void ShowBookGenre(std::vector<Book>&, int&);


#endif