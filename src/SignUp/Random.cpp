/*
 * @CreateTime: Jun 18, 2017 10:05 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: undefined
 * @Last Modified Time: Jun 18, 2017 10:06 PM
 * @Description:
 * 		Random mật khẩu
 * 		Lấy mã số người dùng là số giây hệ thống
 * 		Vì không bao giờ tạo được 2 người cùng một lúc
 * 		
 * 	Random chuỗi lấy trên mạng. Xin các vị thứ lỗi
 * 	Cũng thật sự là không hiểu nó viết gì.
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <string>

#include <SignUp/SignUp.h>


using namespace std;


string RandomPassword() {

	string randomString;
	size_t size = PWD_LENGHT;

	std::random_device rd;
	std::mt19937 mt(rd());
  	std::uniform_int_distribution<int> dist('a', 'z'); 

	std::generate_n(std::back_inserter(randomString), size, [&]{return dist(mt);});

	cout << randomString << endl;
	return randomString;
}
string GenerateUserID() {
	string randomString = "";
	time_t now = time(NULL);
	randomString = to_string(now);
	return randomString;
}