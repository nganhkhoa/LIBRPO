#include <Find/Find.h>
#include <Find/FindBook.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

unsigned int FindBookIndex(string& ISBN) {
	unsigned int book_num = BookDataJSON.at("BookLibrary").size();
	for (unsigned int index = 0; index < book_num; index++) {
		string ISBN_DATA = BookDataJSON.at("BookLibrary")[index].at("ISBN");
		if (ISBN_DATA == ISBN) return index;
	}
}

json ISBNtoJSON(vector<string>& result) {
	json bookdata = json::object();
	bookdata["BookLibrary"] = json::array();

	json newbook = json::object();

	for (unsigned int result_index = 0; result_index < result.size(); result_index++) {
		string ISBN = result[result_index];
		unsigned int book_index = FindBookIndex(ISBN);

		bookdata.at("BookLibrary")[result_index] =
		  BookDataJSON.at("BookLibrary")[book_index];
	}
	return bookdata;
}