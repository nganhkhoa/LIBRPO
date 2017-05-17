#include <Browse.h>

using namespace std;

void ChooseHelp() {

	// this is help

	cout << "Huong dan cau lenh" << endl;
	cout << setw(5) << " " << left << setw(15) << "--view n" << left << setw(10)
	     << "" << left << setw(30) << "Xem sach n" << endl;
	cout << setw(5) << " " << left << setw(15) << "--back" << left << setw(10)
	     << "" << left << setw(30) << "Quay lai trang truoc" << endl;
	cout << setw(5) << " " << left << setw(15) << "--forward" << left
	     << setw(10) << "" << left << setw(30) << "Toi trang tiep theo" << endl;
	cout << setw(5) << " " << left << setw(15) << " " << left << setw(10) << ""
	     << left << setw(30) << "Mac dinh khi ban bam enter" << endl;
	cout << setw(5) << " " << left << setw(15) << "--jump n" << left << setw(10)
	     << "" << left << setw(30) << "Nhay toi trang thu n" << endl;
	cout << setw(5) << " " << left << setw(15) << "--firstpage" << left
	     << setw(10) << "" << left << setw(30) << "Nhay ve trang dau" << endl;
	cout << setw(5) << " " << left << setw(15) << "--lastpage" << left
	     << setw(10) << "" << left << setw(30) << "Nhay ve trang cuoi" << endl;
	cout << setw(5) << " " << left << setw(15) << "--refresh" << left
	     << setw(10) << "" << left << setw(30) << "Lam moi trang nay" << endl;
	cout << setw(5) << " " << left << setw(15) << "--bosuutap n" << left
	     << setw(10) << "" << left << setw(30)
	     << "Them n vao bo suu tap cua ban" << endl;
	cout << setw(5) << " " << left << setw(15) << "--mua n" << left << setw(10)
	     << "" << left << setw(30) << "Bo n vao gio hang cua ban de mua"
	     << endl;
	cout << setw(5) << " " << left << setw(15) << "--muon n" << left << setw(10)
	     << "" << left << setw(30) << "Muon sach n" << endl;
	cout << setw(5) << " " << left << setw(15) << "--thoat" << left << setw(10)
	     << "" << left << setw(30) << "Khong duyet nua" << endl;
	cout << endl << endl;
	cout << "Moi ban chon cau lenh: ";
}


bool ChooseBack(int& books) {

	// this is pure math

	if (books + 1 == BOOK_PER_PAGE) {
		cout << "Ban dang o trang cao nhat" << endl;
		cout << "Moi nhap lai: ";
		return true;
	}
	else if ((books + 1) % BOOK_PER_PAGE) {
		while ((books + 1) % BOOK_PER_PAGE) {
			books--;
		}
		books -= BOOK_PER_PAGE;
		return false;
	}
	else {
		books -= 1;
		books -= (BOOK_PER_PAGE * 2 - 1);
		return false;
	}
}

void ShowBookContent(string Id) {

	// open file content and search for ISBN
	// and get the information

	ifstream contentfile(FILEContent);
	if (!contentfile.is_open()) { return; }

	string str;
	while (getline(contentfile, str)) {
		stringstream scin(str);
		string TempString;
		scin >> TempString;
		if (TempString == Id) break;
	}

	cout << "\t";
	for (int i = 17; i < str.length(); i++) {
		if (str[i] == '\\') {
			i++;
			cout << endl;
			continue;
		}
		cout << str[i];
	}
}


void ChooseBookInformation(vector<Book>& BookData, int& BookToShow) {
	system("cls");

	BookToShow--;

	cout << "Ten sach:" << BookData[BookToShow].BookLabel << endl;

	cout << "Tac gia:" << endl;
	for (int author = 0; author < BookData[BookToShow].Authors.size();
	     author++) {
		if (author == 3) {
			cout << ", va nhieu tac gia khac";
			break;
		}
		if (author != 0) {
			if (author == BookData[BookToShow].Authors.size() - 1)
				cout << " and ";
			else
				cout << ", ";
		}
		cout << BookData[BookToShow].Authors[author];
	}
	cout << "." << endl;

	cout << "So luong sach: " << BookData[BookToShow].Quantity << endl;

	cout << "Muon sach: " << true << endl;

	cout << "Mua sach: " << true << endl;
	if (/*mua sach duoc*/ true) cout << "Gia sach: $" << 10.00 << endl;

	cout << "Noi dung sach: " << endl;
	ShowBookContent(BookData[BookToShow].BookId);

	cout << endl << endl;
	return;
}

