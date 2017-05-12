#include <Browse.h>

using namespace std;

void ShowAllBook(LoggedInUser CurrentUser, vector<Book>& BookData) {
	system("cls");
	for (int books = 0; books < BookData.size(); books++) {

		//the book label
		cout << books + 1 << ": " << BookData[books].BookLabel << endl;

		//the book authors
		//if more than 3 etc
		//if less than 3 show all
		cout << "Tac gia: ";
		for (int author = 0; author < BookData[books].Authors.size(); author++) {
			if (author == 3) {
				cout << ", va nhieu tac gia khac";
				break;
			}
			if (author != 0) {
				if (author == BookData[books].Authors.size() - 1) cout << " and ";
				else cout << ", ";
			}
			cout << BookData[books].Authors[author];
		}
		cout << "." << endl;

		//book quantity
		cout << "Hien co: " << BookData[books].Quantity - BookData[books].Borrowed << " quyen trong kho";
		
		cout << endl;
		cout << "_________________________________________" << endl;
		cout << endl;


		//doing math to slit page
		//doing math to know which page
		//and wait for user input
		if (!((books + 1) % BOOK_PER_PAGE)) {

			//if the browsing book is BOOK_PER_PAGE boi so
			//pause
			//show the page which I have the formula below
			//wait user input

			int Pages = BookData.size() / BOOK_PER_PAGE;
			if (BookData.size() % BOOK_PER_PAGE) Pages += 1;

			cout << "Trang " << (books + 1) / BOOK_PER_PAGE << "/" << Pages << endl;

			ChooseBook(CurrentUser, BookData, books);
			system("pause");
			system("cls");
		}
		if ((books + 1) == BookData.size() && BookData.size() % BOOK_PER_PAGE) {

			//if you are on the last book
			//and the last book is not modibel to BOOK_PER_PAGE
			//then you do math to know the page
			//wait for user input

			int Pages = BookData.size() / BOOK_PER_PAGE;
			Pages += 1;
			cout << "Trang " << Pages << "/" << Pages << endl;

			ChooseBook(CurrentUser, BookData, books);
			system("pause");
			system("cls");
		}
	}
}