/*
 * @CreateTime: Jun 18, 2017 10:01 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 18, 2017 10:01 PM
 * @Description: Màn hình thủ thư
 */

#include <Utilities/Utilities.h>

using namespace std;

int LibrarianChoice() {
	clearscreen();
	int Choice;
	cout << "1\t"
	     << "Duyet sach muon" << endl;
	cout << "2\t"
	     << "Ghi nhan muon sach" << endl;
	cout << "3\t"
	     << "Duyet sach mua" << endl;
	cout << "4\t"
	     << "Ghi nhan mua sach" << endl;
	cout << "5\t"
	     << "Them sach vao thu vien" << endl;
	cout << "6\t"
	     << "Chinh sua sach trong thu vien" << endl;
	// view changes to database????????????
	cout << "7\t"
	     << "Thoat" << endl;

	cout << "Moi ban chon: ";
	cin >> Choice;
	while (Choice < 0 || Choice > 7) {
		cout << "Lua chon khong co, moi ban chon lai: ";
		cin >> Choice;
	}

	return Choice;
}

void Librarian() {

	while (true) {
		enum Choice
		{
			ChoiceBrowseBorrowSubmission = 1,
			ChoiceGetBorrowBook,
			ChoiceBrowseBuySubmission,
			ChoiceGetBuyBook,
			eChoiceAddBook,
			ChoiceModifyBook,
			Exit
		};
		switch (LibrarianChoice()) {
			case ChoiceBrowseBorrowSubmission: BrowseBorrowBook(); break;
			case ChoiceGetBorrowBook:
				cin.ignore();
				GiveBook();
				break;
			case ChoiceBrowseBuySubmission:
				// ChoiceBrowseBuySubmission();
				break;
			case ChoiceGetBuyBook: break;
			case eChoiceAddBook:
				cin.ignore();
				ChoiceAddBook();
				break;
			case ChoiceModifyBook:
				// ChoiceModifyBook();
				break;
			case Exit: return;
		}
	}
}