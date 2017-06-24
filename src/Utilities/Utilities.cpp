/*
 * @CreateTime: Jun 18, 2017 9:57 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 18, 2017 9:57 PM
 * @Description: Màn hình chọn chức năng
 */

#include <Utilities/Utilities.h>

using namespace std;
using json = nlohmann::json;

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

	while (role < 1 || role > (int) CurrentUser.RoleId.size() + 1) {
		cout << "Chuc nang khong co, moi chon lai: ";
		cin >> role;
	}
	return role;
}

void Utilities() {
	while (true) {
		clearscreen();

		int role = ChooseUtilities();

		if (role == (int) CurrentUser.RoleId.size() + 1) {
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
			NhaSuuTamRole,
			ReviewerRole,
			CDRole,
			MovieRole,
			EbookRole,
			// VipRole, // no, vip has all of the above
			ThuThuRole = 8,
			QLTCRole,
			QLNDRole
		};

		switch (CurrentUser.RoleId[role - 1]) {    // switch by user own role id
			case DocGiaRole:
				cout << "Ban dang lua chon chuc nang doc gia" << endl;
				pausescreen();
				Reader();
				break;
			case ThuThuRole:
				cout << "Ban dang lua chon chuc nang thu thu" << endl;
				pausescreen();
				Librarian();
				break;
			case QLNDRole:
				cout << "Ban dang lua chon chuc nang quan ly nguoi dung"
				     << endl;
				pausescreen();
				Admin();
				break;
			case QLTCRole:
				cout << "Ban dang lua chon chuc nang quan ly tai chinh" << endl;
				pausescreen();
				Money();
				break;
		}
	}
}

json readSubmitBorrow() {
	json Submit;

	ifstream Submissionfile(FILESubmission, ios::in);
	if (!Submissionfile.is_open()) return NULL;

	Submissionfile >> Submit;
	Submissionfile.close();
	return Submit;
}

bool updateSubmitBorrow(json& Submit) {
	ofstream Submissionfile(FILESubmission, ios::out);
	if (!Submissionfile.is_open()) return false;
	Submissionfile << Submit.dump(4);
	Submissionfile.close();
	return true;
}


json readBorrowLog() {
	json BorrowLog;

	ifstream borrowlogfile(FILEborrowLog, ios::in);
	if (!borrowlogfile.is_open()) return NULL;

	borrowlogfile >> BorrowLog;
	borrowlogfile.close();
	return BorrowLog;
}

void updateBorrowLog(json& borrowLog) {
	ofstream borrowlogfile(FILEborrowLog, ios::out);
	borrowlogfile << borrowLog.dump(4);
	return;
}