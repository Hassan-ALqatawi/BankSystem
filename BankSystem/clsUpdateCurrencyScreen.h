#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"


class clsUpdateCurrencyScreen:protected clsScreen
{
private:

    static float _ReadRate()
    {
        cout << "\nEnter New Rate: ";
        float NewRate = 0;

        NewRate = clsInputValidate::ReadFloatNumber();
        return NewRate;
    }

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCounter    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();
        cout << "\n___________________\n";

    }

public:

    static void ShowUpdateCurrencyScreen()
    {

        _DrawScreenHeader("\tUpdate Currency Screen");

        string Code = "";

        cout << "\nPlease Enter Code: ";
        Code = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(Code))
        {
            cout << "\nCode is not found, choose another one: ";
            Code = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(Code);
        _PrintCurrency(Currency);

        cout << "\nAre you sure you want to update this Rate y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Rate Info:";
            cout << "\n____________________\n";
           
            Currency.UpdateRate(_ReadRate());
            cout << "\n Currency Update Successfully .";
            _PrintCurrency(Currency);
        }

    }

};

