/*
 * @CreateTime: Jun 25, 2017 8:31 AM
 * @Author: undefined
 * @Contact: undefined
 * @Last Modified By: undefined
 * @Last Modified Time: Jun 25, 2017 8:41 AM
 * @Description: Modify Here, Please
 */

#include <Utilities/Utilities.h>

using namespace std;

int NHASUUTAMChoice() {
	clearscreen();
	int Choice;
	cout << "1\t"
	     << "Chuc nang nha suu tap" << endl;
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


void NHASUUTAM() {
	while (true) {
		enum Choice
		{
			ChoiceANYTHING = 1,
			Exit
		};
		switch (NHASUUTAMChoice()) {
			case ChoiceANYTHING: break;
			case Exit: return;
		}
	}
}