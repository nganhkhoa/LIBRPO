#include <CommonLib.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __unix
#include <termios.h>
#include <unistd.h>
#include <term.h>
#endif

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


void clearscreen() {
	#ifdef _WIN32
	system("cls");
	#endif

	#ifdef __unix
	system("tput clear");
	#endif
}

void pausescreen() {
	#ifdef _WIN32
	system("pause");
	#endif

	#ifdef __unix
	std::cout << "Press \'Return\' to end." << std::endl;
	std::cin.get();
	#endif
}