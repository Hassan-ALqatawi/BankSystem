
#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>

class clsListCurrancyScreen:protected clsScreen
{

    static void _PrintCurrencyRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(32) << left << Currency.Country();
        cout << "| " << setw(8) << left << Currency.CurrencyCode();
        cout << "| " << setw(44) << left << Currency.CurrencyName();
        cout << "| " << setw(12) << left << Currency.Rate();

    }

public:

    static void ShowCurrencyList()
    {
        vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();

        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrency.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(32) << "Country";
        cout << "| " << left << setw(8) << "code";
        cout << "| " << left << setw(44) << "Name";
        cout << "| " << left << setw(12) << "Rate($)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vCurrency.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsCurrency Currency : vCurrency)
            {

                _PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }


};

