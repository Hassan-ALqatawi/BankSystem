
#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrancyScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"


using namespace std;

class clsCurrencyExchangeScreen :protected clsScreen
{
private:
    enum enCurrencyMenueOptions
    {
        eListCurrency = 1, eFindCurrency = 2, eUpdateRate = 3, 
        eCurrencyCalcuiator = 4, eMainMenue = 5
    };

    static short _ReadCurrencyMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static  void _GoBackToCurrencyMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowCurrencyExchange();
    }

    static void _ShowListCurrency() {
        clsListCurrancyScreen::ShowCurrencyList();
    }
    static void _ShowFindCurrency() {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateRate() {
        clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
    }
      static void _ShowCurrencyCalcuiator() {
          clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }


    static void _PerfromCurrencyMenueOption(enCurrencyMenueOptions CurrencyMenueOptions) {
        switch (CurrencyMenueOptions)
        {
        case clsCurrencyExchangeScreen::eListCurrency:
            system("cls");
            _ShowListCurrency();
            _GoBackToCurrencyMenue();
            break;
        case clsCurrencyExchangeScreen::eFindCurrency:
            system("cls");
            _ShowFindCurrency();
            _GoBackToCurrencyMenue();
            break;
        case clsCurrencyExchangeScreen::eUpdateRate:
            system("cls");
            _ShowUpdateRate();
            _GoBackToCurrencyMenue();
            break;
        case clsCurrencyExchangeScreen::eCurrencyCalcuiator:
            system("cls");
            _ShowCurrencyCalcuiator();
            _GoBackToCurrencyMenue();
            break;
        case clsCurrencyExchangeScreen::eMainMenue:
            break;
   
        }
    }

public:

    static void  ShowCurrencyExchange() {

        system("cls");
        _DrawScreenHeader("\t   Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currency.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calcuiator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromCurrencyMenueOption((enCurrencyMenueOptions)_ReadCurrencyMenueOption());

    }

};

