#include "..\..\include\ReadBook.h"

using namespace std;

void ShowBookData(vector<Book>& BookData, int& Book_num) {
	cout	<< "The book ID: " 				<< "\t" << BookData[Book_num].BookId 		<< endl;
	cout	<< "The book label: " 			<< "\t" << BookData[Book_num].BookLabel 	<< endl;
	cout	<< "The book Publisher: " 		<< "\t" << BookData[Book_num].Publisher 	<< endl;
	cout	<< "The book was published on: "<< "\t" << BookData[Book_num].Year			<< endl;
			///this year thing?
			///should it be day month year
			//but unfortunately 
			//the string is hard to examine
	cout 	<< "In stock: "					<< "\t"	<< BookData[Book_num].Quantity		<< endl;
	//cout	<< "The book was published on: "<< "\t" << Date(BookData[Book_num].Date)	<< endl;
}
void ShowBookAuthor(vector<Book>& BookData, int& Book_num) {
	for (int Author_num = 0; Author_num < BookData[Book_num].Authors.size(); Author_num++) {
		cout << "\t" << BookData[Book_num].Authors[Author_num] << endl;
	}
}
void ShowBookGenre(vector<Book>& BookData, int& Book_num) {
	for (int Genre_num = 0; Genre_num < BookData[Book_num].Genres.size(); Genre_num++) {
		cout << "\t" << BookData[Book_num].Genres[Genre_num] << endl;
	}
}

void ShowBook(vector<Book>& BookData) {
		//read above please
	system("cls");
	for (int Book_num = 0; Book_num < BookData.size(); Book_num++) {
		ShowBookData(BookData, Book_num);
		cout << "The book Authors:" << endl;
		ShowBookAuthor(BookData, Book_num);
		cout << "The book Genres:" << endl;
		ShowBookGenre(BookData, Book_num);
	}
}