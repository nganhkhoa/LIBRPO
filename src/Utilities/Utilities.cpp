#include <Utilities.h>

using namespace std;

int ChooseUtilities(LoggedInUser& CurrentUser) {

	// return choice
	// of role
	// available for user

	cout << "Ban hay chon chuc nang muon su dung " << endl;
	for (int role = 0; role < CurrentUser.RoleId.size(); role++) {
		int roleid = CurrentUser.RoleId[role] - 1;
		cout << role + 1 << "\t" << LibraryRole[roleid].RoleName << endl;
	}
	cout << "De thoat ban chon 0" << endl;
	int role;
	cout << "Ban chon thuc hien chuc nang nao? ";
	cin >> role;

	while (role < 0 || role > CurrentUser.RoleId.size()) {
		cout << "Chuc nang khong co, moi chon lai: ";
		cin >> role;
	}
	return role;
}

void Utilities(LoggedInUser& CurrentUser, vector<Book>& BookData) {
	while (true) {
		system("cls");

		int role = ChooseUtilities(CurrentUser);

		if (role == 0) {
			cout << "Ban muon quay ve man hinh chinh? (y/n) ";
			string str;
			cin.ignore();
			getline(cin, str);
			if (str == "y") return;
			continue;
		}

		enum Roles
		{
			DocGiaRole = 1,
			ThuThuRole,
			QLNDRole,
			QLTCRole
		};
		switch (CurrentUser.RoleId[role - 1]) {    // switch by user own role id
			case DocGiaRole:
				cout << "Ban dang lua chon chuc nang doc gia" << endl;
				system("pause");
				Reader(CurrentUser);
				break;
			case ThuThuRole:
				cout << "Ban dang lua chon chuc nang thu thu" << endl;
				system("pause");
				Accountant(CurrentUser, BookData);
				break;
			case QLNDRole:
				cout << "Ban dang lua chon chuc nang quan ly nguoi dung"
				     << endl;
				system("pause");
				// Admin();
				break;
			case QLTCRole:
				cout << "Ban dang lua chon chuc nang quan ly tai chinh" << endl;
				system("pause");
				// Money();
				break;
		}
	}
}