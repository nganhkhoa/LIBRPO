#include "..\include\Welcome.h"

using namespace std;

int Welcome() {
		//nothing worth commenting
	system("cls");
	cout << "WELCOME TO LIBPRO" << endl;
	cout << left << setw(5) << "1\t" << "Dang nhap" << endl;
	cout << left << setw(5) << "2\t" << "Dang ky" << endl;
	cout << left << setw(5) << "3\t" << "Duyet sach" << endl;
	cout << left << setw(5) << "4\t" << "Huong dan thu vien" << endl;
	cout << left << setw(5) << "5\t" << "Thoat" << endl;
	
	int Choice = 0;
	cout << "Lua chon chuc nang: "; cin >> Choice;
	while (Choice > 5 || Choice < 1) {
		cout << "Chuc nang khong co, moi nhap lai: " ; cin >> Choice;
	}
	return Choice;
}
int WelcomeUser(LoggedInUser& NewUser) {
		//nothing worth commenting
		//NewUser because we say hello to user
	system("cls");
	cout << "WELCOME TO LIBPRO " << NewUser.AccId << endl;
	cout << left << setw(5) << "1\t" << "Dang xuat" << endl;
	cout << left << setw(5) << "2\t" << "Cai dat" << endl;
	cout << left << setw(5) << "3\t" << "Chuc nang" << endl;
	cout << left << setw(5) << "4\t" << "Duyet" << endl;
	cout << left << setw(5) << "5\t" << "Huong dan thu vien" << endl;
	cout << left << setw(5) << "6\t" << "Thoat" << endl;

	int Choice = 0;
	cout << "Lua chon chuc nang: "; cin >> Choice;
	while (Choice > 7 || Choice < 0) {
		cout << "Chuc nang khong co, moi nhap lai: " ; cin >> Choice;
	}
	return Choice;
}