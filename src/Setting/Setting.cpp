/*
 * @CreateTime: Jun 18, 2017 10:07 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 18, 2017 10:07 PM
 * @Description: Màn hình cài đặt
 */

#include <Setting/Setting.h>

using namespace std;

int SettingMenu() {
	clearscreen();
	cout << left << setw(5) << "1\t"
	     << "Thay doi mat khau" << endl;
	cout << left << setw(5) << "2\t"
	     << "Thoat" << endl;

	int Choice = 0;
	cout << "Lua chon chuc nang: ";
	cin >> Choice;
	while (Choice > 2 || Choice < 1) {
		cout << "Chuc nang khong co, moi nhap lai: ";
		cin >> Choice;
	}
	return Choice;
}

void Setting() {
	enum Choice
	{
		PwdChange = 1,
		Exit
	};
	while (true) {
		switch (SettingMenu()) {
			case PwdChange:
				cin.ignore();
				if (!ChangePassword()) { break; }
				CurrentUser.Active = false;
				LogoutHistory();
				return;
			case Exit: {
				cout << "Ban muon thoat? (y/n) ";
				cin.ignore();
				string Answer;
				getline(cin, Answer);
				if (Answer != "y")
					break;
				else
					return;
			}
		}
	}
}