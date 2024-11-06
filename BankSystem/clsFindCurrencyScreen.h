#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsFindCurrencyScreen:protected clsScreen 
{
private:
    enum enFind
    {
        eFindByCode = 1 , eFindByCounter = 2
    };

    static short _ReadCurrencyFind()
    {
        cout  << " Find By : [1] Code or [2] Counter ? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter Number between 1 to 2? ");
        return Choice;
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

    static void _FindByCode() {
        string Code;
        cout << "\nPlease Enter Code: ";
        Code = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(Code))
        {
            cout << "\nCode is not found, choose another one: ";
            Code = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(Code);
        if (!Currency.IsEmpty())
        {
            cout << "\nCode Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCode Was not Found :-(\n";
        }

        
    }

    static void _FindByCounter() {
        string Counter;
        cout << "\nPlease Enter Counter: ";
        Counter = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(Counter))
        {
            cout << "\nCounter is not found, choose another one: ";
            Counter = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCountry(Counter);
        if (!Currency.IsEmpty())
        {
            cout << "\nCounter Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCounter Was not Found :-(\n";
        }

        
    }

    static void  _PerfromCurrencyFindOption(enFind Find) {

        switch (Find)
        {
        case clsFindCurrencyScreen::eFindByCode:

            _FindByCode();

            break;
        case clsFindCurrencyScreen::eFindByCounter:
            _FindByCounter();

            break;
      
        }

    }

public:
    static void ShowFindCurrencyScreen()
    {

        _DrawScreenHeader("\t  Find Currency Screen");

        _PerfromCurrencyFindOption((enFind)_ReadCurrencyFind());
      
        

    }


};

