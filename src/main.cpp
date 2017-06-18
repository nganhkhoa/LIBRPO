/*
*	Last update: 09/06/2017, 21:39:00
*	Created on 30/4/2017, ‏‎11:59:37
*	Created by Luibo
*	LIBPRO LIBRARY SYSTEM
*	Version: 0.0.4
*/

/*
        DESCRIPTION
    //The program description is
    //to be placed here
    The LIBPRO library management system
*/

/*
        TO DO LIST
    //Things need to be done
    //Help yourself

        User management
    ~~Read data~~
    ~~Login screen with username /no password~~
    ~~Choose account after username insert correct~~
    ~~Input password and check~~
    ~~Change password~~
    New book notification

        Find book
    ~~Find with one word~~
    ~~Find with multiple word~~
    Find with string metric
    Find using Levenshtein distance
    Choose book to put to cart
    Remove book from cart
    ~~!!!Split page~~

        Borrow book
    ~~Number of books~~
    ~~Number of books borrowing~~ // one only
    Borrow book(s)
    Return book(s)
    Fine if return late

        History
    ???????????????
    ~~Log in and log out~~


                UserScope
Reader
    ~~Find~~
    ~~Return~~

Thu thu
    ???????????????????????

Manager
    ~~Add user~~
    Delete user
    Modify user
    Search user
    Reset password for user
    Look and unlock user


*/

/*
        FUNCTION
    //Keep track with function to work

*/


#include <CommonLib.h>

#include <Book/ReadBookJSON.h>
#include <Data/ReadDataJSON.h>

#include <Welcome/Welcome.h>
#include <Login/Login.h>
#include <AccountChoose/AccountChoose.h>
#include <Utilities/Utilities.h>
#include <Browse/Browse.h>
#include <Setting/Setting.h>
#include <SignUp/SignUp.h>

#include <History/History.h>

using namespace std;

int main() {
	srand(time(NULL));
	clearscreen();


	//
	// ─── READ DATA FROM FILE
	// ────────────────────────────────────────────────────────
	//

	if (!ReadUserDataJSON()) {
		// for now we put it here
		// but after, we put in login
		// only when the user login
		// we run the file, to release memory
		cout << "Error in reading user data" << endl;
		pausescreen();
		return -1;
	}
	if (debug) {
		cout << UserDataJSON.dump(4) << endl;
		pausescreen();
		clearscreen();
	}

	// ────────────────────────────────────────────────────────────────────────────────


	//
	// ─── READ BOOK FROM FILE
	// ────────────────────────────────────────────────────────
	//

	if (!ReadBookDataJSON()) {
		// for now we put it here
		// but after, we put in login
		// only when the user login
		// we run the file, to release memory
		cout << "Error in reading book data" << endl;
		pausescreen();
		return -1;
	}
	if (debug) {
		cout << BookDataJSON.dump(4) << endl;
		pausescreen();
		clearscreen();
	}
	// ────────────────────────────────────────────────────────────────────────────────

	// check log file to see who shutdown without logging out
	// if ... else
	// CurrentUser.Active = false;

	// Create an active user
	// if is active, then there is someone logging in
	// if not active, then show the general welcome
	// this user also has
	// usernum and accountnum to know who is who
	// maybe cart?????

	while (true) {                       // also run welcome until exit
		while (!CurrentUser.Active) {    // if not active, show general welcome
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
					cin.ignore();                    // for inputing string
					CurrentUser.Active = Login();    // login system
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
						return 0;    // terminate the program
				}
				default: break;
			}
		}
		while (CurrentUser.Active && CurrentUser.Account_num == -1) {
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
						return 0;    // terminate the program
					}
				}
				default: break;
			}
		}
		while (CurrentUser.Active && CurrentUser.Account_num != -1) {
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
						return 0;    // terminate the program
					}
				}
				default: break;
			}
		}
	}
}