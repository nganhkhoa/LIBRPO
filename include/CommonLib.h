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
#include <struct/LoggedInUser.h>
#include <struct/Role.h>

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

// ────────────────────────────────────────────────────────────────────────────────


//
// ─── SIGN UP ────────────────────────────────────────────────────────────────────
//

extern const unsigned int PWD_LENGHT;

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
std::string HidePassword();

// ────────────────────────────────────────────────────────────────────────────────


#endif