/*
 * @CreateTime: Jun 18, 2017 10:11 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 18, 2017 10:11 PM
 * @Description: Đưa từ vector<string> ISBN về json chứa thông tin sách
 * Vì có hàm hiện thực in chia trang và chọn với thông số json
 */

#include <Find/Find.h>
#include <Find/FindBook.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

json ISBNtoJSON(vector<string>& result) {
	json bookdata           = json::object();
	bookdata["BookLibrary"] = json::array();

	json newbook = json::object();

	for (unsigned int result_index = 0; result_index < result.size();
	     result_index++) {
		string ISBN             = result[result_index];
		unsigned int book_index = FindBookIndex(ISBN);

		bookdata.at("BookLibrary")[result_index] =
		  BookDataJSON.at("BookLibrary")[book_index];
	}
	return bookdata;
}