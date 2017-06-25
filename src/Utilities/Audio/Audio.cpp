/*
 * @CreateTime: Jun 25, 2017 8:33 AM
 * @Author: undefined
 * @Contact: undefined
 * @Last Modified By: undefined
 * @Last Modified Time: Jun 25, 2017 8:34 AM
 * @Description: Modify Here, Please
 */

#include <Utilities/Utilities.h>

using namespace std;

int AUDIOChoice() {
	clearscreen();
	int Choice;
	cout << "1\t"
	     << "Chuc nang doc gia sach noi" << endl;
	cout << "2\t"
	     << "Thoat" << endl;

	cout << "Moi ban chon: ";
	cin >> Choice;
	while (Choice < 0 || Choice > 2) {
		cout << "Lua chon khong co, moi ban chon lai: ";
		cin >> Choice;
	}

	return Choice;
}


void AUDIO() {
	while (true) {
		enum Choice
		{
			ChoiceANYTHING = 1,
			Exit
		};
		switch (AUDIOChoice()) {
			case ChoiceANYTHING: break;
			case Exit: return;
		}
	}
}