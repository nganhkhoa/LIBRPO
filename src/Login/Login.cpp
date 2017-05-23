#include <Login.h>
#include <Find.h>

using namespace std;



bool UserLoginPrompt(vector<User>& UserData, int& User_num) {
	system("cls");
	cout << "Nhap ten nguoi dung de tiep tuc hoac de trong de thoat" << endl;
	// khi có giao diện thì cancel sẽ được thay bằng nút bấm, nút bấm nhảy về
	cout << "Ten nguoi dung:"
	     << "\t";
	string str;
	getline(cin, str);

	if (str.empty()) return false;

	User_num = FindUserByName(UserData, str);
	return true;
}

void ShowRoleList(vector<User>& UserData, UserAccount& recordNum) {
	// show role just for in vector struct
	for (int Role_num = 0; Role_num < UserData[recordNum.User_num]
	                                    .AccountList[recordNum.Account_num]
	                                    .RoleId.size();
	     Role_num++) {

		int role = UserData[recordNum.User_num]
		             .AccountList[recordNum.Account_num]
		             .RoleId[Role_num] -
		           1;
		// number save in file from 1 to 3,
		// computer count from 0 to 2
		cout << LibraryRole[role].RoleName << ";\t";
	}
}

void ShowAccountList(vector<User>& UserData, int& User_num) {
	// show availabel account
	for (int Account_num = 0;
	     Account_num < UserData[User_num].AccountList.size();
	     Account_num++) {
		cout << left << setw(5) << Account_num + 1 << "\t";
		cout << UserData[User_num].AccountList[Account_num].AccId << "\t";

		UserAccount recordNum = {User_num, Account_num};
		ShowRoleList(UserData, recordNum);
		cout << endl;
	}
}

int AccountLoginPrompt(vector<User>& UserData, int& User_num) {
	system("cls");
	cout << "Chon tai khoan ban muon dang nhap (so): " << endl;
	cout << "De dung lai, xin nhap 0." << endl;

	ShowAccountList(
	  UserData,
	  User_num);    // show the account with no pass and active state

	cout << "Lua chon cua ban? ";
	int Choice;
	cin >> Choice;

	// error handler nedded: text input

	if (Choice == 0) return Choice;    // set to getline and empty? maybe later

	while (Choice > UserData[User_num].AccountList.size() || Choice < 0) {
		cout << "Tai khoan so " << Choice << " khong co, moi nhap lai: ";
		cin >> Choice;
	}

	string StringToCompare = UserData[User_num].AccountList[Choice - 1].AccId;
	if (ReadLock()) {    /// actually, readlock always return true
		// I have not specify the open file in another place
		// so checklock is still so big
		if (CheckLock(StringToCompare)) {
			cout << "Tai khoan nay hien dang bi khoa" << endl;
			cout << "Xin moi ban chon tai khoan khac" << endl;
			cout << "Bam Enter de thu lai" << endl;
			system("pause");
			Choice = AccountLoginPrompt(UserData, User_num);
			// run it again
			// de quy
		}
	}

	return Choice;
}

bool RightPassword(
  vector<User>& UserData,
  UserAccount& recordNum,
  int& Attemps) {
	system("cls");

	string AccountID =
	  UserData[recordNum.User_num].AccountList[recordNum.Account_num].AccId;

	cout << "Ban chon dang nhap vao: " << endl;
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
		LockAccount(AccountID);
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

	cout << AccountID << "\t";
	string str;
	getline(cin, str);

	if (str.empty()) {    // leave empty to go back to choose username
		Attemps = 0;
		return true;
	}
	else
		Attemps++;

	// cipher data?

	// check the f*@#$*& password
	// password not hashed yet
	string ThePassword =
	  UserData[recordNum.User_num].AccountList[recordNum.Account_num].Password;
	if (ThePassword != str) return false;
	return true;
}

void CreateLoggedInUser(vector<User>& UserData, UserAccount& recordNum) {
	CurrentUser.AccId =
	  UserData[recordNum.User_num].AccountList[recordNum.Account_num].AccId;
	CurrentUser.User_num    = recordNum.User_num;
	CurrentUser.Account_num = recordNum.Account_num;

	for (int Role_num = 0; Role_num < UserData[recordNum.User_num]
	                                    .AccountList[recordNum.Account_num]
	                                    .RoleId.size();
	     Role_num++) {    // to long for ya heh
		CurrentUser.RoleId.push_back(UserData[recordNum.User_num]
		                           .AccountList[recordNum.Account_num]
		                           .RoleId[Role_num]);
	}
	return;
}

bool LoggedIn(vector<User>& UserData) {

	//.....Still have no Idea how to make this smaller......

	int User_num = -1;
	// to track the user being run

	while (true) {
		if (UserLoginPrompt(UserData, User_num)) {
			// run login prompt
			// with arg User_num
			if (User_num == UserData.size()) {
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
			if (str == "y") {
				return false;
			}
			else
				continue;    // login prompt
		}
	}

	int Account_num =
	  AccountLoginPrompt(UserData, User_num) - 1;    // chose account
	if (Account_num == -1) return false;     // no account chosen
	//run cppcheck retrun error Reference to auto variable returned.
	UserAccount recordNum = {User_num,
	                         Account_num};    // save user place in vector

	// input password
	int Attemps = 0;
	while (!RightPassword(UserData, recordNum, Attemps))
		;
	// check right password or not
	// remember leave blank returns to login

	// the attemps must be > 1 if enter right or wrong
	// if attemps == 0, the str enter is empty, user choose the login name again

	if (Attemps == 0) return LoggedIn(UserData);
	// return login if left blank
	// attemps set to 0
	else
		CreateLoggedInUser(UserData, recordNum);
	// create the LoggedInUser data to store

	return true;
	//run cppcheck retrun error Reference to auto variable returned.
}