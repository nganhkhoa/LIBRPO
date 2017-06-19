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

#include <gtest/gtest.h>

#include <CommonLib.h>

#include <Book/ReadBookJSON.h>
#include <Data/ReadDataJSON.h>
#include <Welcome/Screens.h>

using namespace std;

int main(int argc, char** argv) {
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

#ifndef UNITTEST

	while (true) {                       // also run welcome until exit
		while (!CurrentUser.Active) {    // if not active, show general welcome
			NotYetLogInScreen();
		}
		while (CurrentUser.Active && CurrentUser.Account_num == -1) {
			UserLogInScreen();
		}
		while (CurrentUser.Active && CurrentUser.Account_num != -1) {
			AccountLogInScreen();
		}
	}

#else

	::testing::InitGoogleTest(&argc, argv);
	int result = RUN_ALL_TESTS();
	system("pause");
	return result;

#endif
}