#include <Browse.h>
#include <FindBook.h>

using namespace std;

void FindBook() {

	string core = "";
	SearchPhrase SearchThis;

	while (!SearchBookPrompt(SearchThis, core)) {
		cout << "Ban khong muon tim kiem nua? (y/n) ";
		string Answer = "";
		getline(cin, Answer);
		if (Answer == "y") return;
		else continue;
	}
	
	SearchAnalize(SearchThis, core);
	vector<string> result = ReadBookFromJson(SearchThis);

	ShowBookFound(result);
	system("pause");

	// choose from number

	// ListBookFromISBN();

	return;
}