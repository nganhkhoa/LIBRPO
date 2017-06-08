#include <Utilities.h>

using namespace std;

bool CreateRequestBorrowBook(string& Book_name) {
	ofstream requestborrowbook(FILEBorrowBook, ios::out | ios::app);
	if (!requestborrowbook) {
		cout << "Cannot open file" << endl;
		system("pause");
		return false;
	}

	string BookId = /*FindBookByName(Book_name)*/ "978-0451524935";
	requestborrowbook << "0" << "\t" 
					  << CurrentUser.Username << "\t"
					  << BookId << "\t" 
					  << -1 << "\t" 
					  << -1 << endl;
	requestborrowbook.close();
	return true;
}

void BorrowFromCart(vector<Book>& Cart) {
	for (int index = 0; index < Cart.size(); index++) {
		if (index > MAX_BORROW /*- UserBorrow*/) {
			cout << "Ban dang muon hon so quyen sach co the" << endl;
			cout << "Ban khong muon them duoc nua" << endl;
			cout << "Cac cuon sach da duoc gui yeu cau: " << endl << endl;
			for (int books = 0; books < 3; books++) {
				cout << Cart[books].BookLabel << endl;
			}
			system("pause");
			return;
		}
		if (!CreateRequestBorrowBook(Cart[index].BookId)) {
			cout << "Khong the gui yeu cau sach" << endl;
			cout << "Bam enter de tiep tuc" << endl;
			system("pause");
			return;
		}
	}
	return;
}

void BorrowBook(/*vector<Book>& BorrowCart*/) {
	while (true) {
		system("cls");
		cout << "Nhap ten sach ban muon muon" << endl;
		cout << "Neu de trong se quay ve" << endl;
		cout << "Neu ban muon muon tu gio sach, go \"giosach\"" << endl;
		cout << "Ten sach: ";
		string str;
		getline(cin, str);

		if (str.empty()) return;
		if (str == "giosach") {
			// BorrowFromCart(BorrowCart);
			return;
		}

		string& BookName = str;
		if (!/*FindBookByName(BookName)*/ true) {
			cout << "Ten sach khong tim thay" << endl;
			cout << "Moi ban nhap lai" << endl;
			cout << "Bam enter de tiep tuc" << endl;
			system("pause");
			continue;
		}

		if (!CreateRequestBorrowBook(BookName)) {
			cout << "Yeu cau khong gui duoc" << endl;
			cout << "Bam enter de tiep tuc" << endl;
			system("pause");
			return;
		}

		cout << "Yeu cau da duoc gui," << endl;
		cout << "Cho xac nhan cua thu thu" << endl;
		cout << "Bam enter de quay ve" << endl;
		system("pause");
		return;
	}
}