#include <Utilities.h>

using namespace std;

int ReaderChoice() {
	system("cls");
	int Choice;
	cout << "1\t" << "Muon sach" << endl;
	cout << "2\t" << "Tra sach" << endl;
	cout << "3\t" << "Mua sach" << endl;
	cout << "4\t" << "Quay ve" << endl;

	cout << "Moi ban chon: ";
	cin >> Choice;
	while (Choice < 0 || Choice > 4) {
		cout << "Lua chon khong co, moi ban chon lai: ";
		cin >> Choice;
	}

	return Choice;
}


void Reader(LoggedInUser CurrentUser) {
	while (true) {
		enum Choice{ChoiceBorrow = 1, ChoiceReturn, ChoiceBuy, Exit};
		switch (ReaderChoice())
		{
			case ChoiceBorrow: 
				cin.ignore();
				BorrowBook(CurrentUser);
				return;
			case ChoiceReturn:
				cin.ignore();
				//ReturnBook(CurrentUser);
				return;
			case ChoiceBuy:
				cin.ignore();
				//BuyBook(CurrentUser);
				return;
			case Exit:
				return;
		}
	}
}