/*
 * @CreateTime: Jun 25, 2017 8:35 AM
 * @Author: undefined
 * @Contact: undefined
 * @Last Modified By: undefined
 * @Last Modified Time: Jun 25, 2017 8:35 AM
 * @Description: Modify Here, Please
 */

#include <Utilities/Utilities.h>

using namespace std;

int DOCUMENTARYChoice() {
	clearscreen();
	int Choice;
	cout << "1\t"
	     << "Chuc nang doc gia phim tu lieu" << endl;
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


void DOCUMENTARY() {
	while (true) {
		enum Choice
		{
			ChoiceANYTHING = 1,
			Exit
		};
		switch (DOCUMENTARYChoice()) {
			case ChoiceANYTHING: break;
			case Exit: return;
		}
	}
}