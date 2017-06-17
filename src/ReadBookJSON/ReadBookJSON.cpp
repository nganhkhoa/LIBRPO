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