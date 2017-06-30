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
	cout << "1\t"
	     << "Xac nhan them nguoi dung" << endl;
	cout << "2\t"
	     << "Xoa nguoi dung" << endl;
	cout << "3\t"
	     << "Dat lai mat khau nguoi dung" << endl;
	cout << "4\t"
	     << "Khoa/Mo khoa nguoi dung" << endl;
	cout << "5\t"
	     << "Them vao thu thu moi" << endl;
	cout << "6\t"
	     << "Them vao quan ly tai chinh moi" << endl;
	cout << "7\t"
	     << "Quay ve" << endl;

	return ChoiceInput(7);
}


void Admin() {
	while (true) {
		enum Choice
		{
			ChoiceAdd = 1,
			ChoiceDelete,
			ChoiceReset,
			ChoiceLock,
			ChoiceNewLibrarian,
			ChoiceNewAccountant,
			Exit
		};
		switch (AdminChoice()) {
			case ChoiceAdd: AddUser(); break;
			case ChoiceDelete:
				cin.ignore();
				DeleteUser();
				break;
			case ChoiceReset:
				cin.ignore();
				PwdReset();
				break;
			case ChoiceLock:
				cin.ignore();
				UserLock();
				break;
			case ChoiceNewLibrarian:
				cin.ignore();
				NewADMINgroup(8);
				break;
			case ChoiceNewAccountant:
				cin.ignore();
				NewADMINgroup(9);
				break;
			case Exit: return;
		}
	}
}