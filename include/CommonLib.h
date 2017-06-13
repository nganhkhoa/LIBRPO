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

#include <ctime>

#include <struct/NewUser.h>

// json parser for C++
// all credit to  nlohmann
#include <nlohmann/json.hpp>
// github repository
// https://github.com/nlohmann/json


//
// ─── USER DATA
// ──────────────────────────────────────────────────────────────────
//

const unsigned int MAX_ROLE = 10;

typedef struct _Account {
	std::string uid;         // link to User
	std::string AccId;       // account name
	std::string Password;    // password
	bool Active;             // active ?
	bool Lock;
	std::vector<int> RoleId;
} Account;

typedef struct _User {
	std::string uid;
	std::string Username;
	std::vector<Account> AccountList;
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
extern std::string FILEUser_focus_JSON;

// ────────────────────────────────────────────────────────────────────────────────


//
// ─── BOOK DATA
// ──────────────────────────────────────────────────────────────────
//

extern const unsigned int MAX_CHARACTER;

typedef struct _Book {
	std::string BookId;
	std::string BookLabel;
	std::string Publisher;
	std::string Year;
	std::vector<std::string> Authors;
	std::vector<std::string> Genres;
	int Quantity = 1;
	int Borrowed = 0;
} Book;

extern std::string BOOKDIRECTORY;
extern std::string FILEBookJSON;

// ────────────────────────────────────────────────────────────────────────────────


//
// ─── LOGIN USER
// ─────────────────────────────────────────────────────────────────
//

extern const unsigned int MAX_ATTEMPT;

typedef struct _LoggedInUser {
	std::string UserID = "";

	int User_num = -1;
	int Account_num = -1;

	std::string AccountName = "";
	std::string Username = "";

	bool Active = false;
	std::vector<int> RoleId = {};
} LoggedInUser;

// ────────────────────────────────────────────────────────────────────────────────


//
// ─── HISTORY DATA
// ───────────────────────────────────────────────────────────────
//

extern std::string FILEHistoryPath;
extern std::string FILELog;

// ────────────────────────────────────────────────────────────────────────────────


//
// ─── BROWSING
// ───────────────────────────────────────────────────────────────────
//

extern const unsigned int BOOK_PER_PAGE;

// ────────────────────────────────────────────────────────────────────────────────


//
// ─── BORROWING
// ──────────────────────────────────────────────────────────────────
//

typedef struct _BorrowBookSubmit {
	int Status;
	// 0 no browse
	// 1 accept
	// 2 reject
	int User_num;
	int Account_num;
	// passing these to lock user
	// lock by accountant
	// also to get record
	std::string ISBN;
	int Accountant_User_num;
	int Accountant_Account_num;
	// to know who have done what
} BorrowBookSubmit;

extern const unsigned int MAX_BORROW;
extern const unsigned int MAX_WEEK_BORROW;

extern std::string SUBMITDIRECTORY;

extern std::string FILESubmition;
extern std::string FILEborrowLog;

// ────────────────────────────────────────────────────────────────────────────────

//
// ─── SEARCH BOOK
// ────────────────────────────────────────────────────────────────
//

extern const unsigned int SEARCH_MAX;

//
// ─── GLOBAL DATA
// ────────────────────────────────────────────────────────────────
//

extern bool debug;
extern LoggedInUser CurrentUser;
extern nlohmann::json UserDataJSON;
// extern std::vector<User> UserData;
extern nlohmann::json BookDataJSON;
extern std::vector<Book> BookData;


// ────────────────────────────────────────────────────────────────────────────────


//
// ─── COMMON FUNCTION
// ────────────────────────────────────────────────────────────
//

void Help();
std::string TrimString(std::string&);

// ────────────────────────────────────────────────────────────────────────────────


#endif