/*
 * @CreateTime: Jun 18, 2017 10:18 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 18, 2017 10:18 PM
 * @Description: Chọn tài khoản lúc đăng nhập
 * 
 * Càn kiểm tra thêm các trường hợp không thể đăng nhập
 */

#include <AccountChoose/AccountChoose.h>

using namespace std;

void CreateLoggedInAccount(unsigned int& account_num) {

	CurrentUser.Account_num = account_num;

	string account_name = UserDataJSON.at("UserList")[CurrentUser.User_num]
	                        .at("AccountList")[CurrentUser.Account_num]
	                        .at("AccountName");
	CurrentUser.AccountName = account_name;

	unsigned int num_role = UserDataJSON.at("UserList")[CurrentUser.User_num]
	                          .at("AccountList")[CurrentUser.Account_num]
	                          .at("AccountRoleMap")
	                          .size();

	for (unsigned int index = 0; index < num_role; index++) {
		int roleID = UserDataJSON.at("UserList")[CurrentUser.User_num]
		               .at("AccountList")[CurrentUser.Account_num]
		               .at("AccountRoleMap")[index];
		CurrentUser.RoleId.push_back(roleID);
	}
	return;
}

void ShowAccountRoleMap(unsigned int& account_num) {
	unsigned int num_role = UserDataJSON.at("UserList")[CurrentUser.User_num]
	                          .at("AccountList")[account_num]
	                          .at("AccountRoleMap")
	                          .size();

	for (unsigned int index = 0; index < num_role; index++) {
		int roleID = UserDataJSON.at("UserList")[CurrentUser.User_num]
		               .at("AccountList")[account_num]
		               .at("AccountRoleMap")[index];
		cout << LibraryRole[roleID - 1].RoleName << "\n\t\t";
	}
}

unsigned int ShowAccountList() {

	unsigned int num_account = UserDataJSON.at("UserList")[CurrentUser.User_num]
	                             .at("AccountList")
	                             .size();
	for (unsigned int index = 0; index < num_account; index++) {
		string account_name = UserDataJSON.at("UserList")[CurrentUser.User_num]
		                        .at("AccountList")[index]
		                        .at("AccountName");
		cout << index + 1 << ".\t" << account_name << "\n\t\t";
		ShowAccountRoleMap(index);
		cout << endl;
		cout << "____________________________________";
		cout << endl;
	}
	cout << num_account + 1 << ".\tThoat" << endl;
	cout << "Moi ban chon: ";

	unsigned int Choice = 0;
	cin >> Choice;
	while (Choice < 1 || Choice > num_account + 1) {
		cout << "Lua chon khong hop le" << endl;
		cout << "Moi ban chon lai: " << endl;
		cin >> Choice;
	}

	return Choice;
}

void AccountChoose() {

	clearscreen();
	unsigned int num_account = UserDataJSON.at("UserList")[CurrentUser.User_num]
	                             .at("AccountList")
	                             .size();
	if (num_account == 0) {
		cout << "Ban hien chua co tai khoan" << endl;
		cout << "Xin vui long tao tai khoan truoc khi chon" << endl;
		pausescreen();
		return;
	}


	unsigned int account_num = ShowAccountList() - 1;
	if (account_num == num_account) return;

	bool Lock = UserDataJSON.at("UserList")[CurrentUser.User_num]
	              .at("AccountList")[account_num]
	              .at("Lock");
	if (Lock) {
		cout << "Tai khoan nay dang bi khoa" << endl;
		cout << "Ban hay lien he ban quan tri de biet them thong tin" << endl;
		pausescreen();
		return;
	}

	CreateLoggedInAccount(account_num);
	return;
}