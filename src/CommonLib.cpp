#include <CommonLib.h>

using namespace std;

void Help() {
	cout << right << setw(10) << "" << left << setw(100) << "" << endl;
}

string TrimString(string& str) {
	char* StringModified = new char[str.length()];
	int beginLetter      = 0;
	// remove white space at begining
	while (str[beginLetter] == ' ')
		beginLetter++;
	int letter = 0;
	for (int index = beginLetter; index < str.length(); index++) {
		if (str[index] == ' ') {
			StringModified[letter++] = ' ';
			while (str[index + 1] == ' ') {
				index++;
			}
			if (str[index + 1] == '\0') {
				StringModified[letter - 1] = '\0';
				break;
			}
		}
		else {
			StringModified[letter++] = str[index];
			if (str[index + 1] == '\0') {
				StringModified[letter] = '\0';
				break;
			}
		}
	}
	string NewString(StringModified);
	return NewString;
}