#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:



    static  bool _Login()
    {
        bool LoginFaild = false;

        string Username, Password;
        short Trials = 0;
        do
        {

            if (LoginFaild)
            {
                Trials++;
                cout << "\nInvlaid Username/Password!";
                cout << "\nYou have "<<3 - Trials<<" Trials to Login \n\n";
            }
            if (Trials == 3) {

                cout << "\n Your are locked after 3 faild trails." << endl;
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();

    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
      return  _Login();

    }

};



