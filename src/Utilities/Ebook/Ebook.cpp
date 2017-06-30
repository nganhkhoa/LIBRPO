/*
 * @CreateTime: Jun 25, 2017 8:35 AM
 * @Author: undefined
 * @Contact: undefined
 * @Last Modified By: undefined
 * @Last Modified Time: Jun 25, 2017 8:41 AM
 * @Description: Modify Here, Please
 */


#include <Utilities/Utilities.h>

using namespace std;

int EBOOKChoice() {
	clearscreen();
	cout << "1\t"
	     << "Chuc nang doc gia sach dien tu" << endl;
	cout << "2\t"
	     << "Thoat" << endl;

	return ChoiceInput(2);
}


void EBOOK() {
	while (true) {
		enum Choice
		{
			ChoiceANYTHING = 1,
			Exit
		};
		switch (EBOOKChoice()) {
			case ChoiceANYTHING: break;
			case Exit: return;
		}
	}
}