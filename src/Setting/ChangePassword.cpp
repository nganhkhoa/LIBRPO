#include <Setting.h>

using namespace std;

bool ComparePassword(
  vector<User>& UserData,
  LoggedInUser& CurrentUser,
  string& VerifyPassword) {
	// cypher here

	string OldPassword = UserData[CurrentUser.User_num]
	                       .AccountList[CurrentUser.Account_num]
	                       .Password;

	if (OldPassword == VerifyPassword) return true;
	return false;
}


bool ChangePassword(
  vector<User>& UserData,
  LoggedInUser& CurrentUser,
  bool debug) {
	system("cls");
	cout << "Sau day he thong se yeu cau ban nhap mat ma cu" << endl;
	cout << "Neu ban khong muon thay doi thi hay de trong" << endl;
	cout << "Nhap password cu cua ban: ";
	string str;
	getline(cin, str);

	if (str.empty()) {
		cout << "Ban muon thoat? (y/n) ";
		string Answer;
		getline(cin, Answer);
		if (Answer != "y") {
			return ChangePassword(UserData, CurrentUser, debug);
		}
		else
			return false;
	}

	if (!ComparePassword(UserData, CurrentUser, str)) {
		cout << "Ban da nhap mat khau sai" << endl;
		cout << "Neu ban khong nho mat khau, hay lien he ban quan tri" << endl;
		cout << "de duoc cap lai mat khau moi" << endl;

		/*
		cout << "Ban con " << Attemps << " lan thu nua" << endl;
		cout << "Tai khoan se bi khoa neu nhap sai qua " << MAX_ATTEMPTS << "
		lan" << endl;
		//*/

		cout << "Ban muon thu lai? (y/n) ";

		string Answer;
		getline(cin, Answer);
		if (Answer == "y") {
			return ChangePassword(UserData, CurrentUser, debug);
		}
		else
			return false;
	}

	cout << "Ban hay nhap mat khau moi: ";
	getline(cin, str);

	if (!UpdatePassword(UserData, CurrentUser, str, debug)) {
		cout << "Cap nhat khong thanh cong" << endl;
		cout << "Bi loi mong quy khach thong cam" << endl;
		cout << "Bam enter de quay lai lua chon" << endl;
		system("pause");
		return false;
	}
	cout << "Cap nhat thanh cong" << endl;
	cout << "Bam enter de quay ve" << endl;
	system("pause");
	return true;
}