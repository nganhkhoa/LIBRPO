/*
 * @CreateTime: Jun 22, 2017 10:30 AM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 22, 2017 11:14 AM
 * @Description: Auto reject borrow submition
 */

#include <Utilities/Utilities.h>

using namespace std;
using json = nlohmann::json;

unsigned int FindCheckedPlace(unsigned int& this_submit) {
	json Submit              = readSubmitBorrow();
	json checked             = Submit.at("Checked");
	unsigned int num_checked = checked.size();
	for (unsigned int index = 0; index < num_checked; index++) {
		unsigned int submit = checked[index].at("Submit ID");
		if (submit == this_submit) return index;
	}
	return num_checked;    // this never happens, but warning so...
}

vector<unsigned int> GetSubmitIDPendingReceived() {
	json borrowLog = readBorrowLog();

	vector<unsigned int> submitid_list = {};

	unsigned int num_pending  = borrowLog.at("Accepted").at("Pending").size();
	unsigned int num_received = borrowLog.at("Accepted").at("Received").size();

	for (unsigned int index = 0; index < num_pending; index++) {
		unsigned int submitid =
		  borrowLog.at("Accepted").at("Pending")[index].at("Submit ID");
		submitid_list.push_back(submitid);
	}
	for (unsigned int index = 0; index < num_received; index++) {
		unsigned int submitid =
		  borrowLog.at("Accepted").at("Received")[index].at("Submit ID");
		submitid_list.push_back(submitid);
	}
	InsertionSort(submitid_list);
	return submitid_list;
}

bool AutoReject(string& ISBN, string& UserID) {
	vector<unsigned int> submitid_list = GetSubmitIDPendingReceived();
	unsigned int listsize              = submitid_list.size();

	json Submit = readSubmitBorrow();

	for (unsigned int index = 0; index < listsize; index++) {
		unsigned int this_submit   = submitid_list[index];
		unsigned int checked_place = FindCheckedPlace(this_submit);

		json submition   = Submit.at("Checked")[checked_place];
		string ISBN_data = submition.at("ISBN");
		if (ISBN_data != ISBN) continue;
		string UserID_data = submition.at("User");
		if (UserID_data == UserID) return true;
	}
	return false;
}