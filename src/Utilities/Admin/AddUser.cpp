/*
 * @CreateTime: Jun 18, 2017 10:03 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 18, 2017 10:03 PM
 * @Description: Xác nhận thêm người dùng mới
 */

#include <Utilities/Utilities.h>
#include <Data/ReadDataJSON.h>

using namespace std;
using json = nlohmann::json;
/**
 * Reverse the delete list to save list
 */
vector<unsigned int> SaveSignupRecord(vector<unsigned int>& signup_record) {

	json signup             = readSignUp();
	unsigned int num_signup = signup.size();

	vector<unsigned int> new_record_list = {};
	unsigned int record_count            = 0;

	for (unsigned int index = 0; index < num_signup; index++) {
		if (index == signup_record[record_count]) {
			record_count++;
			if (record_count == signup_record.size())
				break;
			else
				continue;
		}
		else {
			new_record_list.push_back(index);
		}
	}
	return new_record_list;
}

json UpdateSignUpData(vector<unsigned int>& signup_record) {

	json new_signup      = json::object();
	new_signup["SignUp"] = json::array();

	vector<unsigned int> new_record_list = SaveSignupRecord(signup_record);
	if (new_record_list.size() == 0) { return new_signup; }

	json signup = readSignUp();

	unsigned int num_signup   = signup.size();
	unsigned int record_count = 0;
	for (unsigned int index = 0; index < num_signup; index++) {
		if (index == new_record_list[record_count]) {

			json new_user = signup.at("SignUp")[index];
			new_signup.at("SignUp")[record_count++] = new_user;

			if (record_count == new_record_list.size())
				break;
			else
				continue;
		}
		else
			continue;
	}

	return new_signup;
}

unsigned int ValidateUser() {
	cout << "1.\t"
	     << "Dong y" << endl;
	cout << "2.\t"
	     << "Khong chap thuan" << endl;
	cout << "3.\t"
	     << "Thoat" << endl;

	unsigned int Choice = 0;
	cin >> Choice;

	while (Choice < 1 || Choice > 3) {
		cout << "Lua chon khong hop le" << endl;
		cout << "Moi ban nhap lai: ";
		cin >> Choice;
	}
	return Choice;
}

void ShowSignUpData(json& new_signup) {
	std::string Username      = new_signup.at("Username");
	std::string UserLastName  = new_signup.at("UserLastName");
	std::string UserFirstName = new_signup.at("UserFirstName");
	std::string Gender        = new_signup.at("Gender");
	std::string IDNumber      = new_signup.at("IDNumber");

	cout << "Ten nguoi dung: " << Username << endl;
	cout << "Ho va ten: " << UserFirstName << " " << UserLastName << endl;
	cout << "So CMND: " << IDNumber << endl;
	cout << "Gioi tinh: " << Gender << endl;
	return;
}

verify VerifyNewUser() {
	verify data;

	json SignUp_list = readSignUp();
	json Rejected    = readRejected();

	unsigned int num_signup = SignUp_list.at("SignUp").size();

	if (num_signup == 0) {
		cout << "Khong co du lieu dang ky moi" << endl;
		pausescreen();
		return data;
	}

	vector<unsigned int> signup_record = {};
	unsigned int num_user              = UserDataJSON.at("UserList").size();
	unsigned int num_rejected          = Rejected.at("Rejected").size();

	for (unsigned int index = 0; index < num_signup; index++) {
		clearscreen();

		json new_signup = SignUp_list.at("SignUp")[index];
		ShowSignUpData(new_signup);
		unsigned int choice = ValidateUser();

		if (choice == 3) {
			SignUp_list = UpdateSignUpData(signup_record);
			updateSignUp(SignUp_list);
			updateRejected(Rejected);
			UpdateUserDataJSON();
			return data;
		}

		if (choice == 1) {
			new_signup["First"]                        = true;
			new_signup.at("AccountList")[0].at("Lock") = false;
			UserDataJSON.at("UserList")[num_user++]    = new_signup;
			signup_record.push_back(index);
			data.add++;
		}
		else {
			Rejected.at("Rejected")[num_rejected++] = new_signup;
			signup_record.push_back(index);
			data.reject++;
		}
	}

	cout << "Khong con du lieu dang ky moi" << endl;
	cout << "Bam enter de quay ve" << endl;
	pausescreen();

	SignUp_list = UpdateSignUpData(signup_record);
	updateSignUp(SignUp_list);
	updateRejected(Rejected);
	UpdateUserDataJSON();
	return data;
}

void AddUser() {
	verify data = VerifyNewUser();
	cout << "Ban da them vao " << data.add << " nguoi dung" << endl;
	cout << "Ban da loai bo " << data.reject << " don dang ky" << endl;
	pausescreen();
	return;
}