#ifndef FINDBOOK_H
#define FINDBOOK_H

    const int SEARCH_MAX=10;

bool CompareWord(std::string& attribute, const std::string* search, const int& searchSize);
bool ReadBookFromJson(const std::string* search, const int& searchSize, std::vector<std::string>& result);
void ShowBookFound(const std::vector<std::string>& result);
std::vector<std::string> SearchBook();

#endif //FINDBOOK_H