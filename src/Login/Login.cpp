#include <Login.h>
#include <Find.h>
#include <ReadDataJSON.h>

using namespace std;


bool UserLoginPrompt(int& User_num) {
	system("cls");
	cout << "Nhap ten nguoi dung de tiep tuc hoac de trong de thoat" << endl;
	// khi có giao diện thì cancel sẽ được thay bằng nút bấm, nút bấm nhảy về
	cout << "Ten nguoi dung:"
	     << "\t";
	string str;
	getline(cin, str);

	if (str.empty()) return false;

	User_num = FindUserByName(str);
	return true;
}

void ShowRoleList(UserAccount& recordNum) {
	// show role just for in vector struct
	int num_Roles = UserDataJSON.at("UserList")[recordNum.User_num]
	                  .at("AccountList")[recordNum.Account_num]
	                  .at("AccountRoleMap")
	                  .size();
	for (int Role_num = 0; Role_num < num_Roles; Role_num++) {

		int role = UserDataJSON.at("UserList")[recordNum.User_num]
		             .at("AccountList")[recordNum.Account_num]
		             .at("AccountRoleMap")[Role_num];
		role -= 1;
		// number save in file from 1 to 3,
		// computer count from 0 to 2
		cout << LibraryRole[role].RoleName << ";\t";
	}
}

void ShowAccountList(int& User_num) {
	// show availabel account
	int num_Accounts =    // get number of account a user has
	  UserDataJSON.at("UserList")[User_num].at("AccountList").size();
	  
	for (int Account_num = 0; Account_num < num_Accounts; Account_num++) {

		string AccountID =    // clear "" in string
		  UserDataJSON.at("UserList")[User_num].at("AccountList")[Account_num].at(
		    "AccountName");

		cout << left << setw(5) << Account_num + 1 << "\t";
		cout << AccountID << "\t";

		UserAccount recordNum = {User_num, Account_num};
		ShowRoleList(recordNum);
		cout << endl;
	}
}

int AccountLoginPrompt(int& User_num) {
	system("cls");
	cout << "Chon tai khoan ban muon dang nhap (so): " << endl;
	cout << "De dung lai, xin nhap 0." << endl;

	ShowAccountList(
	  User_num);    // show the account with no pass and active state

	cout << "Lua chon cua ban? ";
	int Choice;
	cin >> Choice;

	// error handler nedded: text input

	if (Choice == 0) return Choice;    // set to getline and empty? maybe later

	int num_Accounts =    // get number of account a user has
	  UserDataJSON.at("UserList")[User_num].at("AccountList").size();


	while (Choice > num_Accounts || Choice < 0) {
		cout << "Tai khoan so " << Choice << " khong co, moi nhap lai: ";
		cin >> Choice;
	}

	// check if user is lock

	bool Locked =
	  UserDataJSON.at("UserList")[User_num].at("AccountList")[Choice - 1].at(
	    "Lock");

	if (Locked) {
		cout << "Tai khoan nay hien dang bi khoa" << endl;
		cout << "Xin moi ban chon tai khoan khac" << endl;
		cout << "Bam Enter de thu lai" << endl;
		system("pause");
		Choice = AccountLoginPrompt(User_num);
	}

	return Choice;
}

void LockAccount(UserAccount& recordNum) {
	UserDataJSON.at("UserList")[recordNum.User_num]
	  .at("AccountList")[recordNum.Account_num]
	  .at("Lock") = true;
	  
	UpdateUserDataJSON();
	return;
}

