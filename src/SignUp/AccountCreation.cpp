/*
 * @CreateTime: Jun 18, 2017 10:04 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: undefined
 * @Last Modified Time: Jun 24, 2017 1:57 PM
 * @Description: Tạo tài khoản mới
 *
 * Thông tin cơ bản như tên tài khoản và các chức năng
 */

#include <SignUp/SignUp.h>
#include <Data/ReadDataJSON.h>

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
	NewCreation.Account.AccountName    = NewCreation.Username;
	NewCreation.Account.AccountRoleMap = {1};
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


bool AccountExist(string& newaccountname) {
	json this_user = UserDataJSON.at("UserList")[CurrentUser.User_num];
	unsigned int num_account = this_user.at("AccountList").size();
	for (unsigned int index = 0; index < num_account; index++) {
		string name = this_user.at("AccountList")[index].at("AccountName");
		if (name == newaccountname) return true;
	}
	return false;
}

/**
 * For user has an account already
 */
void AccountCreation() {

	json NewAccount = json::object();
	cout << "Xin moi nhap vao ten tai khoan moi: ";
	NewAccount["AccountName"];
	string accountname;
	getline(cin, accountname);
	if (accountname == "") return;
	while (AccountExist(accountname)) {
		cout << "Tai khoan da ton tai, " << endl;
		cout << "Xin hay chon mot ten khac" << endl;
		cout << ">> ";
		getline(cin, accountname);
		if (accountname == "") return;
	}

	NewAccount.at("AccountName") = accountname;

	AccountType();
	unsigned int ChooseType = ChooseAccountType();

	if (ChooseType == 8) { return; }

	if (ChooseType == 7) {
		NewAccount["AccountRoleMap"] = {1, 2, 3, 4, 5, 6};
		json this_user = UserDataJSON.at("UserList")[CurrentUser.User_num];
		unsigned int num_account = this_user.at("AccountList").size();
		this_user.at("AccountList")[num_account]          = NewAccount;
		UserDataJSON.at("UserList")[CurrentUser.User_num] = this_user;
		UpdateUserDataJSON();
		return;
	}

	NewAccount["AccountRoleMap"] = json::array();

	string Answer = "";
	NewUser NewCreation;
	NewCreation.Account.AccountRoleMap.push_back(ChooseType);
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
			json this_user = UserDataJSON.at("UserList")[CurrentUser.User_num];
			unsigned int num_account = this_user.at("AccountList").size();
			this_user.at("AccountList")[num_account]          = NewAccount;
			UserDataJSON.at("UserList")[CurrentUser.User_num] = this_user;
			UpdateUserDataJSON();
		}

		if (AccountTypeExist(NewCreation, ChooseType)) {
			cout << "Chuc nang da duoc dang ky" << endl;
			cout << "Moi ban chon chuc nang khac, hoac thoat" << endl;
			continue;
		}
		NewCreation.Account.AccountRoleMap.push_back(ChooseType);
	}

	AccountRoleMapAdjustment(NewCreation);
	for (unsigned int index = 0;
	     index < NewCreation.Account.AccountRoleMap.size();
	     index++) {
		NewAccount.at("AccountRoleMap")
		  .push_back(NewCreation.Account.AccountRoleMap[index]);
	}
	json this_user = UserDataJSON.at("UserList")[CurrentUser.User_num];
	unsigned int num_account = this_user.at("AccountList").size();
	this_user.at("AccountList")[num_account]          = NewAccount;
	UserDataJSON.at("UserList")[CurrentUser.User_num] = this_user;
	UpdateUserDataJSON();
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

	cout << "Ban hay dat ten cho tai khoan cua ban: " << endl;
	cout << "Neu de trong se la ten dang nhap" << endl;
	cout << ">> ";
	getline(cin, NewCreation.Account.AccountName);

	if (NewCreation.Account.AccountName == "")
		NewCreation.Account.AccountName = NewCreation.Username;

	if (ChooseType == 7) {
		NewCreation.Account.AccountRoleMap = {};
		NewCreation.Account.AccountRoleMap = {1, 2, 3, 4, 5, 6};
		return;
	}

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