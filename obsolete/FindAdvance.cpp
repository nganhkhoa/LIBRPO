
#include "findadvance.h"

bool ReadBookFromText(BookManage& LIBPROBook) {
	std::ifstream content("attempt.txt");
	if (!content.is_open()) {
		std::cout << "Cannot open file.Exitting...";
		return false;
	}

	// some parameters
	int step      = 0;
	int NumOfBook = 0, NumOfWord = 0, NumOfTitle = -1;
	std::string input, singleWord;

	while (!content.eof())    // while doi lai for
	// for (int step = 0; !content.eof(); step++)
	{
		int bracket      = 0;
		bool SingleSpace = false;
		std::getline(content, input);
		// std::cout<<input[20];
		int length = input.size();

		ContentIndex Contemp;
		// int NumOfWord=0, NumOfTitle=-1;
		while (step < length) {
			if (step < 13) {    // copy chuoi vo nhanh hon
				Contemp.ISBN += input[step];
				step++;
				if (step == 13) { step++; }
				continue;
			}
			if (input[step] == '|') {
				step++;
				continue;
			}
			if (input[step] == ' ' && SingleSpace == false && bracket == 0) {
				SingleSpace = true;
				// std::cout<<singleWord<<","<<step<<":"<<NumOfTitle<<"|";
				if (NumOfTitle < TITLE_MAX) {
					if (NumOfTitle > -1) Contemp.Title[NumOfTitle] = singleWord;
					NumOfTitle++;
				}

				singleWord.clear();
				step++;
				continue;
			}
			if (input[step] == ' ' && SingleSpace == false && bracket == 1) {
				SingleSpace                 = true;
				Contemp.FindWord[NumOfWord] = singleWord;
				NumOfWord++;

				singleWord.clear();
				step++;
				continue;
			}
			if (input[step] == ' ' && SingleSpace == true) {
				step++;
				continue;
			}
			if (input[step] == ',') {
				step++;
				continue;
			}
			if (input[step] == '.') {
				step++;
				continue;
			}
			if (input[step] == '?') {
				step++;
				continue;
			}
			if (input[step] == '!') {
				step++;
				continue;
			}
			if (input[step] == ':') {
				step++;
				continue;
			}
			if (input[step] == '[') {
				bracket = 1;
				step += 2;
				continue;
			}
			if (input[step] == ']') {
				Contemp.FindWord[NumOfWord] = singleWord;

				singleWord.clear();
				step++;
				continue;
			}
			if (input[step] == '\"') {
				step++;
				continue;
			}
			if (input[step] == '\\') {
				step += 2;
				continue;
			}
			else {
				singleWord += input[step];
				SingleSpace = false;
				step++;
				continue;
			}
		}
		LIBPROBook.ResourceContent.push_back(Contemp);
		LIBPROBook.BookPosition.push_back(NumOfBook);

		NumOfBook++;
		NumOfWord  = 0;
		NumOfTitle = -1;
		step       = 0;
	}
	content.close();

	// for (int check=0; check< 150; check++
	// )std::cout<<check<<LIBPROBook.ResourceContent[1].FindWord[check]<<std::endl;

	return true;
}

void ReadWordsToFind(std::string* search) {
	std::cout << "Find book: ";
	std::string core;
	int step = 0, NumOfWord = 0;
	bool starting = true;
	getline(std::cin, core);

	while (core[step] != '\0') {    // while doi lai for
		// for (int step = 0; core[step] != '\0'; step++)
		// for (int step = 0; step < core.length(); step++)
		// remove starting space
		if (core[step] == ' ' && starting == true)
			step++;
		else if (core[step] == ' ' && starting == false) {
			NumOfWord++;
			step++;
		}
		else {
			search[NumOfWord] += core[step];
			starting = false;
			step++;
		}
	}
}

void CompareWords(
  std::string search[],
  BookManage& LIBPROBook,
  std::vector<std::string> result) {    // ham gi ma dai quan the?????
	                                    // ham phai dai vua phai thoi
	                                    // ham la phai quan que
	int Position = -1, ContentPos = -1;
	int FirstWordFound = 0;
	int numberOfFound  = 1;

	for (unsigned int BookPlace = 0; BookPlace < LIBPROBook.BookPosition.size();
	     BookPlace++) {
		for (int step = 0; step < SEARCH_MAX; step++) {
			while (Position++ < TITLE_MAX - 1 && FirstWordFound == 0) {
				// title =
				// LIBPROBook.ResourceContent[BookPlace].Title[Position];
				// if (search[step] == title)
				if (
				  search[step] ==
				  LIBPROBook.ResourceContent[BookPlace].Title[Position]) {
					result.push_back(
					  LIBPROBook.ResourceContent[BookPlace].ISBN);
					FirstWordFound = 1;
					break;
				}
			}

			while (ContentPos++ < CONTENT_MAX - 1 && FirstWordFound == 0) {
				// dieu kien gi chuoi qua vay???
				// need better codework
				if (
				  search[step] ==
				  LIBPROBook.ResourceContent[BookPlace].FindWord[ContentPos]) {
					result.push_back(
					  LIBPROBook.ResourceContent[BookPlace].ISBN);
					FirstWordFound = 1;
					break;
				}
			}
		}    // end checking matching words

		Position       = -1;
		ContentPos     = -1;
		FirstWordFound = 0;
	}    // end checking all books

	int titleValue = -1;
	bool hasShown  = false;

	if (result.size() == 0) std::cout << "Book not found" << std::endl;
	for (unsigned int showBookFound = 0; showBookFound < result.size();
	     showBookFound++) {
		for (unsigned int isbn = 0; isbn < LIBPROBook.BookPosition.size(); isbn++) {
			if (
			  LIBPROBook.ResourceContent[isbn].ISBN == result[showBookFound]) {
				std::cout << numberOfFound << ". ";
				while (titleValue++ < TITLE_MAX - 1)
					std::cout
					  << LIBPROBook.ResourceContent[isbn].Title[titleValue]
					  << " ";
				hasShown = true;
			}
			if (hasShown == true) {
				std::cout << std::endl;
				hasShown = false;
			}
		}
		titleValue = -1;
		numberOfFound++;
	}
}