#include <Utilities/Utilities.h>
#include <SignUp/SignUp.h>

using namespace std;
using json = nlohmann::json;

void FineLateReturn(unsigned int& dayslate) {

	if (dayslate == 0) return;

	clearscreen();
	cout << "Ban da bi tru tien khi khong tra sach dung han" << endl;
	cout << "Voi moi ngay nop tre ban bi tru di " << FINE_MONEY << " VND"
	     << endl;
	cout << "So tien nay se duoc tru di trong tai khoan cua ban" << endl;

	double fine = dayslate * FINE_MONEY;
	double userbalance =
	  UserDataJSON.at("UserList")[CurrentUser.User_num].at("Balance");
	userbalance -= fine;

	if (userbalance < 0) {
		cout << "Tai khoan ban hien da khong con tien" << endl;
		cout << "Ban hay nap tien vao tai khoan," << endl;
		cout << "Chung toi se khoa quyen su dung cua ban lai" << endl;
		LockAllAccount();
	}

	UserDataJSON.at("UserList")[CurrentUser.User_num].at("Balance") =
	  userbalance;
	pausescreen();
}

bool CalculateFine(int& submitid) {
	json borrowLog = readBorrowLog();

	unsigned int num_return = borrowLog.at("Accepted").at("Returned").size();
	int submit_place        = -1;

	for (unsigned int index = 0; index < num_return; index++) {
		json this_submition = borrowLog.at("Accepted").at("Returned")[index];
		if (this_submition.at("Submit ID") == submitid) {
			submit_place = index;
			break;
		}
	}

	json this_submition = borrowLog.at("Accepted").at("Returned")[submit_place];
	string borrowdate   = this_submition.at("Returned Date");
	string returndate   = this_submition.at("Received Date");

	int borrowdate_int = stoi(borrowdate);
	int returndate_int = stoi(returndate);

	double days_elapse = returndate_int - borrowdate_int;
	days_elapse /= 3600;

	int dayslate = days_elapse - 7 * MAX_WEEK_BORROW;

	if (dayslate > 0) { return dayslate; }
	else
		return 0;
}