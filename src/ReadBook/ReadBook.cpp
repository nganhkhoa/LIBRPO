#include "..\include\ReadBook.h"

using namespace std;

bool ReadBook(vector<Book>& BookData, bool debug) {
	system("cls");
	
	if (!ReadBookData(BookData, debug)) {
			//read book ISBN, name, publisher, date, quantity
		cout << "Error in loading book data" << endl;
		system("pause");
		return false;
	}

	if (!ReadAuthor(BookData, debug)) {
			//read file author
		cout << "Error in loading author" << endl;
		system("pause");
		return false;
	}

	if (!ReadGenre(BookData, debug)) {
			//read file genre
		cout << "Error in loading genre" << endl;
		system("pause");
		return false;
	}

	if (debug) ShowBook(BookData);
	//only show if debug mode is on

	return true;
}