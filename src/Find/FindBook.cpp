/*
 * @CreateTime: Jun 18, 2017 10:11 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 18, 2017 10:11 PM
 * @Description: Tìm sách theo chuỗi và in ra rồi chọn
 */

#include <Find/FindBook.h>
#include <Browse/Browse.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void FindBook() {

	string core = "";
	SearchPhrase SearchThis;

	while (!SearchBookPrompt(SearchThis, core)) {
		cout << "Ban khong muon tim kiem nua? (y/n) ";
		string Answer = "";
		getline(cin, Answer);
		if (Answer == "y")
			return;
		else
			continue;
	}

	SearchAnalize(SearchThis, core);
	vector<string> result = ReadBookFromJson(SearchThis);

	if (result.size() == 0) {
		cout << "Khong tim thay bat cu ket qua nao" << endl;
		cout << "voi tu khoa" << endl;
		cout << "\t" << core << endl;
		return;
	}

	json resultJSON = ISBNtoJSON(result);

	ShowAllBook(resultJSON);

	return;
}


int FindBookBorrow(string& core, json& resultJSON) {

	SearchPhrase SearchThis;
	if (core != "--giosach") { SearchAnalize(SearchThis, core); }
	vector<string> result = ReadBookFromJson(SearchThis);

	if (result.size() == 0) {
		cout << "Khong tim thay bat cu ket qua nao" << endl;
		cout << "voi tu khoa:" << endl;
		cout << "\t" << core << endl;
		return -1;
	}

	resultJSON = ISBNtoJSON(result);

	return ShowBookResult(resultJSON) - 1;
}