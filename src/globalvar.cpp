/*
 * @CreateTime: Jun 18, 2017 9:55 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: undefined
 * @Last Modified Time: Jun 18, 2017 11:04 PM
 * @Description: Các biến toàn cục trong chương trình
 */

#include <CommonLib.h>

bool debug = false;    // debug mode switch
// this should be #define debug


//
// ─── DATA
// ───────────────────────────────────────────────────────────────────────
//

nlohmann::json UserDataJSON = NULL;
nlohmann::json BookDataJSON = NULL;
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

const double FINE_MONEY = 10000;

const unsigned int SEARCH_MAX = 10;

const unsigned int PWD_LENGHT = 10;

Role LibraryRole[MAX_ROLE] = {
  {1, "DOC GIA", "Chi co quyen doc", 0},
  {2, "NHA SUU TAM", "Co the mua duoc sach", 10},
  {3, "REVIEWER", "Co the binh luan sach", 20},
  {4, "CD", "Co the truy cap vao kho sach noi", 50},
  {5, "MOVIE", "Co the truy cap vao kho phim anh", 100},
  {6, "EBOOK", "Co the truy cap vao kho ebook", 50},
  {7, "VIP", "Huong tat ca quyen loi tren", 200},
  {8, "THU THU", "Quan ly sach", 0},
  {9, "QUAN LY TAI CHINH", "Quan ly tien", 0},
  {10, "QUAN LY NGUOI DUNG", "Them nguoi dung, xoa nguoi dung?", 0}};

std::string BOOKDIRECTORY = "book/";
std::string FILEBookJSON  = BOOKDIRECTORY + "book.json";

std::string FILEHistoryPath = "history/";
std::string FILELog         = FILEHistoryPath + "log.txt";

std::string FILEDIRECTORY       = "user/";
std::string FILEUser_focus_JSON = FILEDIRECTORY + "userdata_user-focus.json";
std::string FILESignUp_JSON     = FILEDIRECTORY + "user_signup.json";
std::string FILERejected_JSON   = FILEDIRECTORY + "user_rejected.json";
std::string FILEDeleted_JSON    = FILEDIRECTORY + "user_deleted.json";

std::string SUBMITDIRECTORY = "borrow/";
std::string FILESubmition   = SUBMITDIRECTORY + "submition.json";
std::string FILEborrowLog   = SUBMITDIRECTORY + "borrowLog.json";

std::string ADMINDIRECTORY = "admin/";
std::string FILEAdmin      = ADMINDIRECTORY + "pwd.txt";