/*
 * @CreateTime: Jun 18, 2017 10:07 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 18, 2017 10:07 PM
 * @Description: Xác nhận mật khẩu cũ và đổi mật khẩu mới
 */

#include <Setting/Setting.h>
#include <Data/ReadDataJSON.h>

using namespace std;

bool ComparePassword(string& VerifyPassword) {
	// cypher here

	string OldPassword =
	  UserDataJSON.at("UserList")[CurrentUser.User_num].at("Password");

	if (OldPassword == VerifyPassword) return true;
	return false;
}


bool ChangePassword() {    // ham thi dai ma toan la chu
	while (true) {
		clearscreen();
		cout << "Sau day he thong se yeu cau ban nhap mat ma cu" << endl;
		cout << "Neu ban khong muon thay doi thi hay de trong" << endl;
		cout << "Nhap password cu cua ban: ";
		string pwd_entered = HidePassword();
		string NewPassword;

		if (pwd_entered.empty()) {
			cout << "Ban muon thoat? (y/n) ";
			string Answer;
			getline(cin, Answer);
			if (Answer != "y") { continue; }
			else
				return false;
		}

		if (!ComparePassword(pwd_entered)) {
			cout << "Ban da nhap mat khau sai" << endl;
			cout << "Neu ban khong nho mat khau, hay lien he ban quan tri"
			     << endl;
			cout << "de duoc cap lai mat khau moi" << endl;

			/*
			cout << "Ban con " << Attemps << " lan thu nua" << endl;
			cout << "Tai khoan se bi khoa neu nhap sai qua " << MAX_ATTEMPTS <<
			"
			lan" << endl;
			//*/

			cout << "Ban muon thu lai? (y/n) ";

			string Answer;
			getline(cin, Answer);
			if (Answer == "y") { continue; }
			else
				return false;
		}

		while (true) {

			cout << "Ban hay nhap mat khau moi: ";
			NewPassword = HidePassword();

			cout << "Moi ban nhap lai mat khau moi: ";
			pwd_entered = HidePassword();

			if (NewPassword != pwd_entered) {
				cout << "Mat khau moi khong trung" << endl;
				cout << "Ban muon thu lai? (y/n): ";
				string Answer;
				getline(cin, Answer);

				if (Answer == "y")
					continue;

				else
					return false;
			}

			cout << "De tiep tuc bam enter" << endl;
			pausescreen();
			break;
		}

		if (UserDataJSON.at("UserList")[CurrentUser.User_num].at("First")) {
			UserDataJSON.at("UserList")[CurrentUser.User_num].at("First") =
			  false;
		}

		// Cypher password here

		UserDataJSON.at("UserList")[CurrentUser.User_num].at("Password") =
		  NewPassword;

		if (!UpdateUserDataJSON()) {
			cout << "Cap nhat khong thanh cong" << endl;
			cout << "Bi loi mong quy khach thong cam" << endl;
			cout << "Bam enter de quay lai lua chon" << endl;
			pausescreen();
			return false;
		}
		cout << "Cap nhat thanh cong" << endl;
		cout << "Bam enter de quay ve" << endl;
		pausescreen();
		return true;
	}
}