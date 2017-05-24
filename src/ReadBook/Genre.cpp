#include <ReadBook.h>
#include <Find.h>
using namespace std;

bool ReadGenre() {
	// read the same rule as in author
	ifstream genrefile(FILEGenre);
	if (!genrefile.is_open()) return false;

	if (debug) {
		cout << "Opened genre" << endl;
		system("pause");
	}

	string str;
	while (getline(genrefile, str)) {
		if (str.empty()) continue;

		string TempString;
		string Genre;

		stringstream scin(str);

		while (true) {    // get the genre
			scin >> TempString;
			if (TempString == "|") break;
			Genre += " ";
			Genre += TempString;
		}

		Genre = TrimString(Genre);

		while (!scin.eof()) {
			scin >> TempString;
			int Book_num;
			Book_num = FindBook(TempString);
			BookData[Book_num].Genres.push_back(Genre);
			TempString = "";
		}
	}

	if (debug) {
		cout << "Close Genre" << endl;
		system("pause");
		system("cls");
	}

	genrefile.close();
	return true;
}