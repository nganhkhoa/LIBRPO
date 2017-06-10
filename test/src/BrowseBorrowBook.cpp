#include <Show.h>
#include <Utilities.h>

using namespace std;

bool GetBorrowData(vector<BorrowBookSubmit>& BorrowBookData) {
	ifstream borrowfile(FILEBorrowBook, ios::in);

	if (!borrowfile.is_open()) {
		cout << "Khong mo duoc file borrow.txt" << endl;
		system("pause");
		return false;
	}

	string str;
	while (getline(borrowfile, str)) {
		if (str.empty()) continue;

		stringstream scin(str);
		BorrowBookSubmit TempBorrowBookData;
		scin >> TempBorrowBookData.Status >> TempBorrowBookData.User_num >>
		  TempBorrowBookData.Account_num >> TempBorrowBookData.ISBN >>
		  TempBorrowBookData.Accountant_User_num >>
		  TempBorrowBookData.Accountant_Account_num;

		// running cpp check gives error
		// Accountant_User_num and Accountant_Account_num
		// not initialied

		BorrowBookData.push_back(TempBorrowBookData);
	}
	borrowfile.close();
	return true;
}

bool UpdateBorrowData(vector<BorrowBookSubmit>& BorrowBookData) {
	ofstream borrowfile(FILEBorrowBook, ios::out);

	if (!borrowfile.is_open()) {
		cout << "Khong mo duoc file borrow.txt" << endl;
		system("pause");
		return false;
	}

	for (int index = 0; index < BorrowBookData.size(); index++) {
		borrowfile << BorrowBookData[index].Status << "\t"
		           << BorrowBookData[index].User_num << "\t"
		           << BorrowBookData[index].Account_num << "\t"
		           << BorrowBookData[index].ISBN << "\t";

		if (BorrowBookData[index].Status == 0) {
			borrowfile << -1 << "\t" << -1 << endl;
			// -1 means not check
			cout << endl;
			continue;
		}
		// if validated, log the accountant info
		borrowfile << BorrowBookData[index].Accountant_User_num << "\t"
		           << BorrowBookData[index].Accountant_Account_num << endl;
	}

	borrowfile.close();
	return true;
}

bool CreateBorrowRecord(BorrowBookSubmit BorrowBookData) {
	ofstream borrowrecord(FILEBorrowRecord, ios::out | ios::app);

	if (!borrowrecord.is_open()) {
		cout << "Khong mo duoc file borrowrecord.txt" << endl;
		system("pause");
		return false;
	}

	borrowrecord << 0 << "\t"
	             // first number
	             // 0 for nothing
	             // 1 for received
	             // 2 for returned
	             << BorrowBookData.User_num << "\t"
	             << BorrowBookData.Account_num << "\t" << BorrowBookData.ISBN
	             // day
	             // month
	             // year
	             // when user received book
	             << endl;
	return true;
}

int ValidateBorrowBook(BorrowBookSubmit BorrowBookData) {
	system("cls");

	// show book info
	int Book_num = 0;
	// 1984 has book_num 0
	// FindBookByISBN(BookData, BorrowBookData.ISBN);
	// need to create this function
	cout << "Quyen sach can duoc muon:" << endl;
	ShowBookDataJSON(Book_num);

	// user to lend to info
	cout << "Nguoi muon muon sach nay la:" << endl;
	cout << BorrowBookData.User_num << "\t" << BorrowBookData.Account_num
	     << endl;

	// show choice
	cout << "Ban co muon cho khach hang nay muon sach?" << endl;
	cout << "1\t"
	     << "Co" << endl;
	cout << "2\t"
	     << "Khong" << endl;
	cout << "3\t"
	     << "Thoat" << endl;

	cout << "Moi ban chon: ";
	int Choice;
	cin >> Choice;
	while (Choice < 1 || Choice > 3) {
		cout << "Lua chon khong co, moi ban chon lai: ";
		cin >> Choice;
	}

	return Choice;
}

void BrowseBorrowBook() {
	system("cls");

	vector<BorrowBookSubmit> BorrowBookData;

	if (!GetBorrowData(BorrowBookData)) {
		cout << "Khong the load du lieu sach muon" << endl;
		system("pause");
		return;
	}


	bool NewRequest = false;
	for (int index = 0; index < BorrowBookData.size(); index++) {
		if (BorrowBookData[index].Status != 0) continue;    // book validated

		NewRequest = true;
		BorrowBookData[index].Status =
		  ValidateBorrowBook(BorrowBookData[index]);

		if (BorrowBookData[index].Status == 3) {
			BorrowBookData[index].Status = 0;    // return state
			break;                               // exit
		}

		// if not exit,
		// log the accountant who has made the validation
		BorrowBookData[index].Accountant_User_num = CurrentUser.User_num;

		if (BorrowBookData[index].Status == 2)
			continue;    // reject so nothing happens
		// maybe announce to the user??????

		if (!CreateBorrowRecord(BorrowBookData[index])) {
			cout << "Khong the cap nhat ban ghi muon" << endl;
			system("pause");
			return;
		}
		// until the accountant gives the book to client
		// the record is hold
		// if the user has receive
		// update in date ///and time///
		// we only care about days passed
	}
	if (!NewRequest) {
		cout << "Khong co yeu cau muon moi" << endl;
		cout << "Hay thu lai sau" << endl;
		cout << "Bam enter de quay ve" << endl;
		system("pause");
	}
	UpdateBorrowData(BorrowBookData);
	return;
}