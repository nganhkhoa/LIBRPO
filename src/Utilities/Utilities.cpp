#include <Utilities/Utilities.h>

using namespace std;

int ChooseUtilities() {

	// return choice
	// of role
	// available for user

	cout << "Ban hay chon chuc nang muon su dung " << endl;
	for (unsigned int role = 0; role < CurrentUser.RoleId.size(); role++) {
		int roleid = CurrentUser.RoleId[role] - 1;
		cout << role + 1 << "\t" << LibraryRole[roleid].RoleName << endl;
	}
	cout << CurrentUser.RoleId.size() + 1 << "\t Thoat" << endl;
	int role = 0;
	cout << "Ban chon thuc hien chuc nang nao? ";
	cin >> role;

	while (role < 1 || role > (int)CurrentUser.RoleId.size() + 1) {
		cout << "Chuc nang khong co, moi chon lai: ";
		cin >> role;
	}
	return role;
}

void Utilities() {
	while (true) {
		system("cls");

		int role = ChooseUtilities();

		if (role == (int)CurrentUser.RoleId.size() + 1) {
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
				Reader();
				break;
			case ThuThuRole:
				cout << "Ban dang lua chon chuc nang thu thu" << endl;
				system("pause");
				Accountant();
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