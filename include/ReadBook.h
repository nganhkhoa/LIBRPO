#ifndef LIBPRO_READBOOK_H
#define LIBPRO_READBOOK_H

#include "CommonLib.h"

bool ReadBookData(std::vector<Book>&);
bool ReadAuthor(std::vector<Book>&);
bool ReadGenre(std::vector<Book>&);


bool ReadBook(std::vector<Book>&);

// Show Book

void ShowBook(std::vector<Book>&);
void ShowBookData(std::vector<Book>&, int&);
void ShowBookAuthor(std::vector<Book>&, int&);
void ShowBookGenre(std::vector<Book>&, int&);


#endif