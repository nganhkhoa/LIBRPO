/*
 * @CreateTime: Jun 19, 2017 3:58 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: undefined
 * @Last Modified Time: Jun 25, 2017 9:31 AM
 * @Description:
 *
 * Test tất cả trường hợp lúc đăng nhập
 * Yeah
 *
 * Còn thiếu
 * (mã hoá)
 * nếu là lần đầu đăng nhập, không hash chuỗi nhập vào
 * nếu không phải lần đầu, hash chuỗi nhập và so sánh
 */


#include <gtest/gtest.h>

#include <CommonLib.h>

#include <Data/ReadDataJSON.h>
#include <Login/Login.h>

std::vector<std::string> right_names = {"khoa", "khoi", "nam"};
std::vector<std::string> right_pwds  = {"1234", "2345", "aaaa"};

// sample data
nlohmann::json sampleUserDataJSON = {{"UserList",
                                      {{{"Username", right_names[0]},
                                        {"Password", right_pwds[0]},
                                        {"First", false}},
                                       {{"Username", right_names[1]},
                                        {"Password", right_pwds[1]},
                                        {"First", false}},
                                       {{"Username", right_names[2]},
                                        {"Password", right_pwds[2]},
                                        {"First", false}}}}};

TEST(Login, EmptyData) {

	// khi khong co du lieu

	nlohmann::json user_json = nlohmann::json::object();
	user_json["UserList"]    = nlohmann::json::array();
	UserDataJSON             = user_json;

	int num_user = right_names.size();

	for (int index = 0; index < num_user; index++) {
		EXPECT_EQ(-1, ValidateUserLogin(right_names[index], right_pwds[index]));
	}
}


TEST(Login, AllUserRightPassword) {

	UserDataJSON = sampleUserDataJSON;

	int num_user = right_names.size();

	for (int index = 0; index < num_user; index++) {
		EXPECT_GT(
		  num_user, ValidateUserLogin(right_names[index], right_pwds[index]));
	}
}

TEST(Login, AllUserWrongPassword) {

	UserDataJSON = sampleUserDataJSON;

	std::vector<std::string> pwds = {
	  "sgkjasldkg", "asdlkgjalskdgj", "alskdgjlksdgj"};

	int num_user = right_names.size();

	for (int index = 0; index < num_user; index++) {
		EXPECT_EQ(num_user, ValidateUserLogin(right_names[index], pwds[index]));
	}
}

TEST(Login, WrongUser) {

	UserDataJSON = sampleUserDataJSON;

	std::vector<std::string> names = {"khoa123", "khoi1111", "nam2424"};

	int num_user = names.size();

	for (int index = 0; index < num_user; index++) {
		EXPECT_EQ(num_user, ValidateUserLogin(names[index], right_pwds[index]));
	}
}