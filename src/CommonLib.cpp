/*
 * @CreateTime: Jun 18, 2017 9:56 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 18, 2017 9:56 PM
 * @Description: Các hàm nhỏ dùng nhiều chỗ
 */


#include <CommonLib.h>

using namespace std;

void Help() {
	clearscreen();
	cout << right << setw(10) << "" << left << setw(100) << "" << endl;
	pausescreen();
}

string TrimString(string& str) {
	char* StringModified = new char[str.length()];
	int beginLetter      = 0;
	// remove white space at begining
	while (str[beginLetter] == ' ')
		beginLetter++;
	int letter = 0;
	for (unsigned int index = beginLetter; index < str.length(); index++) {
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

int ChoiceInput(int max) {
	int Choice = 0;
	cout << "Lua chon chuc nang: ";
	cin >> Choice;
	while (Choice > max || Choice < 1) {
		cout << "Chuc nang khong co, moi nhap lai: ";
		cin >> Choice;
	}
	return Choice;
}


string HidePassword() {
	string pwd;

#ifdef _WIN32
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode    = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

	getline(cin, pwd);

	SetConsoleMode(hStdin, mode);
#endif

#ifdef __unix
	termios oldt;
	tcgetattr(STDIN_FILENO, &oldt);
	termios newt = oldt;
	newt.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	getline(cin, pwd);

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif

	cout << endl;
	return pwd;
}


void clearscreen() {    // system is evil
#ifdef _WIN32
	system("cls");
#endif

#ifdef __unix
	system("clear");
#endif
}

void pausescreen() {    // system is evil
#ifdef _WIN32
	system("pause");
#endif

#ifdef __unix
	std::cout << "Press any key to continue" << std::endl;
	std::cin.get();
#endif
}


// swap function for use
void Swap(unsigned int* Num1, unsigned int* Num2) {
	unsigned int Temp = *Num1;
	*Num1             = *Num2;
	*Num2             = Temp;
}

void InsertionSort(vector<unsigned int>& NumList) {
	for (int i = 1; i < (int) NumList.size(); i++) {
		if (NumList[i - 1] < NumList[i])
			continue;
		else {
			int NumSort = i;
			int j       = NumSort - 1;
			while (NumList[j] > NumList[NumSort] && j > -1) {
				Swap(&NumList[NumSort], &NumList[j]);
				NumSort = j--;
			}
		}
	}
}