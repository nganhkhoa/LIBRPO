#include <Book/ReadBookJSON.h>

using namespace std;

bool ReadBookDataJSON() {
	ifstream bookfile(FILEBookJSON, ios::in);

	if (!bookfile.is_open()) {
		cout << "File bookdata.json open failed" << endl;
		if (debug) system("pause");
		return false;
	}

	bookfile >> BookDataJSON;
	return true;
}