#ifndef FINDBOOK_H
#define FINDBOOK_H

    const int SEARCH_MAX=10;

void ReadWord(std::string* search, int& searchSize);
bool CompareWord(std::string& attribute, const std::string* search, const int& searchSize);
bool ReadBookFromJson(const std::string* search, const int& searchSize, std::vector<std::string> result);

#endif //FINDBOOK_H