#include <Browse.h>

using namespace std;

int BrowseOption() {
	// return choice
	// like the welcome
	system("cls");
	cout << "Chon cach duyet sach" << endl;
	cout << left << setw(5) << "1\t"
	     << "Khuyen khich" << endl;
	cout << left << setw(5) << "2\t"
	     << "Toan bo" << endl;
	cout << left << setw(5) << "3\t"
	     << "Sach hay" << endl;
	cout << left << setw(5) << "4\t"
	     << "Sach hay cua thang" << endl;
	cout << left << setw(5) << "5\t"
	     << "Sach hay cua nam" << endl;
	cout << left << setw(5) << "6\t"
	     << "Sach theo the loai" << endl;
	cout << left << setw(5) << "7\t"
	     << "Sach theo tac gia" << endl;
	cout << left << setw(5) << "8\t"
	     << "Tim sach" << endl;
	cout << left << setw(5) << "9\t"
	     << "Sach cua toi" << endl;
	cout << left << setw(5) << "10\t"
	     << "Thoat" << endl;

	int Choice;
	cout << "Lua chon cach duyet sach: ";
	cin >> Choice;
	while (Choice > 10 || Choice < 1) {
		cout << "Lua chon khong co, moi nhap lai: ";
		cin >> Choice;
	}
	return Choice;
}

void Browse() {

	enum BrowseMode
	{
		Recommended = 1,
		All,
		HotBook,
		HotMonth,
		HotYear,
		Genre,
		Author,
		Find,
		MyCollection,
		Exit
	};

	while (true) {
		// always show until press exit
		// show browseoption and switch by case
		switch (BrowseOption()) {
			case Recommended: break;
			case All:
				cin.ignore();
				ShowAllBook();
				// show all the book
				break;
			case HotBook: break;
			case HotMonth: break;
			case HotYear: break;
			case Genre: break;
			case Author: break;
			case Find: break;
			case MyCollection: break;
			case Exit: {
				cout << "Ban muon quay lai man hinh chinh? (y/n) ";
				cin.ignore();
				string Answer;
				getline(cin, Answer);
				if (Answer != "y")
					break;
				else
					return;    // exit function
			}
		}
	}
}