#include <Data/ReadDataJSON.h>

using namespace std;
using json = nlohmann::json;

bool ReadUserDataJSON() {
	ifstream userfile(FILEUser_focus_JSON, ios::in);

	if (!userfile.is_open()) {
		cout << "File userdata.json open failed" << endl;
		if (debug) system("pause");
		return false;
	}

	userfile >> UserDataJSON;
	return true;
}

bool UpdateUserDataJSON() {
	ofstream userfile(FILEUser_focus_JSON, ios::out);

	if (!userfile.is_open()) {
		cout << "File userdata.json open failed" << endl;
		if (debug) system("pause");
		return false;
	}

	userfile << UserDataJSON.dump(4);
	return true;
}

json readSignUp() {
	ifstream signupfile(FILESignUp_JSON, ios::in);
	json SignUp;

	if (!signupfile.is_open()) {
		cout << "File signup.json open failed" << endl;
		if (debug) system("pause");
		return NULL;
	}

	signupfile >> SignUp;
	return SignUp;
}

bool updateSignUp(json& SignUp) {
	ofstream signupfile(FILESignUp_JSON, ios::out);

	if (!signupfile.is_open()) {
		cout << "File signup.json open failed" << endl;
		if (debug) system("pause");
		return false;
	}

	signupfile << SignUp.dump(4);
	return true;
}

json readRejected() {
	ifstream rejectfile(FILERejected_JSON, ios::in);
	json Rejected = NULL;

	if (!rejectfile.is_open()) {
		cout << "File user_rejected.json open failed" << endl;
		if (debug) system("pause");
		return false;
	}

	rejectfile >> Rejected;
	return Rejected;
}

bool updateRejected(json& Rejected) {
	ofstream rejectfile(FILERejected_JSON, ios::out);

	if (!rejectfile.is_open()) {
		cout << "File rejected.json open failed" << endl;
		if (debug) system("pause");
		return false;
	}

	rejectfile << Rejected.dump(4);
	return true;
}