/*
*	Last update: 22/06/2017, 16:37:00
*	Created on 30/4/2017, ‏‎11:59:37
*	Created by Luibo
*	LIBPRO LIBRARY SYSTEM
*	Version: 1.0.0
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
#include <SuperAdmin/SuperAdmin.h>

#include "version.h"


using namespace std;

int main(int argc, char** argv) {


	if (argc == 2) {
		if (strcmp(argv[1], "--version") == 0) {
			cout << "LIBPRO VERSION: " << LIBPRO_VERSION_MAJOR << "."
			     << LIBPRO_VERSION_MINOR << "." << LIBRPO_VERSION_FIX << endl;
			cout << "Welcome to LIBPRO" << endl;
			return 1;
		}

		if (strcmp(argv[1], "--help") == 0) {
			Help();
			return 0;
		}

		if (strcmp(argv[1], "--info") == 0) {
#ifdef _WIN32    // change size to make it beautiful
			HWND console = GetConsoleWindow();
			RECT r;
			GetWindowRect(console, &r);
			MoveWindow(console, r.left, r.top, 750, 600, TRUE);
#endif

			clearscreen();

			cout << setw(15) << " " << endl << endl;
			cout << setw(15) << " "
			     << "LIBPRO " << LIBPRO_VERSION_MAJOR << "."
			     << LIBPRO_VERSION_MINOR << "." << LIBRPO_VERSION_FIX << endl;
			cout << setw(15) << " "
			     << "Lap trinh boi nhom SIMPLE" << endl;
			cout << setw(15) << " "
			     << "Ban quyen thuoc ve nhom SIMPLE" << endl;
			cout << setw(15) << " "
			     << "Bai tap lon so 2" << endl;
			cout << setw(15) << " "
			     << "Ky thuat lap trinh" << endl;

			cout << setw(15) << " " << endl;
			cout << setw(15) << " " << endl;
			cout << setw(15) << " "
			     << ">>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<" << endl;
			cout << setw(15) << " "
			     << "https://thaoxkhoa.visualstudio.com/LIBPRO" << endl;
			cout << setw(15) << " "
			     << ">>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<" << endl;
			cout << setw(15) << " " << endl;

			cout << setw(15) << " " << endl;
			cout << setw(15) << " "
			     << "Danh sach thanh vien: " << endl;
			cout << setw(15) << " "
			     << "Nguyen Anh Khoa  - 1611617" << endl;
			cout << setw(15) << " "
			     << "Nguyen Minh Khoi - 1611657" << endl;
			cout << setw(15) << " "
			     << "Pham Quoc Nam    - 1612128" << endl;
			cout << setw(15) << " " << endl;

			cout << setw(15) << " " << endl;
			cout << setw(15) << " "
			     << "Dai hoc Bach Khoa TPHCM" << endl;
			cout << setw(15) << " "
			     << "Khoa khoa hoc va ky thuat may tinh" << endl;
			cout << setw(15) << " "
			     << "Lop MT16, khoa 2016, BK16" << endl;
			cout << setw(15) << " "
			     << "____________________________________________" << endl;
			cout << setw(15) << " "
			     << "Written by LUIBO" << endl;
			cout << setw(15) << " " << endl;
			return 0;
		}

		return 0;
	}

	if (argc > 2) return 0;


	srand(time(NULL));
	clearscreen();

	SuperAdminHiddenUsername();
	SuperAdminHiddenPassword();

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
	pausescreen();
	return result;

#endif
}
