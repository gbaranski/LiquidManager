#include <iostream>
#include <fstream>
#include <cstdlib>
#include "liquids.h"
#include "systemFunctions.h"
using namespace std;
SystemFunctions callSystemFunctionInNewLiquid;

void Liquids::ingredientsToAchieve()
{
    int amountOfLiquid = 0;
    int liquidStrength = 0;

    cout << "======== What you want to achieve? ========";
    cout << endl
         << "Amount of liquid: ";
    cin >> amountOfLiquid;

    cout << endl
         << "Nicotine strength: ";
    cin >> liquidStrength;

    int baseStrength = 0;
    int dilutionBaseStrength = 0;
    int aromaPercent = 0;
    int glicerinePercent = 0;
    int additivesPercent = 0;

    cout << "======== What do you have with you? ========";

    cout << endl
         << "Strength of base [mg/ml]: ";
    cin >> baseStrength;

    cout << endl
         << "Strength of dillution base, most common is 0mg [mg/ml]: ";
    cin >> dilutionBaseStrength;

    cout << endl
         << "!OPTIONAL! Amount of aroma in result liquid [%]: ";
    cin >> aromaPercent;

    cout << endl
         << "!OPTIONAL! Amoung of glicerine in result liquid [%]: ";
    cin >> glicerinePercent;

    cout << endl
         << "!OPTIONAL! Amount of additives e.g alcohol in result liquid [%]";
    cin >> additivesPercent;

    int resultBaseAmount = amountOfLiquid / (baseStrength / dilutionBaseStrength);
    int resultDilutionBaseAmount = liquidStrength;
    int resultAromaAmount;
    int resultGlicerineAmount;
    int resultAdditivesPercent;
}
void Liquids::achieveProperNic()
{
    cout << "2";
}
void Liquids::resultantMixing()
{
    cout << "3";
}
void Liquids::newLiquidTab()
{
    callSystemFunctionInNewLiquid.clearConsole();
    cout << "What would you like to achieve\n";
    cout << "1. Amount of ingredients needed to achieve proper amount of liquid\n"; // ingredientsToAchieve
    cout << "2. Amount of liquid needed to achieve proper nicotine strength\n";     // achieveProperNic
    cout << "3. Resultant nicotine strength after mixing few liquids\n";            // resultantMixing

    int newLiquidPick;
    cin >> newLiquidPick;
    switch (newLiquidPick)
    {
    case 1:
        cout << "1";
        break;
    case 2:
        cout << "2";
        break;
    case 3:
        cout << "3";
        break;
    default:
        cout << "Select between 1 and 4";
        break;
    }
}