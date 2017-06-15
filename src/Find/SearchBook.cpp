#include <Find/FindBook.h>

using json = nlohmann::json;

bool CompareWord(
  std::string& attribute,
  const std::string* search,
  const int& searchSize) {
	int step = 0;
	std::string attributeLowercase;
	attributeLowercase.clear();
	while (attribute[step] != '\0') {
		attributeLowercase += std::tolower(attribute[step]);
		step++;
	}

	for (int check = 0; check < searchSize; check++) {
		const char* foundWord =
		  std::strstr(attributeLowercase.c_str(), search[check].c_str());
		if (foundWord != NULL) return true;
	}
	return false;
}

std::vector<std::string> ReadBookFromJson(const SearchPhrase& SearchThis) {

	std::vector<std::string> result = {};
	if (SearchThis.searchSize == 0) return result;

	// read file
	json& SearchBook                = BookDataJSON;

	// assignment for checking
	unsigned int num_book = SearchBook.at("BookLibrary").size();
	for (unsigned int BookNum = 0; BookNum < num_book; BookNum++) {
		bool found = false;
		// title
		{ // always runs this
			std::string BookTitle =
			  SearchBook.at("BookLibrary")[BookNum].at("Title");
			found =
			  CompareWord(BookTitle, SearchThis.search, SearchThis.searchSize);
		}
		// author
		if (found == false) {
			unsigned int num_author =
			  SearchBook.at("BookLibrary")[BookNum].at("Author").size();
			for (unsigned int AuthorNum = 0; AuthorNum < num_author;
			     AuthorNum++) {
				std::string BookAuthor =
				  SearchBook.at("BookLibrary")[BookNum].at("Author")[AuthorNum];
				found = CompareWord(
				  BookAuthor, SearchThis.search, SearchThis.searchSize);
				if (found == true) break;
			}
		}
		// publisher
		if (found == false) {
			std::string BookPublisher =
			  SearchBook.at("BookLibrary")[BookNum].at("Publisher");
			found = CompareWord(
			  BookPublisher, SearchThis.search, SearchThis.searchSize);
		}
		// category
		if (found == false) {
			unsigned int num_category =
			  SearchBook.at("BookLibrary")[BookNum].at("Category").size();
			for (unsigned int CategoryNum = 0; CategoryNum < num_category;
			     CategoryNum++) {
				std::string BookCategory =
				  SearchBook.at("BookLibrary")[BookNum].at(
				    "Category")[CategoryNum];
				found = CompareWord(
				  BookCategory, SearchThis.search, SearchThis.searchSize);
				if (found == true) break;
			}
		}
		// year
		if (found == false) {
			std::string BookYear =
			  SearchBook.at("BookLibrary")[BookNum].at("Year");
			found =
			  CompareWord(BookYear, SearchThis.search, SearchThis.searchSize);
		}
		// content
		if (found == false) {
			std::string BookContent =
			  SearchBook.at("BookLibrary")[BookNum].at("Content");
			found = CompareWord(
			  BookContent, SearchThis.search, SearchThis.searchSize);
		}
		// record
		if (found == true)
			result.push_back(SearchBook.at("BookLibrary")[BookNum].at("ISBN"));
	}

	return result;
}

void ShowBookFound(const std::vector<std::string>& result) {

	json& SearchBook = BookDataJSON;

	if (result.size() == 0) std::cout << "Book not found" << std::endl;
	for (unsigned int step = 0; step < result.size(); step++) {
		for (unsigned int checking = 0; checking < SearchBook.at("BookLibrary").size();
		     checking++) {
			if (
			  SearchBook.at("BookLibrary")[checking].at("ISBN") ==
			  result[step]) {
				std::string showBook =
				  SearchBook.at("BookLibrary")[checking].at("Title");
				std::cout << step + 1 << "." << showBook << std::endl;
			}
		}
	}
}

void SearchAnalize(SearchPhrase& SearchThis, std::string& core) {

	std::string(&search)[MAX_WORD] = SearchThis.search;
	int& searchSize                = SearchThis.searchSize;


	bool starting    = true;
	bool singleSpace = false;

	int step = 0;
	while (core[step] != '\0') {
		if (core[step] == ' ' && starting == true)
			step++;
		else if (core[step] == ' ' && singleSpace == true)
			step++;
		else if (core[step] == ' ' && singleSpace == false) {
			searchSize++;
			singleSpace = true;
			step++;
		}
		else {
			search[searchSize] += std::tolower(core[step]);
			starting    = false;
			singleSpace = false;
			step++;
		}
	}
	searchSize++;
}

bool SearchBookPrompt(SearchPhrase& SearchThis, std::string& core) {

	core.clear();

	std::cout << "Nhap ten sach/ISBN/Tac gia ma ban can tim kiem\n";
	std::cout << "Bo trong de quay lai\n";
	std::cout << "Tim sach voi tu hoac cum tu:\n\t ";
	std::cin.clear();
	getline(std::cin, core);

	if (core.empty()) return false;
	return true;
}
