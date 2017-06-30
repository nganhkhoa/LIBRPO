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
	cout << "1\t"
	     << "Chuc nang nha suu tap" << endl;
	cout << "2\t"
	     << "Thoat" << endl;

	return ChoiceInput(2);
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