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

    double baseStrength = 0;
    double dilutionBaseStrength = 0;
    double aromaPercent = 0;
    double glicerinePercent = 0;
    double additivesPercent = 0;

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

    double y3 = 0;

    double resultGlicerineAmount = glicerinePercent + additivesPercent;
    double x3 = amountOfLiquid * resultGlicerineAmount / 100;
    double resultDilutionBaseAmount = (liquidStrength * amountOfLiquid + baseStrength * (x3 + aromaPercent - amountOfLiquid)) / (dilutionBaseStrength - baseStrength);
    double resultBaseAmount = amountOfLiquid - resultDilutionBaseAmount - x3 - aromaPercent;
    string resultString;
    if (amountOfLiquid <= 0)
    {
        resultString = "Invalid amount of liquid(it must be higher than 0)";
    }
    else
    {
        if (glicerinePercent >= 100)
            resultString = "Invalid proportions of additives and glicerine";
        else if (resultDilutionBaseAmount < 0 || resultBaseAmount < 0)
            resultString = "Invalid proportions of dilution base and nicotine base";
        else
        {
            amountOfLiquid = resultBaseAmount + resultDilutionBaseAmount + x3 + aromaPercent;
            if (resultGlicerineAmount > 0)
            {
                double z1 = (glicerinePercent / resultGlicerineAmount) * x3;
                double z2 = (x3 - z1);
                cout << "======== To make ========" << endl
                     << amountOfLiquid << endl
                     << "with strength of " << liquidStrength << "mg " << endl
                     << "";
            }
        }
    }

    cout << "======== You'll need ========" << endl;
    cout << resultBaseAmount << "ml of nicotine base" << endl
         << resultDilutionBaseAmount << "ml of dillution base" << endl
         << resultGlicerineAmount << "ml of glicerine"
         << aromaPercent << "ml of aroma"
         << x3 << "dsaasd";
    callSystemFunctionInNewLiquid.pauseConsole();
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
        ingredientsToAchieve();
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