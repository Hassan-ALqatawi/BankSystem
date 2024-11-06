#pragma once

#include <iostream>
#include "Global.h"
#include "clsUser.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{

protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "") {

		cout << "\n \t\t\t\t____________________________________________________________________ ";
		cout << "\n\n \t\t\t\t\t" << Title;
		if (SubTitle != "")
		{
			cout << "\n \t\t\t\t\t" << SubTitle;
		}
		cout << "\n \t\t\t\t____________________________________________________________________\n ";

		cout << "\n \t\t\t\t\t User : " << CurrentUser.UserName;
		cout << "\n \t\t\t\t\t Date : " << clsDate::DateToString(clsDate()) << "\n\n";

	}

	static bool CheckAccessRights(clsUser::enPermissions Permission) {
		
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\n\t\t\t\t\t______________________________________________";
			cout << "\n\n\t\t\t\t\t   Access Denied ! Contact Your Access ";
			cout << "\n\t\t\t\t\t______________________________________________";
			return false;
		}
		else
			return true;

	}

};