void ChooseBook(LoggedInUser CurrentUser, vector<Book>& BookData, int& books) {

	/// too bad we can't do switch here

	cout << "Go viec ban muon lam" << endl;
	cout << "Go enter de tiep tuc sang trang khac" << endl;
	cout << "Go --help de biet them chi tiet" << endl;
	string str;
	bool WrongInput = true;
	while (WrongInput) {
		getline(cin, str);
		if (str.empty()) return;

		stringstream scin(str);
		string TempString;
		scin >> TempString;

		if (TempString == "--help")
			ChooseHelp();    // show help

		else if (TempString == "--view") {
			// the input must be
			//--view <a number>
			// a number not numbers
			// so if the user enter exceeding that
			// don't f*#^%*#% care
			int BookToShow;
			scin >> BookToShow;
			if (scin.fail()) {
				cout << "Ban khong nhap dung cu phap" << endl;
				continue;
			}

			// check in range
			// BookToShow

			ChooseBookInformation(BookData, BookToShow);


			// refresh page
			// this is math
			// again I don't want to talk about this
			if ((books + 1) % BOOK_PER_PAGE) {
				while ((books + 1) % BOOK_PER_PAGE) {
					books--;
				}
				return;
			}
			books -= BOOK_PER_PAGE;
			return;
		}

		else if (TempString == "--back")
			WrongInput = ChooseBack(books);    // back page

		else if (TempString == "--forward")
			return;    // default is move to next page
		// still in for


		else if (TempString == "--jump") {

			// jumps to another page not this page
			// still I haven't check if the page entered is the current page

			int PageNum;
			scin >> PageNum;
			if (scin.fail()) {
				cout << "Ban nhap khong dung cu phap" << endl;
				continue;
			}

			if (PageNum < 1) {
				cout << "Ban nhap trang khong hien huu" << endl;
				continue;
			}

			int lastpage = BookData.size() / BOOK_PER_PAGE;
			if (PageNum > lastpage) {
				cout << "Ban nhap trang khong hien huu" << endl;
				continue;
			}

			if (PageNum == 1)
				books = -1;
			else
				books = BOOK_PER_PAGE * (PageNum - 1) - 1;
			return;
		}

		else if (TempString == "--firstpage") {
			// jump to first page
			books = -1;
			return;
		}

		else if (TempString == "--lastpage") {
			// jumps to last page
			books = BookData.size();
			if (books % BOOK_PER_PAGE) {
				while (books % BOOK_PER_PAGE) {
					books--;
				}
				return;
			}
			books -= BOOK_PER_PAGE + 1;
			return;
		}

		else if (TempString == "--bosuutap") {
			// I don't know
		}

		else if (TempString == "--refresh") {

			// refresh the page
			// Yeah refresh

			if ((books + 1) % BOOK_PER_PAGE) {
				while ((books + 1) % BOOK_PER_PAGE) {
					books--;
				}
				return;
			}
			books -= BOOK_PER_PAGE;
			return;
		}

		else if (TempString == "--thoat") {
			// exit, well
			// you're in for
			// make the condition false
			books = BookData.size();
			return;
		}

		else {

			// wrong input

			cout << "Cau lenh \"" << str << "\" khong co" << endl;
			cout << "Xin vui long nhap lai" << endl;
			cout << "Hoac enter de di toi trang tiep theo" << endl;
			cout << "Hoac go \"--help\" de biet them thong tin ve cach nhap"
			     << endl;
			cout << "Nhap lai: ";
		}
	}
	return;
}