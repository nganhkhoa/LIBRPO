#include <CommonLib.h>

bool debug = true;    // debug mode switch


//
// ─── DATA
// ───────────────────────────────────────────────────────────────────────
//

nlohmann::json UserDataJSON = NULL;
std::vector<User> UserData  = {};
std::vector<Book> BookData  = {};
LoggedInUser CurrentUser    = {"", -1, -1, false, {}};


//
// ─── CONSTE STUFF
// ───────────────────────────────────────────────────────────────
//


const int MAX_CHARACTER = 1000;

const int MAX_ATTEMPT = 3;

const int BOOK_PER_PAGE = 3;

const int MAX_BORROW = 4;

const int MAX_WEEK_BORROW = 2;

Role LibraryRole[MAX_ROLE]{
  {1, "DOC GIA", "Chi co quyen doc"},
  {2, "THU THU", "Khong biet thu thu lam gi"},
  {3, "QUAN LY NGUOI DUNG", "Them nguoi dung, xoa nguoi dung?"},
  {4, "QUAN LY TAI CHINH", "Quan ly tien"}};

std::string BOOKDIRECTORY = "book/";
std::string FILEBook      = BOOKDIRECTORY + "book.txt";
std::string FILEAuthor    = BOOKDIRECTORY + "author.txt";
std::string FILEGenre     = BOOKDIRECTORY + "genre.txt";
std::string FILEContent   = BOOKDIRECTORY + "content.txt";

std::string FILEHistoryPath = "history/";
std::string FILELog         = FILEHistoryPath + "log.txt";

std::string FILEDIRECTORY = "user/";                       // link to folder
std::string FILEUser      = FILEDIRECTORY + "user.txt";    // link to user file
std::string FILEAccount =
  FILEDIRECTORY + "account.txt";    // link to account file
std::string FILEAccountRoleMap =
  FILEDIRECTORY + "accountrolemap.txt";    // link to account role map file
std::string FILELock      = FILEDIRECTORY + "lock.txt";    // link to lock file
std::string FILEUserJSON = FILEDIRECTORY + "userdata.json";

std::string SUBMITDIRECTORY  = "submit/";
std::string FILEBorrowBook   = SUBMITDIRECTORY + "borrow.txt";
std::string FILEBorrowRecord = SUBMITDIRECTORY + "borrowrecord.txt";