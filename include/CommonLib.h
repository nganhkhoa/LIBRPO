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

#include <cctype>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __unix
#include <termios.h>
#include <unistd.h>
#include <term.h>
#endif

#include <struct/NewUser.h>
#include <struct/LoggedInUser.h>
#include <struct/Role.h>
#include <struct/NewBook.h>

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
extern std::string FILEDeleted_JSON;


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
// ─── SIGN UP
// ────────────────────────────────────────────────────────────────────
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
extern const double FINE_MONEY;

extern std::string SUBMITDIRECTORY;

extern std::string FILESubmition;
extern std::string FILEborrowLog;

// ────────────────────────────────────────────────────────────────────────────────

//
// ─── SEARCH BOOK
// ────────────────────────────────────────────────────────────────
//

extern const unsigned int SEARCH_MAX;

// ────────────────────────────────────────────────────────────────────────────────


//
// ─── ADMIN
// ──────────────────────────────────────────────────────────────────────
//

extern std::string ADMINDIRECTORY;
extern std::string FILEAdmin;

// ────────────────────────────────────────────────────────────────────────────────


//
// ─── GLOBAL DATA
// ────────────────────────────────────────────────────────────────
//

extern LoggedInUser CurrentUser;
extern nlohmann::json UserDataJSON;
extern nlohmann::json BookDataJSON;


// ────────────────────────────────────────────────────────────────────────────────


//
// ─── COMMON FUNCTION
// ────────────────────────────────────────────────────────────
//

void Help();
std::string TrimString(std::string&);
std::string HidePassword();
void clearscreen();
void pausescreen();
void Swap(unsigned int*, unsigned int*);
void InsertionSort(std::vector<unsigned int>&);

// ────────────────────────────────────────────────────────────────────────────────


#endif