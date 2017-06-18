/*
 * @CreateTime: Jun 18, 2017 10:10 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 18, 2017 10:10 PM
 * @Description: Tổng hợp các hàm tìm kiếm trên dữ liệu với key sẵn
 */

#include <Find/Find.h>

using namespace std;

unsigned int FindUserByName(string& name) {
	int num_Users = UserDataJSON.at("UserList").size();
	for (int i = 0; i < num_Users; i++) {
		string Username = UserDataJSON.at("UserList")[i].at("Username");
		if (Username == name) return i;
	}
	return num_Users;
}

unsigned int FindUserID(string& UserID) {
	int num_Users = UserDataJSON.at("UserList").size();
	for (int i = 0; i < num_Users; i++) {
		string data_UserID = UserDataJSON.at("UserList")[i].at("UserID");
		if (data_UserID == UserID) return i;
	}
	return num_Users;
}


unsigned int FindBookIndex(string& ISBN) {
	unsigned int book_num = BookDataJSON.at("BookLibrary").size();
	for (unsigned int index = 0; index < book_num; index++) {
		string ISBN_DATA = BookDataJSON.at("BookLibrary")[index].at("ISBN");
		if (ISBN_DATA == ISBN) return index;
	}
	return book_num;
}