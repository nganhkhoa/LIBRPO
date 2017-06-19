#include <gtest/gtest.h>

#include <Login/Login.h>

TEST(demo, firsttest) {
	std::string username = "khoa";
	std::string pwd      = "123";

	// sai mật khẩu

	int num_user = UserDataJSON.at("UserList").size();
	EXPECT_GT(num_user, ValidateUserLogin(username, pwd));
}