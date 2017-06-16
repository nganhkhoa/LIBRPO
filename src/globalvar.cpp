#include <CommonLib.h>

bool debug = true;    // debug mode switch


//
// ─── DATA
// ───────────────────────────────────────────────────────────────────────
//

nlohmann::json UserDataJSON = NULL;
// std::vector<User> UserData  = {};
nlohmann::json BookDataJSON = NULL;
// std::vector<Book> BookData  = {};
LoggedInUser CurrentUser;


//
// ─── CONSTE STUFF
// ───────────────────────────────────────────────────────────────
//


const unsigned int MAX_CHARACTER = 1000;

const unsigned int MAX_ATTEMPT = 3;

const unsigned int BOOK_PER_PAGE = 3;

const unsigned int MAX_BORROW = 4;

const unsigned int MAX_WEEK_BORROW = 2;

const unsigned int SEARCH_MAX = 10;

Role LibraryRole[MAX_ROLE]{
  {1, "DOC GIA", "Chi co quyen doc"},
  {2, "THU THU", "Khong biet thu thu lam gi"},
  {3, "QUAN LY NGUOI DUNG", "Them nguoi dung, xoa nguoi dung?"},
  {4, "QUAN LY TAI CHINH", "Quan ly tien"}};

std::string BOOKDIRECTORY = "book/";
std::string FILEBookJSON  = BOOKDIRECTORY + "book.json";

std::string FILEHistoryPath = "history/";
std::string FILELog         = FILEHistoryPath + "log.txt";

std::string FILEDIRECTORY       = "user/";
std::string FILEUser_focus_JSON = FILEDIRECTORY + "userdata_user-focus.json";
std::string FILESignUp_JSON     = FILEDIRECTORY + "user_signup.json";
std::string FILERejected_JSON   = FILEDIRECTORY + "user_rejected.json";

std::string SUBMITDIRECTORY = "borrow/";

std::string FILESubmition = SUBMITDIRECTORY + "submition.json";
std::string FILEborrowLog = SUBMITDIRECTORY + "borrowLog.json";