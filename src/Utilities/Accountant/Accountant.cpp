#include <Utilities.h>

using namespace std;

int AccountantChoice() {
	system("cls");
	int Choice;
	cout << "1\t"
	     << "Duyet sach muon" << endl;
	cout << "2\t"
	     << "Duyet sach mua" << endl;
	cout << "3\t"
	     << "Them sach vao thu vien" << endl;
	cout << "4\t"
	     << "Chinh sua sach trong thu vien" << endl;
	// view changes to database????????????
	cout << "5\t"
	     << "Thoat" << endl;

	cout << "Moi ban chon: ";
	cin >> Choice;
	while (Choice < 0 || Choice > 5) {
		cout << "Lua chon khong co, moi ban chon lai: ";
		cin >> Choice;
	}

	return Choice;
}

void Accountant(LoggedInUser CurrentUser, vector<Book>& BookData) {

	while (true) {
		enum Choice
		{
			ChoiceBrowseBorrowSubmition = 1,
			ChoiceBrowseBuySubmition,
			ChoiceAddBook,
			ChoiceModifyBook,
			Exit
		};
		switch (AccountantChoice()) {
			case ChoiceBrowseBorrowSubmition:
				BrowseBorrowBook(CurrentUser, BookData);
				break;
			case ChoiceBrowseBuySubmition:
				// ChoiceBrowseBuySubmition();
				break;
			case ChoiceAddBook:
				// ChoiceAddBook();
				break;
			case ChoiceModifyBook:
				// ChoiceModifyBook();
				break;
			case Exit: return;
		}
	}
}