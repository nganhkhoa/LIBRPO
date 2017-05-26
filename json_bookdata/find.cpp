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
    std::vector<std::string> FindBookResult=SearchBook();

    system("pause");
    return 0;
}