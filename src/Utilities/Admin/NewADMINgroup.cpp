#include <Utilities/Utilities.h>
#include <SignUp/SignUp.h>

using namespace std;

void NewADMINgroup(unsigned int role) {
	NewUser NewCreation;

	enum GROUP
	{
		eLibrarian = 8,
		eAccountant,
		eAdmin
	};
	switch (role) {
		case eLibrarian:
			cout << "Dang ky thong tin cua thu thu moi" << endl;
			break;
		case eAccountant:
			cout << "Dang ky thong tin cua quan ly tai chinh moi" << endl;
			break;
		case eAdmin:
			cout << "Dang ky thong tin cua quan ly nguoi dung moi" << endl;
			break;
	}

	if (!NewCommonUser(NewCreation)) return;

	ExpandSignUp(NewCreation);
	NewCreation.Password = RandomPassword();
	NewCreation.UserID   = GenerateUserID();

	NewCreation.Account.AccountName    = NewCreation.Username;
	NewCreation.Account.AccountRoleMap = {role};
	if (!add_success(NewCreation)) {
		cout << "Rat tiec, loi da xay ra" << endl;
		cout << "Ban vui long thu lai sau" << endl;
		pausescreen();
		return;
	}
	ShowInfoAndBilling(NewCreation);
	return;
}