#ifndef NEWBOOK_H
#define NEWBOOK_H

#include <string>

typedef struct _NewBook {
	std::string ISBN                  = "";
	std::string Title                 = "";
	std::string Publisher             = "";
	std::string Year                  = "";
	std::string Content               = "";
	std::vector<std::string> Author   = {};
	std::vector<std::string> Category = {};
	unsigned int BookNumber           = 1;
} NewBook;

#endif