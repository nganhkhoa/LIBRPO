#ifndef FINDBOOK_H
#define FINDBOOK_H

#include "CommonLib.h"

void ReadWord(std::string* search, int& searchSize);
bool CompareWord(std::string& attribute, const std::string* search, const int& searchSize);
bool LoadBookResult(const std::string* search, const int& searchSize, std::vector<std::string> result);

#endif //FINDBOOK_H