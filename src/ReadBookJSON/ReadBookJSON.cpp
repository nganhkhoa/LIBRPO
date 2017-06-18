/*
 * @CreateTime: Jun 18, 2017 10:08 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 18, 2017 10:08 PM
 * @Description: Đọc và ghi dữ liệu về sách
 */

#include <Book/ReadBookJSON.h>

using namespace std;

bool ReadBookDataJSON() {
	ifstream bookfile(FILEBookJSON, ios::in);

	if (!bookfile.is_open()) {
		cout << "File bookdata.json open failed" << endl;
		if (debug) pausescreen();
		return false;
	}

	bookfile >> BookDataJSON;
	return true;
}

bool UpdateBookDataJSON() {
	ofstream bookfile(FILEBookJSON, ios::out);

	if (!bookfile.is_open()) {
		cout << "File bookdata.json open failed" << endl;
		if (debug) pausescreen();
		return false;
	}

	bookfile << BookDataJSON.dump(4);
	return true;
}