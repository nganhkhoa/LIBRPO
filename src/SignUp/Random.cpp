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