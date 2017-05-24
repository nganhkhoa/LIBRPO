#include <Setting.h>

using namespace std;

bool ComparePassword(string& VerifyPassword) {
	// cypher here

	string OldPassword = UserData[CurrentUser.User_num]
	                       .AccountList[CurrentUser.Account_num]
	                       .Password;

	if (OldPassword == VerifyPassword) return true;
	return false;
}


bool ChangePassword() {
	while (true) {
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
			if (Answer != "y") { continue; }
			else
				return false;
		}

		if (!ComparePassword(str)) {
			cout << "Ban da nhap mat khau sai" << endl;
			cout << "Neu ban khong nho mat khau, hay lien he ban quan tri"
			     << endl;
			cout << "de duoc cap lai mat khau moi" << endl;

			/*
			cout << "Ban con " << Attemps << " lan thu nua" << endl;
			cout << "Tai khoan se bi khoa neu nhap sai qua " << MAX_ATTEMPTS <<
			"
			lan" << endl;
			//*/

			cout << "Ban muon thu lai? (y/n) ";

			string Answer;
			getline(cin, Answer);
			if (Answer == "y") { continue; }
			else
				return false;
		}

		string NewPassword;
		while (true) {
			
			cout << "Ban hay nhap mat khau moi: ";
			getline(cin, NewPassword);

			cout << "Moi ban nhap lai mat khau moi: ";
			getline(cin, str);

			if (NewPassword != str) {
				cout << "Mat khau moi khong trung" << endl;
				cout << "Ban muon thu lai? (y/n): ";
				getline(cin, str);

				if (str == "y")
					continue;

				else
					return false;
			}

			cout << "De tiep tuc bam enter" << endl;
			system("pause");
			break;
		}

		if (!UpdatePassword(NewPassword)) {
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
}