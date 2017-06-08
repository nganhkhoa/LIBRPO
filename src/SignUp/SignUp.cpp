#include <SignUp.h>


using namespace std;
using json = nlohmann::json;

bool UserExist(string& NewCreation_username) {

	json& userdata = UserDataJSON;


	unsigned int num_user = userdata.at("UserList").size();
	unsigned int num_user_signup = userdata.at("SignUp").size();

	for (unsigned int index = 0; index < num_user; index++) {
		string username = userdata.at("UserList")[index].at("Username");
		if (NewCreation_username == username)
			return true;
	}

	for (unsigned int index = 0; index < num_user_signup; index++) {
		string username = userdata.at("SignUp")[index].at("Username");
		if (NewCreation_username == username)
			return true;
	}

	return false;
}

bool ValidateNew(NewUser& NewCreation) {

	if (NewCreation.UserLastName == "") return false;
	if (NewCreation.UserFirstName == "") return false;
	if (NewCreation.IDNumber == "") return false;

	return true;
}


void ExpandSignUp(NewUser& NewCreation) {
	return;
}


bool SignUpUser(NewUser& NewCreation) {

	cout << "Sau day la mau dang nhap, ban hay dien vao" << endl;
	cout << "Neu ban khong muon dang nhap nua, hay bo trong" << endl;



	cout << "De bat dau, ban hay cho chung toi biet ban la ai?" << endl;
	cout << "Ho: "; getline(cin, NewCreation.UserLastName);
	cout << "Ten: "; getline(cin, NewCreation.UserFirstName);
	cout << "CMDN: "; getline(cin, NewCreation.IDNumber);

	cout << "_________________________________________________" << endl;

	cout << "Gioi tinh: " << endl;
	cout << "           1. Nam" << endl;
	cout << "           2. Nu" << endl;
	cout << "           3. Trong" << endl;
	int Choice = 0;
	cout << "Chon: "; cin >> Choice;

	while (Choice < 1 || Choice > 3) {
		cout << "Ban chon khong hop le," << endl;
		cout << "Vui long chon lai" << endl;
		cout << "Lua chon moi: "; cin >> Choice;
	}

	cin.ignore();
	cout << "Ten dang nhap cua ban: "; getline(cin, NewCreation.Username);

		while (UserExist(NewCreation.Username)) {
			cout << "Ten dang nhap ton tai" << endl;
			cout << "Xin moi ban chon lai ten dang nhap khac" << endl;
			cout << "De khong tiep tuc, ban hay de trong" << endl;
			cout << "Ten dang nhap moi: "; getline(cin, NewCreation.Username);

			if (NewCreation.Username == "") return false;
		}

	if(!ValidateNew(NewCreation)) {
		cout << "Mau khong hop le, moi ban thu lai" << endl;
		//...
		return false;
	}

	cout << "Phan dang nhap da ket thuc," << endl;
	cout << "Tuy nhien ban co the tiep tuc dien thong tin khong bat buoc" << endl;
	cout << "De tiep tuc dien thong tin khong bat buoc, ban nhap 1" << endl;
	cout << "De dang ky nhanh, ban nhap 2" << endl;

	cout << "Lua chon: "; cin >> Choice;

	while (Choice < 1 || Choice > 2) {
		cout << "Ban chon khong hop le," << endl;
		cout << "Vui long chon lai" << endl;
		cout << "Lua chon moi: "; cin >> Choice;
	}

	if (Choice == 1) ExpandSignUp(NewCreation);
	return true;
}


void SignUp() {
	system("cls");
	
	cout << "Ban muon tao tai khoan moi?(y/n) " << endl;
	string Answer = ""; 
	getline(cin, Answer);

	if (Answer != "y") return;

	NewUser NewCreation;
	if (!SignUpUser(NewCreation)) return;

	if(!add_success(NewCreation)) {
		cout << "Rat tiec, loi da xay ra" << endl;
		cout << "Ban vui long thu lai sau" << endl;
		system("pause");
		return;
	}

	//system("pause");
	return;
}