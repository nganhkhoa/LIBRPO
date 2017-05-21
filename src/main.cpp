/*
*	Last update: 21/5/2017, 16:47:00
*	Created on 30/4/2017, ‏‎11:59:37
*	Created by Luibo
*	LIBPRO LIBRARY SYSTEM
*	Version: 0.0.2
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
    Find with one word
    Find with multiple word
    Find with string metric
    Find using Levenshtein distance
    Choose book to put to cart
    Remove book from cart
    ~~!!!Split page~~

        Borrow book
    Number of books
    Number of books borrowing
    Borrow book(s)
    Return book(s)
    Fine if return late

        History
    ???????????????
    ~~Log in and log out~~


                UserScope
Reader
    ~~Find~~
    Return

Thu thu
    ???????????????????????

Manager
    Add user
    Delete user
    Modify user
    Search user
    Reset password for user
    Look and unlock user


*/

/*
        FUNCTION
    //Keep track with function to work
    bool ReadData(vector<User>&, vector<AccountRoleMap>&)
    int Welcome(vector<User>&, vector<AccountRoleMap>&);
    int WelcomeUser(vector<User>&, vector<AccountRoleMap>&, LoggedInUser&);
*/


#include <CommonLib.h>
#include <Find.h>

#include <ReadBook.h>
#include <ReadData.h>

#include <Welcome.h>
#include <Login.h>
#include <Utilities.h>
#include <Browse.h>
#include <Setting.h>

#include <History.h>

using namespace std;

int main() {
	system("cls");
	vector<User> UserData;
	vector<Book> BookData;
	bool debug = true;

	//
	// ─── READ DATA FROM FILE
	// ────────────────────────────────────────────────────────
	//

	if (!ReadData(UserData, debug)) {
		// for now we put it here
		// but after, we put in login
		// only when the user login
		// we run the file, to release memory
		cout << "Error in reading user data" << endl;
		system("pause");
		return -1;
	}
	if (debug) system("pause");
	// ────────────────────────────────────────────────────────────────────────────────


	//
	// ─── READ BOOK FROM FILE
	// ────────────────────────────────────────────────────────
	//

	if (!ReadBook(BookData, debug)) {
		// we always read books
		// maybe?
		cout << "Error in reading book data" << endl;
		system("pause");
		return -2;
	}
	if (debug) system("pause");
	// ────────────────────────────────────────────────────────────────────────────────


	LoggedInUser CurrentUser;
	CurrentUser.Active = false;

	// Create an active user
	// if is active, then there is someone logging in
	// if not active, then show the general welcome
	// this user also has
	// usernum and accountnum to know who is who
	// maybe cart?????

	while (true) {                       // also run welcome until exit
		while (!CurrentUser.Active) {    // if not active, show general welcom
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
					cin.ignore();                     // for inputing string
					CurrentUser = Login(UserData);    // login system
					if (CurrentUser.Active)
						LoginHistory(CurrentUser);    // login history
					break;
				case SignUpUser:
					// SignUp();
					break;
				case BrowseOption:
					// without loging in, the user can still browse
					// we use CurrentUser.Active to know if loggin or not
					// if no, we would not let them borrow, buy?
					Browse(CurrentUser, BookData);
					system("pause");
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
		while (CurrentUser.Active) {
			enum WelcomeUserChoice
			{
				LogoutUser = 1,
				SettingUser,
				UtilitiesUser,
				BrowseOption,
				Manual,
				Exit
			};
			switch (WelcomeUser(CurrentUser)) {
				case LogoutUser: {    // as said change active to false
					cout << "Ban muon dang xuat? (y/n) ";
					cin.ignore();
					string Answer;
					getline(cin, Answer);
					if (Answer == "y") {
						LogoutHistory(CurrentUser);    // logout history
						CurrentUser.Active = false;    // change active to false
					}
					break;
				}
				case SettingUser: Setting(UserData, CurrentUser, debug); break;
				case UtilitiesUser:
					Utilities(CurrentUser, BookData);    // void utilities
					break;
				case BrowseOption:
					// without loging in, the user can still browse
					// we use CurrentUser.Active to know if logged in or not
					// if no, we would not let them borrow, buy?
					Browse(CurrentUser, BookData);
					system("pause");
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
						LogoutHistory(CurrentUser);
						return 0;    // terminate the program
					}
				}
				default: break;
			}
		}
	}
}