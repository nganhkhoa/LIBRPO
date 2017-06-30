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
	cout << "1\t"
	     << "Chuc nang doc gia phim tu lieu" << endl;
	cout << "2\t"
	     << "Thoat" << endl;

	return ChoiceInput(2);
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