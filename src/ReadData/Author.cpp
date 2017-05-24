#include <ReadBook.h>
#include <Find.h>

using namespace std;

bool ReadAuthor() {
	// read the file
	// read author's name
	// read books in rows
	// find and add to vector
	ifstream authorfile(FILEAuthor);
	if (!authorfile.is_open()) return false;

	if (debug) {
		cout << "Opened author" << endl;
		system("pause");
	}
	string str;
	while (getline(authorfile, str)) {
		if (str.empty()) continue;

		string TempString;
		string Author;
		

		stringstream scin(str);
		while (true) {
			scin >> TempString;
			if (TempString == "|") break;
			Author += " ";
			Author += TempString;
		}
		Author = TrimString(Author);
		while (!scin.eof()) {
			scin >> TempString;
			int Book_num;
			Book_num = FindBook(TempString);
			BookData[Book_num].Authors.push_back(Author);
			TempString = "";
		}
	}


	if (debug) {
		cout << "Closed Author" << endl;
		system("pause");
		system("cls");
	}

	authorfile.close();
	return true;
}