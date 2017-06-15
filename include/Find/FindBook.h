#ifndef FINDBOOK_H
#define FINDBOOK_H

#include <CommonLib.h>

const int MAX_WORD = 10;

typedef struct _SearchPhrase {
	std::string search[MAX_WORD] = {};
	int searchSize = 0;
} SearchPhrase;

void FindBook();
int FindBookBorrow(std::string&, nlohmann::json&);

nlohmann::json ISBNtoJSON(std::vector<std::string>&);

bool CompareWord(std::string&, const std::string*, const int&);
std::vector<std::string> ReadBookFromJson(const SearchPhrase&);
void ShowBookFound(const std::vector<std::string>&);
void SearchAnalize(SearchPhrase&, std::string&);
bool SearchBookPrompt(SearchPhrase&, std::string&);

#endif //FINDBOOK_H