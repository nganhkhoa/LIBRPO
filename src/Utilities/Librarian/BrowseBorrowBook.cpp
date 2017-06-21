/*
 * @CreateTime: Jun 18, 2017 10:01 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 18, 2017 10:01 PM
 * @Description: Duyệt các yêu cầu mượn sách
 *
 * Còn thiếu: Các thư gửi bị trùng, cần được từ chối tự động
 *
 */

#include <Utilities/Utilities.h>
#include <Find/Find.h>

using namespace std;
using json = nlohmann::json;


void updateBorrowLog(unsigned int& submitid, bool accepted) {
	json borrowLog = readBorrowLog();
	if (borrowLog == NULL)
		;

	json borrowrecord         = json::object();
	borrowrecord["Submit ID"] = submitid;

	string TODAY = "";
	time_t now   = time(NULL);
	TODAY        = to_string(now);

	borrowrecord["Browsed Date"]          = TODAY;
	borrowrecord["Permission Granted by"] = CurrentUser.UserID;

	if (accepted) {
		unsigned int accepted_num =
		  borrowLog.at("Accepted").at("Pending").size();
		borrowLog.at("Accepted").at("Pending")[accepted_num] = borrowrecord;
	}
	else {
		unsigned int rejected_num = borrowLog.at("Rejected").size();
		borrowLog.at("Rejected")[rejected_num] = borrowrecord;
	}

	return updateBorrowLog(borrowLog);
}


void RejectSubmit(json& Submit, unsigned int& submit_index) {
	unsigned int rejected =
	  Submit.at("Submition")[submit_index].at("Submit ID");
	updateBorrowLog(rejected, false);
}
void AcceptSubmit(json& Submit, unsigned int& submit_index) {
	unsigned int accepted =
	  Submit.at("Submition")[submit_index].at("Submit ID");
	updateBorrowLog(accepted, true);
}
bool CheckedSubmition(json& Submit, unsigned int& submit_index_delete) {
	json new_data         = json::object();
	new_data["Submition"] = json::array();
	new_data["Checked"]   = Submit.at("Checked");

	json delete_data = Submit.at("Submition")[submit_index_delete];
	bool deleted     = false;

	unsigned int num_submit = Submit.at("Submition").size();
	for (unsigned int submit_index = 0; submit_index < num_submit;
	     submit_index++) {

		if (submit_index == submit_index_delete) {
			deleted                             = true;
			unsigned int checked_num            = new_data.at("Checked").size();
			new_data.at("Checked")[checked_num] = delete_data;
			continue;
		}

		if (!deleted) {
			new_data.at("Submition")[submit_index] =
			  Submit.at("Submition")[submit_index];
		}
		else {
			new_data.at("Submition")[submit_index - 1] =
			  Submit.at("Submition")[submit_index];
		}
	}

	return updateSubmitBorrow(new_data);
}


unsigned int ActionSubmit() {
	cout << "Ban muon cho nguoi dung muon?" << endl;
	cout << "1.\t Co" << endl;
	cout << "2.\t Khong" << endl;
	cout << "3.\t Thoat" << endl;

	int Choice = 0;
	cin >> Choice;

	while (Choice < 0 || Choice > 3) {
		cout << "Lua chon khong ton tai" << endl;
		cout << "Moi ban chon lai: ";
		cin >> Choice;
	}
	return (unsigned int) Choice;
}


void ShowSubmitInfo(unsigned int& book_place, unsigned int& user_place) {

	string title = BookDataJSON.at("BookLibrary")[book_place].at("Title");
	unsigned int quanlity =
	  BookDataJSON.at("BookLibrary")[book_place].at("BookNumber");
	unsigned int borrowed =
	  BookDataJSON.at("BookLibrary")[book_place].at("Borrowed");

	cout << "Ten sach:" << endl;
	cout << "\t" << title << endl;
	cout << "So luong: " << quanlity << endl;
	cout << "Dang muon: " << borrowed << endl;
	cout << "Con lai: " << quanlity - borrowed << endl;

	string firstname =
	  UserDataJSON.at("UserList")[user_place].at("UserFirstName");
	string lastname =
	  UserDataJSON.at("UserList")[user_place].at("UserLastName");
	string username = UserDataJSON.at("UserList")[user_place].at("Username");
	string occupation =
	  UserDataJSON.at("UserList")[user_place].at("Occupation");

	cout << "___________________________________" << endl;
	cout << "Nguoi muon muon sach nay: " << endl;
	cout << firstname << " " << lastname << endl;
	cout << "Ten nguoi dung: " << username << endl;
	cout << "Nghe nghiep: " << occupation << endl;
	cout << "___________________________________" << endl;
}

void ValidateSubmition() {
	json Submit             = readSubmitBorrow();
	unsigned int num_submit = Submit.at("Submition").size();
	for (unsigned int submit_index = 0; submit_index < num_submit;
	     submit_index++) {

		clearscreen();

		string ISBN   = Submit.at("Submition")[submit_index].at("ISBN");
		string UserID = Submit.at("Submition")[submit_index].at("User");

		unsigned int book_place = FindBookIndex(ISBN);
		unsigned int user_place = FindUserID(UserID);

		ShowSubmitInfo(book_place, user_place);
		unsigned int action = ActionSubmit();
		if (action == 3) return;

		if (action == 1)
			AcceptSubmit(Submit, submit_index);
		else {
			RejectSubmit(Submit, submit_index);
			// NotifyUser(Submit, submit_index);
		}

		if (!CheckedSubmition(Submit, submit_index)) {
			cout << "Khong cap nhat thanh cong" << endl;
			cout << "Bam enter de quay ve" << endl;
			pausescreen();
			return;
		}
		Submit     = readSubmitBorrow();
		num_submit = Submit.at("Submition").size();
		submit_index--;
	}

	cout << "Khong con du lieu muon sach moi" << endl;
	cout << "Bam enter de quay ve" << endl;
	pausescreen();
	return;
}


void BrowseBorrowBook() {
	clearscreen();

	json Submit = readSubmitBorrow();

	if (Submit == NULL) {
		cerr << "Khong load duoc du lieu muon sach" << endl;
		pausescreen();
		return;
	}

	if (Submit.at("Submition").size() == 0) {
		cout << "Khong co yeu cau muon sach moi" << endl;
		cout << "Ban enter de quay ve" << endl;
		pausescreen();
		return;
	}

	ValidateSubmition();
	return;
}