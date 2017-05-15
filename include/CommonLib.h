#ifndef LIBPRO_COMMONLIB_H
#define LIBPRO_COMMONLIB_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

//
// ─── USER DATA ──────────────────────────────────────────────────────────────────
//

	const int MAX_ROLE = 10;

	typedef struct _Account {
		std::string uid; //link to User
		std::string AccId; //account name
		std::string Password; //password
		bool Active; //active ?
		bool Lock;
		std::vector<int> RoleId;
	} Account;

	typedef struct _User {
		std::string uid;
		std::string Username;
		std::vector <Account> AccountList;
	} User;

	typedef struct _UserAccount {
		int User_num;
		int Account_num;
	} UserAccount;

	typedef struct _Role {
		int RoleId;
		std::string RoleName;
		std::string RoleDesc;
	} Role;

	extern Role LibraryRole[MAX_ROLE];

	extern std::string FILEDIRECTORY;
	extern std::string FILEUser;
	extern std::string FILEAccount;
	extern std::string FILEAccountRoleMap;
	extern std::string FILELock;

// ────────────────────────────────────────────────────────────────────────────────


//
// ─── BOOK DATA ──────────────────────────────────────────────────────────────────
//

	extern const int MAX_CHARACTER;

	typedef struct _Book {
		std::string BookId;
		std::string BookLabel;
		std::string Publisher;
		std::string Year;
		std::vector <std::string> Authors;
		std::vector <std::string> Genres;
		int Quantity = 1;
		int Borrowed = 0;
	} Book;

	extern std::string BOOKDIRECTORY;
	extern std::string FILEBook;
	extern std::string FILEAuthor;
	extern std::string FILEGenre;
	extern std::string FILEContent;

// ────────────────────────────────────────────────────────────────────────────────


//
// ─── LOGIN USER ─────────────────────────────────────────────────────────────────
//

	extern const int MAX_ATTEMPT;

	typedef struct _LoggedInUser {
		std::string AccId;
		int User_num;
		int Account_num;
		bool Active;
		std::vector<int> RoleId;
	} LoggedInUser;

// ────────────────────────────────────────────────────────────────────────────────


//
// ─── HISTORY DATA ───────────────────────────────────────────────────────────────
//

	extern std::string FILEHistoryPath;
	extern std::string FILELog;

// ────────────────────────────────────────────────────────────────────────────────


//
// ─── BROWSING ───────────────────────────────────────────────────────────────────
//

	extern const int BOOK_PER_PAGE;

// ────────────────────────────────────────────────────────────────────────────────


//
// ─── BORROWING ──────────────────────────────────────────────────────────────────
//

	extern const int MAX_BORROW;

	extern std::string SUBMITDIRECTORY;
	extern std::string FILEBorrowBook;

// ────────────────────────────────────────────────────────────────────────────────


//
// ─── COMMON FUNCTION ────────────────────────────────────────────────────────────
//

	void Help();
	std::string TrimString(std::string);

// ────────────────────────────────────────────────────────────────────────────────


#endif