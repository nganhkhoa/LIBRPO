/*
 * @CreateTime: Jun 19, 2017 3:58 PM
 * @Author: luibo
 * @Contact: ng.akhoa@yahoo.com.vn
 * @Last Modified By: luibo
 * @Last Modified Time: Jun 19, 2017 4:00 PM
 * @Description:
 *
 * Test tất cả trường hợp lúc đăng nhập
 * Yeah
 */


#include <gtest/gtest.h>

#include <CommonLib.h>

#include <Data/ReadDataJSON.h>
#include <Login/Login.h>

std::vector<std::string> right_names = {"khoa", "thuthao"};
std::vector<std::string> right_pwds  = {"1234", "1234"};


TEST(Login, EmptyData) {
	std::string username = "khoa";
	std::string pwd      = "123";

	// khi khong co du lieu

	nlohmann::json user_json = nlohmann::json::object();
	user_json["UserList"]    = nlohmann::json::array();
	UserDataJSON             = user_json;

	EXPECT_EQ(-1, ValidateUserLogin(username, pwd));

	ReadUserDataJSON();
}

TEST(Login, AllUserRightPassword) {

	int num_user = right_names.size();

	for (int index = 0; index < num_user; index++) {
		EXPECT_GT(
		  num_user, ValidateUserLogin(right_names[index], right_pwds[index]));
	}
}

TEST(Login, AllUserWrongPassword) {
	std::vector<std::string> pwds = {"aegasgdsgag", "aFASGASDGASGA"};

	int num_user = right_names.size();

	for (int index = 0; index < num_user; index++) {
		EXPECT_EQ(num_user, ValidateUserLogin(right_names[index], pwds[index]));
	}
}

TEST(Login, WrongUser) {
	std::vector<std::string> names = {"khoa123", "thuthaoabc"};

	int num_user = names.size();

	for (int index = 0; index < num_user; index++) {
		EXPECT_EQ(num_user, ValidateUserLogin(names[index], right_pwds[index]));
	}
}