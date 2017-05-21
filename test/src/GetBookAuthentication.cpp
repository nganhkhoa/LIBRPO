#include <Utilities.h>

using namespace std;

bool LoadBorrowRecord(BorrowBookSubmit BorrowData) {
	ifstream borrowrecord(FILEBorrowRecord, ios::in);
	if (!borrowrecord.is_open()) {
		cout << "Cannot open borrowrecord.txt" << endl;
		system("pause");
		return false;
	}

	string str;
	getline(borrowrecord, str);    // skip
	while (getline(borrowrecord, str)) {
		if (str.empty()) continue;
		BorrowBookSubmit TempBorrowData;
		stringstream scin(str);
		scin >> TempBorrowData.Status;
		if (TempBorrowData.Status == 0) continue;

		scin >> TempBorrowData.User_num >> TempBorrowData.Account_num >>
		  TempBorrowData.ISBN;

		BorrowData.push_back(TempBorrowData);
	}
}


void GetBookAuthentication(vector<User>& UserData, vector<Book>& BookData, LoggedInUser& CurrentUser) {

	BorrowBookSubmit BorrowData;
	if (!LoadBorrowRecord(BorrowData)) return;

	string str;
	cout << "Ban hay nhap ten nguoi dung: ";
	string Username;
	getline(cin, Username);
	cout << "Ban hay chon tai khoan: ";
	string Accountname;
	getline(cin, Accountname);

	Borrow_num = FindUserBorrow(Username, Accountname, BorrowData);
	if (Borrow_num == 0) {
		cout << "Khong tim thay nguoi dung trong bien ban muon sach" << endl;
		system("pause");
		return;
	}

	cout << "Nguoi dung muon muon sach nhu sau: " << endl;
	// int Book_num = FindBookByISBN(BookData, BorrowData.ISBN);
	ShowBookData(BookData, Book_num);

	cout << "Hay cho nguoi dung nhap mat khau de xac thuc muon" << endl;
	cout << "Mat khau nguoi dung: ";
	string Password;
	getline(cin, Password);
	string UserPassword = UserData[Borrow_num.User_num]
	                        .AccountList[Borrow_num.Account_num]
	                        .Password;
	// cypher????
	if (Password != UserPassword) {
		for (int attemps = 1; attemps < 3; attemps++) {
			cout << "Ban da nhap sai mat khau, ban con: " << 3 - attemps
			     << " lan thu" << endl;
			cout << "Moi ban nhap lai: ";
			getline(cin, Password);
			if (Password == UserPassword) break;
		}
		cout << "Nguoi dung da nhap sai mat khau qua so lan quy dinh" << endl;
		cout << "Nguoi dung khong the xac nhan muon quyen sach nay" << endl;
		cout << "Bam enter de tiep tuc" << endl;
		system("pause");
		return;
	}

	cout << "Mat khau nhap vao dung" << endl;
	cout << "Tiep tuc, moi thu thu nhap mat khau: " << endl;
	getline(cin, Password);
	string AccountantPassword = UserData[CurrentUser.User_num]
	                              .AccountList[CurrentUser.Account_num]
	                              .Password;
	if (Password != AccountantPassword) {
		for (int attemps = 1; attemps < 3; attemps++) {
			cout << "Ban da nhap sai mat khau, ban con: " << 3 - attemps
			     << " lan thu" << endl;
			cout << "Moi ban nhap lai: ";
			getline(cin, Password);
			if (Password == UserPassword) break;
		}
		cout << "Thu thu da nhap sai mat khau qua so lan quy dinh" << endl;
		cout << "Khong the xac nhap thu thu" << endl;
		cout << "Khong the muon sach khi xac nhan thu thu sai" << endl;
		cout << "Bam enter de tiep tuc" << endl;
		system("pause");
		return;
	}

	if (!UpdateBorrowRecord(BorrowData, Borrow_num, CurrentUser)) {
		cout << "Cap nhat ban ghi khong thanh cong" << endl;
		cout << "Hay thu lai sau" << endl;
		system("pause");
		return;
	}
	cout << "Da thanh cong cap nhat ban ghi" << endl;
	cout << "Thu thu hay dua sach cho nguoi dung" << endl;
	system("pause");
	return;
}