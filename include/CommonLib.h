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

typedef struct _Role {
	int RoleId;
	std::string RoleName;
	std::string RoleDesc;
} Role;

extern Role LibraryRole[MAX_ROLE];

extern std::string FILEDIRECTORY;
extern std::string FILEUser_focus_JSON;
extern std::string FILESignUp_JSON;
extern std::string FILERejected_JSON;


// ────────────────────────────────────────────────────────────────────────────────


//
// ─── BOOK DATA
// ──────────────────────────────────────────────────────────────────
//

extern const unsigned int MAX_CHARACTER;

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

	int User_num    = -1;
	int Account_num = -1;

	std::string AccountName = "";
	std::string Username    = "";

	bool Active             = false;
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


// ────────────────────────────────────────────────────────────────────────────────


//
// ─── COMMON FUNCTION
// ────────────────────────────────────────────────────────────
//

void Help();
std::string TrimString(std::string&);

// ────────────────────────────────────────────────────────────────────────────────


#endif