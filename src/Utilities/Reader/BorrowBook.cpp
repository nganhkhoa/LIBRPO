#include <Utilities/Utilities.h>
#include <Browse/Browse.h>
#include <Find/FindBook.h>

using namespace std;
using json = nlohmann::json;

json readSubmitBorrow(){
	json Submit;

	ifstream submitionfile(FILESubmition, ios::in);
	if (!submitionfile.is_open()) return false;

	submitionfile >> Submit;
	submitionfile.close();
	return Submit;
}

bool CreateRequestBorrowBook(string& ISBN) {
	json Submit = NULL;
	Submit = readSubmitBorrow();
	
	json newsubmit = json::object();

	unsigned int submitid = 0;
	if (Submit.at("Submition").size()  == 0) {
		// check the
	} else {
		submitid = Submit.at("Submition")[Submit.at("Submition").size() - 1].at(
		  "Submit ID");
		submitid += 1;
	}
	newsubmit["ISBN"]         = ISBN;
	newsubmit["User"]         = CurrentUser.UserID;
	newsubmit["Request Date"] = "Today";
	newsubmit["Submit ID"]    = submitid;
	newsubmit["Check"]        = false;

	Submit.at("Submition")[Submit.at("Submition").size()] = newsubmit;

	ofstream submitionfile(FILESubmition, ios::out);
	if (!submitionfile.is_open()) return false;
	submitionfile << Submit.dump(4);
	submitionfile.close();
	return true;
}

void BorrowFromCart(vector<Book>& Cart) {
	for (unsigned int index = 0; index < Cart.size(); index++) {
		if (index > MAX_BORROW /*- UserBorrow*/) {
			cout << "Ban dang muon hon so quyen sach co the" << endl;
			cout << "Ban khong muon them duoc nua" << endl;
			cout << "Cac cuon sach da duoc gui yeu cau: " << endl << endl;
			for (int books = 0; books < 3; books++) {
				cout << Cart[books].BookLabel << endl;
			}
			system("pause");
			return;
		}
		if (!CreateRequestBorrowBook(Cart[index].BookId)) {
			cout << "Khong the gui yeu cau sach" << endl;
			cout << "Bam enter de tiep tuc" << endl;
			system("pause");
			return;
		}
	}
	return;
}

void BorrowBook(/*vector<Book>& BorrowCart*/) {
	while (true) {
		system("cls");
		cout << "Nhap ten sach ban muon muon" << endl;
		cout << "Neu de trong se quay ve" << endl;
		cout << "Neu ban muon muon tu gio sach, go \"giosach\"" << endl;
		cout << "Ten sach: ";
		string keywords;
		getline(cin, keywords);

		if (keywords.empty()) return;
		if (keywords == "giosach") {
			// BorrowFromCart(BorrowCart);
			return;
		}

		json resultJSON  = NULL;

		int BookIndex = -1;
		BookIndex = FindBookBorrow(keywords, resultJSON);

		if (BookIndex == -1) {
			cout << "Ten sach khong tim thay" << endl;
			cout << "Moi ban nhap lai" << endl;
			cout << "Bam enter de tiep tuc" << endl;
			system("pause");
			continue;
		}

		if (BookIndex == (int)resultJSON.at("BookLibrary").size()) { return; }

		string ISBN = resultJSON.at("BookLibrary")[BookIndex].at("ISBN");

		if (!CreateRequestBorrowBook(ISBN)) {
			cout << "Yeu cau khong gui duoc" << endl;
			cout << "Bam enter de tiep tuc" << endl;
			system("pause");
			return;
		}

		cout << "Yeu cau da duoc gui," << endl;
		cout << "Cho xac nhan cua thu thu" << endl;
		cout << "Bam enter de quay ve" << endl;
		system("pause");
		return;
	}
}