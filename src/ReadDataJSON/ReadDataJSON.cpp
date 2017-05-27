#include <ReadDataJSON.h>

using namespace std;

bool ReadUserDataJSON() {
	ifstream userfile(FILEUserJSON, ios::in);

	if (!userfile.is_open()) {
		cout << "File userdata.json open failed" << endl;
		if (debug) system("pause");
		return false;
	}

	userfile >> UserDataJSON;
	return true;
}

bool UpdateUserDataJSON() {
	ofstream userfile(FILEUserJSON, ios::out);

	if (!userfile.is_open()) {
		cout << "File userdata.json open failed" << endl;
		if (debug) system("pause");
		return false;
	}

	userfile << UserDataJSON.dump(4);
	return true;
}