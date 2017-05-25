#include <ReadData.h>

using namespace std;

bool ReadLock() {
	/*
	ifstream lockfile(FILELock);
	if (!lockfile.is_open()) return false;
	return true;
	//*/
	return true;
}

bool CheckLock(string& StringToCompare) {
	ifstream lockfile(FILELock);
	if (!lockfile.is_open()) {
		cout << "Khong mo duoc file lock.txt" << endl;
		system("pause");
		return true;
	}


	string str;
	while (getline(lockfile, str)) {
		if (str.empty()) continue;

		str = TrimString(str);
		if (StringToCompare == str) {
			lockfile.close();
			return true;
		}
	}
	lockfile.close();
	return false;
}