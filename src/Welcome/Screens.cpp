/*
 * @CreateTime: Jun 19, 2017 2:31 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 19, 2017 2:35 PM
 * @Description: Screens on welcome
 */

#include <Welcome/Screens.h>

#include <Welcome/Welcome.h>
#include <Login/Login.h>
#include <AccountChoose/AccountChoose.h>
#include <Utilities/Utilities.h>
#include <Browse/Browse.h>
#include <Setting/Setting.h>
#include <SignUp/SignUp.h>

#include <History/History.h>

using namespace std;

void NotYetLogInScreen() {
	enum WelcomeChoice
	{
		LoginUser = 1,
		SignUpUser,
		BrowseOption,
		Manual,
		Exit
	};

	// welcome is an int function return choice
	switch (Welcome()) {
		case LoginUser:
			cin.ignore();                              // for inputing string
			CurrentUser.Active = Login();              // login system
			if (CurrentUser.Active) LoginHistory();    // login history
			break;
		case SignUpUser:
			cin.ignore();
			SignUp();
			break;
		case BrowseOption:
			// without loging in, the user can still browse
			// we use CurrentUser.Active to know if loggin or not
			// if no, we would not let them borrow, buy?
			Browse();
			pausescreen();
			break;
		case Manual:
			// Help();
			break;
		case Exit: {    // normal exit
			cout << "Ban muon thoat? (y/n) ";
			cin.ignore();
			string Answer;
			getline(cin, Answer);
			if (Answer != "y")
				break;
			else
				exit(0);    // terminate the program
		}
		default: break;
	}
}

void UserLogInScreen() {
	enum WelcomeUserChoice
	{
		LogoutUser = 1,
		SettingUser,
		ChooseAccount,
		CreateAccount,
		BrowseOption,
		Manual,
		Exit
	};
	switch (WelcomeUser()) {
		case LogoutUser: {    // as said change active to false
			cout << "Ban muon dang xuat? (y/n) ";
			cin.ignore();
			string Answer;
			getline(cin, Answer);
			if (Answer == "y") {
				LogoutHistory();    // logout history
			}
			break;
		}
		case SettingUser: Setting(); break;
		case ChooseAccount: AccountChoose(); break;
		case CreateAccount:
			// CreateAccount();
			break;
		case BrowseOption:
			Browse();
			pausescreen();
			break;
		case Manual:
			// Help();
			break;
		case Exit: {
			cout << "Ban muon thoat? (y/n) ";
			cin.ignore();
			string Answer;
			getline(cin, Answer);
			if (Answer != "y")
				break;
			else {
				// logout what ever user is logging on
				LogoutHistory();
				exit(0);    // terminate the program
			}
		}
		default: break;
	}
}

void AccountLogInScreen() {
	enum WelcomeAccountChoice
	{
		LogoutAccountChoice = 1,
		SettingUser,
		UtilitiesUser,
		BrowseOption,
		Manual,
		Exit
	};
	switch (WelcomeAccount()) {
		case LogoutAccountChoice: {
			cout << "Chi dang xuat ban khoi tai khoan" << endl;
			cout << "Ban muon dang xuat? (y/n) ";
			cin.ignore();
			string Answer;
			getline(cin, Answer);
			if (Answer == "y") { LogoutAccount(); }
			break;
		}
		case SettingUser: Setting(); break;
		case UtilitiesUser: Utilities(); break;
		case BrowseOption:
			Browse();
			pausescreen();
			break;
		case Manual:
			// Help();
			break;
		case Exit: {
			cout << "Ban muon thoat? (y/n) ";
			cin.ignore();
			string Answer;
			getline(cin, Answer);
			if (Answer != "y")
				break;
			else {
				// logout
				LogoutHistory();
				exit(0);    // terminate the program
			}
		}
		default: break;
	}
}