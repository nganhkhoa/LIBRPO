#include <ReadBook.h>

using namespace std;

bool ReadBook() {
	system("cls");

	if (!ReadBookData()) {
		// read book ISBN, name, publisher, date, quantity
		cout << "Error in loading book data" << endl;
		system("pause");
		return false;
	}

	if (!ReadAuthor()) {
		// read file author
		cout << "Error in loading author" << endl;
		system("pause");
		return false;
	}

	if (!ReadGenre()) {
		// read file genre
		cout << "Error in loading genre" << endl;
		system("pause");
		return false;
	}

	if (debug) ShowBook();
	// only show if debug mode is on

	return true;
}