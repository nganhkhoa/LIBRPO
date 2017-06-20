/*
 * @CreateTime: Jun 18, 2017 10:04 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 18, 2017 10:04 PM
 * @Description: Tạo tài khoản mới
 *
 * Thông tin cơ bản như tên tài khoản và các chức năng
 */

#include <SignUp/SignUp.h>

using namespace std;
using json = nlohmann::json;


void AccountRoleMapAdjustment(NewUser& NewCreation) {

	vector<unsigned int>& thisVector = NewCreation.Account.AccountRoleMap;
	bool reader                      = false;

	for (unsigned int index = 0; index < thisVector.size(); index++) {
		if (thisVector[index] == 1) {
			reader = true;
			break;
		}
	}

	if (!reader) thisVector.push_back(1);

	InsertionSort(thisVector);
}


bool AccountTypeExist(NewUser& NewCreation, unsigned int ChooseType) {
	unsigned int roles = NewCreation.Account.AccountRoleMap.size();
	for (unsigned int index = 0; index < roles; index++) {
		unsigned int roleid = NewCreation.Account.AccountRoleMap[index];
		if (ChooseType == roleid) { return true; }
	}
	return false;
}


void DefaultAccount(NewUser& NewCreation) {
	return;
}

unsigned int ChooseAccountType() {
	cout << "Lua chon cua ban?" << endl;
	cout << "Neu de mac dinh, se la doc gia" << endl;
	cout << "Lua chon: ";
	unsigned int Choice = 0;
	cin >> Choice;
	while (Choice < 1 || Choice > 8) {
		cout << "Lua chon khong hop le" << endl;
		cout << "Ban hay nhap lai: ";
		cin >> Choice;
	}
	return Choice;
}

void AccountType() {
	clearscreen();
	for (unsigned int index = 0; index < 7; index++) {
		cout << LibraryRole[index].RoleId << ".\t"
		     << LibraryRole[index].RoleName << "\n\t"
		     << LibraryRole[index].RoleDesc << "\n\t"
		     << "Phi thu moi thang: ";
		cout << LibraryRole[index].Price;
		cout << ".000 VND" << endl;
	}
	cout << 8 << ".\tThoat" << endl << endl;
}

/**
 * For user has an account already
 */
void AccountCreation() {
	AccountType();
	unsigned int ChooseType = ChooseAccountType();

	if (ChooseType == 8) { return; }
}

/**
 * For new user signup
 */
void AccountCreation(NewUser& NewCreation) {
	clearscreen();
	cout << "Sau day ban se duoc chon cac quyen loi cua he thong" << endl;
	cout << "Ban co the khong chon va chung toi se tao mac dinh" << endl;
	cout << "ban la mot doc gia" << endl;
	cout << "Ten tai khoan se la ten dang nhap cua ban" << endl;
	AccountType();
	unsigned int ChooseType = ChooseAccountType();

	if (ChooseType == 8) {
		DefaultAccount(NewCreation);
		return;
	}

	NewCreation.Account.AccountName = NewCreation.Username;
	NewCreation.Account.AccountRoleMap.push_back(ChooseType);

	string Answer = "";
	while (true) {
		cout << "Ban muon dang ky mot chuc nang khac? ";
		cin.ignore();
		getline(cin, Answer);
		if (Answer != "y") break;

		AccountType();
		ChooseType = ChooseAccountType();

		if (ChooseType == 8) { break; }

		if (ChooseType == 7) {
			NewCreation.Account.AccountRoleMap = {};
			NewCreation.Account.AccountRoleMap = {1, 2, 3, 4, 5, 6};
			return;
		}

		if (AccountTypeExist(NewCreation, ChooseType)) {
			cout << "Chuc nang da duoc dang ky" << endl;
			cout << "Moi ban chon chuc nang khac, hoac thoat" << endl;
			continue;
		}
		NewCreation.Account.AccountRoleMap.push_back(ChooseType);
	}

	AccountRoleMapAdjustment(NewCreation);
	return;
}