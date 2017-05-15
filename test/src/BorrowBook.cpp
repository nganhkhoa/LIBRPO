#include <Utilities.h>

using namespace std;

bool CreateRequestBorrowBook(LoggedInUser CurrentUser, string Book_name) {
	ofstream requestborrowbook("borrow.txt", ios::out | ios::app);
	if (!requestborrowbook) {
		cout << "Cannot open file" << endl;
		system("pause");
		return false;
	}

	string BookId = /*FindBookByName(str)*/ "123456789";
	requestborrowbook << "0" << "\t"
					  << CurrentUser.User_num << "\t"
					  << CurrentUser.Account_num << "\t"
					  << BookId << endl;
	requestborrowbook.close();
	return true;
}

void BorrowBook(LoggedInUser CurrentUser) {
	system("cls");
	cout << "Nhap ten sach ban muon muon" << endl;
	cout << "Neu de trong se quay ve" << endl;
	//cout << "Neu ban muon muon tu gio sach, go \"giosach\"" << endl;
	cout << "Ten sach: ";
	string str;
	getline(cin, str);

	if (str.empty())
		return;
	if (str == "giosach")
		//BorrowFromCart(CurrentUser);

	if(!/*FindBookByName(str)*/true) {
		cout << "Ten sach khong tim thay" << endl;
		cout << "Moi ban nhap lai" << endl;
		BorrowBook(CurrentUser);
	}

	if (!CreateRequestBorrowBook(CurrentUser, str)) {
		cout << "Yeu cau khong gui duoc" << endl;
		cout << "Bam enter de tiep tuc" << endl;
		system("pause");
		return;
	}

	cout << "Yeu cau da duoc gui," << endl;
	cout << "Cho xac nhan cua thu thu" << endl;
	cout << "Bam enter de quay ve" << endl;
	system("cls");
	return;

}