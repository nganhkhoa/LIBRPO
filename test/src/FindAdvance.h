#ifndef FINDADVANCE_H
#define FINDADVANCE_H

    const int TITLE_MAX=10;
    const int CONTENT_MAX=200;
    const int SEARCH_MAX=10;

    typedef struct
    {
        std::string Title[TITLE_MAX];
        std::string FindWord[CONTENT_MAX];
        std::string ISBN; //code for book
    }ContentIndex;

    typedef struct
    {
        std::vector<ContentIndex> ResourceContent;
        std::vector<int> BookPosition;
    }BookManage;


bool ReadBookFromText(BookManage& LIBPROBook);
void ReadWordsToFind(std::string* search);
void CompareWords(std::string search[], BookManage& LIBPROBook, std::vector<std::string> result);

#endif