#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>

#include"json.hpp"
#include"findbook.h"

using json=nlohmann::json;

bool CompareWord(std::string& attribute, const std::string* search, const int& searchSize)
{
    int step=0;
    std::string attributeLowercase; attributeLowercase.clear();
    while(attribute[step]!='\0') {attributeLowercase+=std::tolower(attribute[step]); step++;}

    for(int check=0; check<searchSize; check++)
    {
        const char* foundWord= std::strstr(attributeLowercase.c_str(), search[check].c_str());
        if(foundWord!=NULL) return true;
    }
    return false;
}

bool ReadBookFromJson(const std::string* search, const int& searchSize, std::vector<std::string>& result)
{
    //open book file
    std::ifstream bookfile("book.json");
    if(!bookfile.is_open()){std::cout<<"Cannot search book. Exiting..."; return false;}

    //read file
    json SearchBook;
    bookfile>> SearchBook;

    //assignment for checking
    for(int BookNum=0; BookNum< SearchBook.at("BookLibrary").size(); BookNum++)
    {
        bool found=false;
        //title
        if (found==false)
        {
            std::string BookTitle= SearchBook.at("BookLibrary")[BookNum].at("Title");
            found=CompareWord(BookTitle, search, searchSize);
        }
        //author
        if (found==false)
        {
            for(int AuthorNum=0; AuthorNum<SearchBook.at("BookLibrary")[BookNum].at("Author").size(); AuthorNum++)
            {
                std::string BookAuthor= SearchBook.at("BookLibrary")[BookNum].at("Author")[AuthorNum];
                found=CompareWord(BookAuthor, search, searchSize);
                if(found==true) break;
            }
        }
        //publisher
        if (found==false)
        {
            std::string BookPublisher= SearchBook.at("BookLibrary")[BookNum].at("Publisher");
            found=CompareWord(BookPublisher, search, searchSize);
        }
        //category
        if (found==false)
        {
            for(int CategoryNum=0; CategoryNum<SearchBook.at("BookLibrary")[BookNum].at("Category").size(); CategoryNum++)
            {
                std::string BookCategory= SearchBook.at("BookLibrary")[BookNum].at("Category")[CategoryNum];
                found=CompareWord(BookCategory, search, searchSize);
                if(found==true) break;
            }
        }
        //year
        if (found==false)
        {
            std::string BookYear= SearchBook.at("BookLibrary")[BookNum].at("Year");
            found=CompareWord(BookYear, search, searchSize);
        }
        //content
        if (found==false)
        {
            std::string BookContent= SearchBook.at("BookLibrary")[BookNum].at("Content");
            found=CompareWord(BookContent, search, searchSize);
        }
        //record
        if (found==true) result.push_back(SearchBook.at("BookLibrary")[BookNum].at("ISBN"));
    }

    bookfile.close();
    return true;
}

void ShowBookFound(const std::vector<std::string>& result)
{
    std::ifstream bookfile("book.json");

    json SearchBook;
    bookfile>>SearchBook;

    if(result.size()==0) std::cout<<"Book not found"<<std::endl;
    for(int step=0; step< result.size(); step++)
    {
        for(int checking=0; checking<SearchBook.at("BookLibrary").size(); checking++)
        {
            if(SearchBook.at("BookLibrary")[checking].at("ISBN")==result[step])
            {
                std::string showBook= SearchBook.at("BookLibrary")[checking].at("Title");
                std::cout<<step+1<<"."<<showBook<<std::endl;
            }
        }
    }
    bookfile.close();
}

std::vector<std::string> SearchBook()
{
    std::string core; core.clear();
    std::string search[SEARCH_MAX];
    int step=0, searchSize=0;

    bool starting=true;
    bool singleSpace=false;
    std::cout<<"Find book: ";
    std::cin.clear();
    getline(std::cin, core);

    while(core[step]!='\0')
    {
        if(core[step]==' '&&starting==true) step++;
        else if (core[step]==' '&&singleSpace==true) step++;
        else if (core[step]==' '&&singleSpace==false)
        {
            searchSize++; singleSpace=true;
            step++;
        }
        else
        {
            search[searchSize]+=std::tolower(core[step]);
            starting=false; singleSpace=false;
            step++;
        }
    }
    searchSize++;

    std::vector<std::string> result;
    ReadBookFromJson(search, searchSize, result);
    ShowBookFound(result);
    return result;
}