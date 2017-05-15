#include <ReadBook.h>

using namespace std;

bool ReadBookData(vector<Book>& BookData, bool debug) {
	ifstream bookfile(FILEBook);
	if (!bookfile.is_open()) return false;

	if (debug) {
	cout << "Opened book" << endl;
	system("pause");
	}

	string str;
	while (getline(bookfile, str)) {
		if (str.empty()) continue;
		string TempString = "";
		int count = 1;
		Book TempBook;

		for (int index = 0; index < str.length(); index++) {
			if (str[index] == '|') {
				TempString = TrimString(TempString);
				switch (count++) {
					case 1: TempBook.BookId 	= TempString; break;
					case 2: TempBook.BookLabel 	= TempString; break;
					case 3: TempBook.Publisher 	= TempString; break;
					case 4: TempBook.Year 		= TempString; break;
					case 5: TempBook.Quantity 	= stoi(TempString); break;
					case 6: TempBook.Borrowed 	= stoi(TempString); break;
				}
				TempString = "";
				continue;
			}
			TempString += str[index];
		}
		
		if (debug) {
			cout << "Book read:" << endl;
			cout << "Book ID: " << TempBook.BookId << endl;
			cout << "Book Label:" << TempBook.BookLabel << endl;
			cout << "Book Publisher:" << TempBook.Publisher << endl;
			cout << "Book Year:" << TempBook.Year << endl;
			cout << "Book Quantity:" << TempBook.Quantity << endl;
			cout << "Book Borrowed: " << TempBook.Borrowed << endl;
			cout << "Book num = " << BookData.size() << endl;
		}

		BookData.push_back(TempBook);
	}
	if (debug) {
		cout << "Closed book" << endl;
		system("pause");
		system("cls");
	}
	bookfile.close();
	return true;
}

int FindBook(vector<Book>& BookData, string BookId, bool debug) {
		//find book by ISBN
	if (debug) cout << "Finding for book with ID: " << BookId << endl;
	for (int index = 0; index < BookData.size(); index++) {
		if (BookData[index].BookId == BookId) {
			if (debug) cout << "Book " << BookId << " found" << endl;
			return index;
		}
	}
	return BookData.size();
}