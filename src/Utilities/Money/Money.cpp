/*
 * @CreateTime: Jun 18, 2017 9:58 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: undefined
 * @Last Modified Time: Jun 18, 2017 9:59 PM
 * @Description: Màn hình độc giả
 */

#include <Utilities/Utilities.h>

using namespace std;

int MoneyChoice() {
	clearscreen();
	cout << "1\t"
	     << "Nap tien" << endl;
	cout << "2\t"
	     << "Tinh tien" << endl;
	cout << "3\t"
	     << "Quay ve" << endl;

	return ChoiceInput(3);
}


void Money() {
	while (true) {
		enum Choice
		{
			ChoiceCharge = 1,
			ChoicePay,
			Exit
		};
		switch (MoneyChoice()) {
			case ChoiceCharge:
				cin.ignore();
				Charge();
				break;
			case ChoicePay: break;
			case Exit: return;
		}
	}
}