bool RightPassword(UserAccount& recordNum, int& Attemps) {
	system("cls");

	cout << "Ban chon dang nhap " << endl;
	cout << "Nhap password de thuc hien dang nhap" << endl;
	cout << "Bo trong se quay nguoc lai man hinh chon ten dang nhap" << endl;

	if (Attemps == 0)
		cin.ignore();                    // first attemp
	else if (Attemps < MAX_ATTEMPT) {    // wrong but still ok
		cout << "Ban con " << MAX_ATTEMPT - Attemps << " lan thu" << endl;
		cout << "Neu ban nhap sai qua " << MAX_ATTEMPT
		     << " lan, tai khoan se bi khoa" << endl;
	}
	else if (Attemps == MAX_ATTEMPT) {    /// lock this user
		LockAccount(recordNum);
		cout << "Tai khoan nay da bi khoa do nhap sai mat khau nhieu lan"
		     << endl;
		cout
		  << "Hay lien he ban quan tri de lay lai quyen truy cap tai khoan nay"
		  << endl;
		system("pause");
		Attemps = 0;    // set to zero to choose username again
		return true;
	}

	// if they are privilege to enter password

	string AccountID = UserDataJSON.at("UserList")[recordNum.User_num]
	                     .at("AccountList")[recordNum.Account_num]
	                     .at("AccountName");

	cout << AccountID << ":\t";
	string pwd_entered;
	getline(cin, pwd_entered);

	if (pwd_entered.empty()) {    // leave empty to go back to choose username
		Attemps = 0;
		return true;
	}
	else
		Attemps++;

	// cipher data?

	// check the f*@#$*& password
	// password not hashed yet
	string ThePassword = UserDataJSON.at("UserList")[recordNum.User_num]
	                       .at("AccountList")[recordNum.Account_num]
	                       .at("Password");
	if (ThePassword != pwd_entered) return false;
	return true;
}

void CreateLoggedInUser(UserAccount& recordNum) {

	CurrentUser.User_num    = recordNum.User_num;
	CurrentUser.Account_num = recordNum.Account_num;
	CurrentUser.AccId       = UserDataJSON.at("UserList")[recordNum.User_num]
	                      .at("AccountList")[recordNum.Account_num]
	                      .at("AccountName");


	int num_Roles = UserDataJSON.at("UserList")[recordNum.User_num]
	                  .at("AccountList")[recordNum.Account_num]
	                  .at("AccountRoleMap")
	                  .size();

	for (int Role_num = 0; Role_num < num_Roles; Role_num++) {

		int role = UserDataJSON.at("UserList")[recordNum.User_num]
		             .at("AccountList")[recordNum.Account_num]
		             .at("AccountRoleMap")[Role_num];

		CurrentUser.RoleId.push_back(role);
	}
	return;
}

bool LoggedIn() {

	//.....Still have no Idea how to make this smaller......

	int User_num = -1;
	// to track the user being run

	while (true) {
		if (UserLoginPrompt(User_num)) {
			// run login prompt
			// with arg User_num
			if (User_num == UserDataJSON.at("UserList").size()) {
				// user not found
				cout << "Ten nguoi dung khong hien huu" << endl;
				cout << "Bam enter de thu lai" << endl;
				system("pause");
				continue;
			}
			else
				break;    // if found proceed account choosing
		}
		else {    // if User_num = -1
			cout << "\nBan khong muon dang nhap nua? (y/n) ";
			string str;
			getline(cin, str);
			if (str == "y") { return false; }
			else
				continue;    // login prompt
		}
	}

	int Account_num = AccountLoginPrompt(User_num) - 1;    // chose account
	if (Account_num == -1) return false;                   // no account chosen
	// run cppcheck retrun error Reference to auto variable returned.
	UserAccount recordNum = {User_num,
	                         Account_num};    // save user place in vector

	// input password
	int Attemps = 0;
	while (!RightPassword(recordNum, Attemps))
		;
	// check right password or not
	// remember leave blank returns to login

	// the attemps must be > 1 if enter right or wrong
	// if attemps == 0, the str enter is empty, user choose the login name again

	if (Attemps == 0) return LoggedIn();
	// return login if left blank
	// attemps set to 0
	else
		CreateLoggedInUser(recordNum);
	// create the LoggedInUser data to store

	return true;
	// run cppcheck retrun error Reference to auto variable returned.
}