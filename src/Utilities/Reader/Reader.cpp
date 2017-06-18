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
	     << "Mua sach" << endl;
	cout << "4\t"
	     << "Quay ve" << endl;

	cout << "Moi ban chon: ";
	cin >> Choice;
	while (Choice < 0 || Choice > 4) {
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
			ChoiceBuy,
			Exit
		};
		switch (ReaderChoice()) {
			case ChoiceBorrow:
				cin.ignore();
				BorrowBook();
				break;
			case ChoiceReturn:
				ReturnBook();
				break;
			case ChoiceBuy:
				cin.ignore();
				// BuyBook(CurrentUser);
				break;
			case Exit: return;
		}
	}
}