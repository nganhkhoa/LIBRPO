#include <Browse/Browse.h>

using namespace std;
using json = nlohmann::json;

void ShowAllBook(json& bookdata) {
	system("cls");
	int num_Books = bookdata.at("BookLibrary").size();
	for (int books = 0; books < num_Books; books++) {

		// the book label
		string BookTitle = bookdata.at("BookLibrary")[books].at("Title");
		cout << books + 1 << ": " << BookTitle << endl;

		// the book authors
		// if more than 3 etc
		// if less than 3 show all
		int num_Authors = bookdata.at("BookLibrary")[books].at("Author").size();
		cout << "Tac gia: ";
		for (int author = 0; author < num_Authors;
		     author++) {
			if (author == 3) {
				cout << ", va nhieu tac gia khac";
				break;
			}
			if (author != 0) {
				if (author == num_Authors - 1)
					cout << " va ";
				else
					cout << ", ";
			}
			string Author = bookdata.at("BookLibrary")[books].at("Author")[author];
			cout << Author;
		}
		cout << "." << endl;

		// book quantity
		cout << "Hien co: "
		     << bookdata.at("BookLibrary")[books].at("BookNumber") //- bookdata.at("BookLibrary")[books].at("Borrowed")
		     << " quyen trong kho";

		cout << endl;
		cout << "_________________________________________" << endl;
		cout << endl;


		// doing math to slit page
		// doing math to know which page
		// and wait for user input
		if (!((books + 1) % BOOK_PER_PAGE)) {

			// if the browsing book is BOOK_PER_PAGE boi so
			// pause
			// show the page which I have the formula below
			// wait user input

			int Pages = num_Books / BOOK_PER_PAGE;
			if (num_Books % BOOK_PER_PAGE) Pages += 1;

			cout << "Trang " << (books + 1) / BOOK_PER_PAGE << "/" << Pages
			     << endl;

			ChooseBook(bookdata, books);
			system("pause");
			system("cls");
		}
		if ((books + 1) == num_Books && num_Books % BOOK_PER_PAGE) {

			// if you are on the last book
			// and the last book is  %= BOOK_PER_PAGE != 0
			// then you do math to know the page
			// wait for user input

			int Pages = num_Books / BOOK_PER_PAGE;
			Pages += 1;
			cout << "Trang " << Pages << "/" << Pages << endl;

			ChooseBook(bookdata, books);
			system("pause");
			system("cls");
		}
	}
}


int ShowBookResult(json& bookdata) {
	int num_Books = bookdata.at("BookLibrary").size();
	for (int books = 0; books < num_Books; books++) {

		// the book label
		string BookTitle = bookdata.at("BookLibrary")[books].at("Title");
		cout << books + 1 << ": " << BookTitle << endl;
	}
	cout << num_Books + 1 << ": Thoat" << endl;

	cout << "Moi ban chon: ";
	int Choice = 0;
	cin >> Choice;

	while (Choice < 1 || Choice > num_Books + 1) {
		cout << "Lua chon khong co" << endl;
		cout << "Moi ban nhap lai: ";
		cin >> Choice;
	}
	return Choice;
}