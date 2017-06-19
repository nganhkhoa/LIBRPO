#include <Utilities/Utilities.h>
#include <Find/Find.h>
#include <Book/ReadBookJSON.h>

using namespace std;
using json = nlohmann::json;

vector<string> ExtractStatement() {
	vector<string> result = {};
	unsigned int index    = 0;
	while (getline(cin, result[index], ',')) {    // infinity loop
		index++;
	}
	return result;
}

json CreateNewBook(NewBook& book) {
	json new_book         = json::object();
	new_book["ISBN"]      = book.ISBN;
	new_book["Title"]     = book.Title;
	new_book["Publisher"] = book.Publisher;
	new_book["Year"]      = book.Year;
	new_book["Content"]   = book.Content;

	new_book["Author"]   = json::array();
	new_book["Category"] = json::array();

	unsigned int num_author   = book.Author.size();
	unsigned int num_category = book.Category.size();
	for (unsigned int index = 0; index < num_author; index++) {
		new_book.at("Author")[index] = book.Author[index];
	}

	for (unsigned int index = 0; index < num_category; index++) {
		new_book.at("Category")[index] = book.Category[index];
	}
	return new_book;
}

void AddNewBook(string& ISBN) {
	NewBook book;
	book.ISBN = ISBN;
	cout << "Nhap ten quyen sach: ";
	getline(cin, book.Title);
	cout << "Nhap nha xuat ban: ";
	getline(cin, book.Publisher);
	cout << "Nhap nam xuat ban: ";
	getline(cin, book.Year);

	cout << "Nhap ten cac tac gia, cach nhau dau \",\"";
	book.Author = ExtractStatement();

	cout << "Nhap ten cac the loai, cach nhau dau \",\"";
	book.Category = ExtractStatement();

	cout << "Nhap noi dung, co the de trong va sua sau:" << endl;
	getline(cin, book.Content);

	json new_book         = CreateNewBook(book);
	unsigned int num_book = BookDataJSON.at("BookLibrary").size();
	BookDataJSON.at("BookLibrary")[num_book] = new_book;
}

void AddExistBook(string& ISBN) {
	unsigned int book_place = FindBookIndex(ISBN);
	unsigned int quanlity =
	  BookDataJSON.at("BookLibrary")[book_place].at("BookNumber");
	int add_quanlity = 0;

	cout << "Hien tai co " << quanlity << " quyen sach trong kho" << endl;
	cout << "Ban muon them vao bao nhieu quyen? ";
	cin >> add_quanlity;

	while (add_quanlity < 0) {
		cout << "Khong the them so luong sach am." << endl;
		cout << "Neu ban muon bot di, hay vao phan" << endl;
		cout << "chinh thong tin sach" << endl;
		cin >> add_quanlity;
	}

	BookDataJSON.at("BookLibrary")[book_place].at("BookNumber") =
	  quanlity + add_quanlity;
}


bool book_exits(string& ISBN) {
	unsigned int book_place = FindBookIndex(ISBN);
	if (book_place == BookDataJSON.at("BookLibrary").size()) { return false; }
	return true;
}


void ChoiceAddBook() {
	clearscreen();
	cout << "Nhap ma so sach ISBN: ";
	string ISBN = "";
	getline(cin, ISBN);

	if (ISBN == "") { return; }

	if (book_exits(ISBN)) { AddExistBook(ISBN); }
	else {
		AddNewBook(ISBN);
	}

	if (!UpdateBookDataJSON()) {
		cout << "Du lieu khong duoc them vao" << endl;
		cout << "Xin hay thu lai sau" << endl;
	}
	else {
		cout << "Da them vao thanh cong" << endl;
	}
	pausescreen();
	return;
}