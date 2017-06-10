#include <modify.h>

using namespace std;
using json = nlohmann::json;

bool delete_success(string& userIDtobedeleted) {

	json& userdata = UserDataJSON;

	/* Delete but still there
	// if usernum and account num is to be reserved
	userdata.at("UserList")[0].clear();
	//*/

	/* Delete the whole user
	// no trace of user
	json new_data = json::array();


	bool deleted = false;
	string ID_tobedeleted = "001";
	int num_user = userdata.at("UserList").size();

	for(int i = 0; i < num_user; i++) {
	    string UserID = userdata.at("UserList")[i].at("UserID");
	    if (UserID == ID_tobedeleted) {deleted = true; continue;}
	    if (deleted) {
	        new_data[i - 1] = userdata.at("UserList")[i];
	    } else {
	        new_data[i] = userdata.at("UserList")[i];
	    }
	}

	userdata.at("UserList").clear();
	userdata.at("UserList") = new_data;
	//*/


	//* Delete the user but put in archive
	/// This is to be recommended

	json new_data    = json::array();
	json delete_data = json::array();

	bool deleted           = false;
	string& ID_tobedeleted = userIDtobedeleted;
	int num_user           = userdata.at("UserList").size();
	int num_deleted_user   = userdata.at("Deleted").size();

	for (int i = 0; i < num_deleted_user; i++) {
		delete_data[i] = userdata.at("Deleted")[i];
	}

	for (int i = 0; i < num_user; i++) {
		string UserID = userdata.at("UserList")[i].at("UserID");
		if (UserID == ID_tobedeleted) {
			deleted                       = true;
			delete_data[num_deleted_user] = userdata.at("UserList")[i];

			continue;
		}
		if (deleted) { new_data[i - 1] = userdata.at("UserList")[i]; }
		else {
			new_data[i] = userdata.at("UserList")[i];
		}
	}

	if (!deleted) {
		cout << "User not found to delete" << endl;
		system("pause");
		return false;
	}

	userdata.at("UserList").clear();
	userdata.at("Deleted").clear();
	userdata.at("UserList") = new_data;
	userdata.at("Deleted")  = delete_data;

	//*/
	return true;
}