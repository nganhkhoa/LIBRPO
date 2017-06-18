/*
 * @CreateTime: Jun 18, 2017 10:03 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 18, 2017 10:03 PM
 * @Description: Màn hình quản lý người dùng
 */

#include <Utilities/Utilities.h>

using namespace std;

int AdminChoice() {
	clearscreen();
	int Choice;
	cout << "1\t"
	     << "Xac nhan them nguoi dung" << endl;
	cout << "2\t"
	     << "Xoa nguoi dung" << endl;
	cout << "3\t"
	     << "Dat lai mat khau nguoi dung" << endl;
	cout << "4\t"
	     << "Them vao quan ly moi" << endl;
	cout << "5\t"
	     << "Quay ve" << endl;

	cout << "Moi ban chon: ";
	cin >> Choice;
	while (Choice < 0 || Choice > 5) {
		cout << "Lua chon khong co, moi ban chon lai: ";
		cin >> Choice;
	}

	return Choice;
}


void Admin() {
	while (true) {
		enum Choice
		{
			ChoiceAdd = 1,
			ChoiceDelete,
			ChoiceReset,
			ChoiceNew,
			Exit
		};
		switch (AdminChoice()) {
			case ChoiceAdd: AddUser(); break;
			case ChoiceDelete: 
				cin.ignore();
				DeleteUser();
				break;
			case ChoiceReset: break;
			case ChoiceNew: break;
			case Exit: return;
		}
	}
}