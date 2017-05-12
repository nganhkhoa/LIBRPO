#include <ReadBook.h>

using namespace std;

bool ReadGenre(vector<Book>& BookData, bool debug) {
		//read the same rule as in author
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
		int Book_num;
		
		stringstream scin(str);

		while (true){ //get the genre
			scin >> TempString;
			if (TempString == "|") break;
			Genre += " ";
			Genre +=  TempString;
		}

		Genre = TrimString(Genre);

		while (!scin.eof()) {
			scin >> TempString;
			Book_num = FindBook(BookData, TempString, debug);
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