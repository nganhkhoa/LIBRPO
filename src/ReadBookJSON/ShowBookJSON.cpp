/*
 * @CreateTime: Jun 18, 2017 10:08 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 18, 2017 10:08 PM
 * @Description: Xuất thông tin sách từ json ra
 */

#include <Book/ReadBookJSON.h>

using namespace std;

void ShowBookDataJSON(int& Book_num) {
	string ISBN  = BookDataJSON.at("BookLibrary")[Book_num].at("ISBN");
	string Title = BookDataJSON.at("BookLibrary")[Book_num].at("Title");
	// string Author = ;
	int Year         = BookDataJSON.at("BookLibrary")[Book_num].at("Year");
	string Publisher = BookDataJSON.at("BookLibrary")[Book_num].at("Publisher");
	string Content   = BookDataJSON.at("BookLibrary")[Book_num].at("Content");
	// string Genre = ;
	int BookNumber = BookDataJSON.at("BookLibrary")[Book_num].at("BookNumber");


	cout << "The book ID: "
	     << "\t" << ISBN << endl;
	cout << "The book label: "
	     << "\t" << Title << endl;
	cout << "The book Publisher: "
	     << "\t" << Publisher << endl;
	cout << "The book was published in: "
	     << "\t" << Year << endl;
	cout << "In stock: "
	     << "\t" << BookNumber << endl;
	cout << "\nContent:\n ";
	cout << Content << endl;
}