/*
 * @CreateTime: Jun 18, 2017 9:58 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: undefined
 * @Last Modified Time: Jun 18, 2017 9:59 PM
 * @Description: Màn hình độc giả
 */

#include <Utilities/Utilities.h>

using namespace std;

int ReaderChoice() {
	clearscreen();
	int Choice;
	cout << "1\t"
	     << "Muon sach" << endl;
	cout << "2\t"
	     << "Tra sach" << endl;
	cout << "3\t"
	     << "Sach cua toi" << endl;
	cout << "4\t"
	     << "Gio sach cua toi" << endl;
	cout << "5\t"
	     << "Sach toi dang muon" << endl;
	cout << "6\t"
	     << "Thoat" << endl;

	cout << "Moi ban chon: ";
	cin >> Choice;
	while (Choice < 0 || Choice > 6) {
		cout << "Lua chon khong co, moi ban chon lai: ";
		cin >> Choice;
	}

	return Choice;
}


void Reader() {
	while (true) {
		enum Choice
		{
			ChoiceBorrow = 1,
			ChoiceReturn,
			ChoiceFav,
			ChoiceCart,
			ChoiceBorrowList,
			Exit
		};
		switch (ReaderChoice()) {
			case ChoiceBorrow:
				cin.ignore();
				BorrowBook();
				break;
			case ChoiceReturn: ReturnBook(); break;
			case ChoiceFav:
				cin.ignore();
				ShowFav();
				break;
			case ChoiceCart:
				cin.ignore();
				ShowCart();
				break;
			case ChoiceBorrowList:
				cin.ignore();
				ShowBorrow();
				break;
			case Exit: return;
		}
	}
}