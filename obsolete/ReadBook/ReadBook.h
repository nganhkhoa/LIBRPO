#ifndef LIBPRO_READBOOK_H
#define LIBPRO_READBOOK_H

#include <CommonLib.h>

bool ReadBookData();
bool ReadAuthor();
bool ReadGenre();


bool ReadBook();

// Show Book

void ShowBook();
void ShowBookData(int&);
void ShowBookAuthor(int&);
void ShowBookGenre(int&);


#endif