/*
 * @CreateTime: Jun 18, 2017 9:57 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 18, 2017 9:57 PM
 * @Description: Màn hình chính
 */

#include <Welcome/Welcome.h>

using namespace std;

int Welcome() {
	// nothing worth commenting
	clearscreen();
	cout << "WELCOME TO LIBPRO" << endl;
	cout << left << setw(5) << "1\t"
	     << "Dang nhap" << endl;
	cout << left << setw(5) << "2\t"
	     << "Dang ky" << endl;
	cout << left << setw(5) << "3\t"
	     << "Huong dan thu vien" << endl;
	cout << left << setw(5) << "4\t"
	     << "Thoat" << endl;

	int Choice = 0;
	cout << "Lua chon chuc nang: ";
	cin >> Choice;
	while (Choice > 4 || Choice < 1) {
		cout << "Chuc nang khong co, moi nhap lai: ";
		cin >> Choice;
	}
	return Choice;
}
int WelcomeUser() {
	// nothing worth commenting
	// NewUser because we say hello to user
	clearscreen();
	cout << "WELCOME TO LIBPRO " << CurrentUser.Username << endl;
	cout << left << setw(5) << "1\t"
	     << "Dang xuat" << endl;
	cout << left << setw(5) << "2\t"
	     << "Tao tai khoan moi" << endl;
	cout << left << setw(5) << "3\t"
	     << "Cai dat" << endl;
	cout << left << setw(5) << "4\t"
	     << "Chon tai khoan" << endl;
	cout << left << setw(5) << "5\t"
	     << "Tao tai khoan" << endl;
	cout << left << setw(5) << "6\t"
	     << "Duyet" << endl;
	cout << left << setw(5) << "7\t"
	     << "Huong dan thu vien" << endl;
	cout << left << setw(5) << "8\t"
	     << "Thoat" << endl;

	if (UserDataJSON.at("UserList")[CurrentUser.User_num].at("First")) {
		cout << endl << endl;
		cout << "Chao mung ban lan dau den voi LIBPRO" << endl;
		cout << "Chung toi khuyen ban chon so 3 de doi mat khau" << endl;
	}
	int Choice = 0;
	cout << "Lua chon chuc nang: ";
	cin >> Choice;
	while (Choice > 8 || Choice < 1) {
		cout << "Chuc nang khong co, moi nhap lai: ";
		cin >> Choice;
	}
	return Choice;
}
int WelcomeAccount() {
	// nothing worth commenting
	// NewUser because we say hello to user
	clearscreen();
	cout << "WELCOME TO LIBPRO " << CurrentUser.Username << endl;
	cout << "Ban dang dang nhap duoi tai khoan" << endl;
	cout << "\t\t" << CurrentUser.AccountName << endl;
	cout << left << setw(5) << "1\t"
	     << "Dang xuat" << endl;
	cout << left << setw(5) << "2\t"
	     << "Cai dat" << endl;
	cout << left << setw(5) << "3\t"
	     << "Chuc nang" << endl;
	cout << left << setw(5) << "4\t"
	     << "Duyet" << endl;
	cout << left << setw(5) << "5\t"
	     << "Huong dan thu vien" << endl;
	cout << left << setw(5) << "6\t"
	     << "Thoat" << endl;

	int Choice = 0;
	cout << "Lua chon chuc nang: ";
	cin >> Choice;
	while (Choice > 6 || Choice < 1) {
		cout << "Chuc nang khong co, moi nhap lai: ";
		cin >> Choice;
	}
	return Choice;
}