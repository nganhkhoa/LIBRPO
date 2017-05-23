#include <ReadBook.h>

using namespace std;

bool ReadBook(vector<Book>& BookData) {
	system("cls");

	if (!ReadBookData(BookData)) {
		// read book ISBN, name, publisher, date, quantity
		cout << "Error in loading book data" << endl;
		system("pause");
		return false;
	}

	if (!ReadAuthor(BookData)) {
		// read file author
		cout << "Error in loading author" << endl;
		system("pause");
		return false;
	}

	if (!ReadGenre(BookData)) {
		// read file genre
		cout << "Error in loading genre" << endl;
		system("pause");
		return false;
	}

	if (debug) ShowBook(BookData);
	// only show if debug mode is on

	return true;
}