#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cstdlib>

#include"json.hpp"
#include"findbook.h"

using json=nlohmann::json;

int main(int argc, char** argv)
{
    //initialising
    std::string search[SEARCH_MAX];
    std::vector<std::string> result;

    int searchSize;
    //find book
    ReadWord(search, searchSize);

    ReadBookFromJson(search, searchSize, result);

    system("pause");
    return 0;
}