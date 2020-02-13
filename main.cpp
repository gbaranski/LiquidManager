#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "manageDatabase.h"
#include "liquids.h"
#include "systemFunctions.h"
using namespace std;

int main()
{
    bool albo;
    if (albo)
    {
        cout << "chuj";
    }
    SystemFunctions callSystemFunction;
    callSystemFunction.checkOS();
    callSystemFunction.clearConsole();
    int mainPick;
    cout << "Hello, what you want to do today?\n";
    cout << "1. I want to make a liquid\n";
    cout << "2. I want to see list of aromas in database \n";
    cout << "3. I want to add new aromas to database \n";
    cout << "4. I want to remove aroma from database \n";
    cin >> mainPick;
    Liquids liquids;
    AromasDatabase manageAromaDatabase;
    switch (mainPick)
    {
    case 1:
        liquids.newLiquidTab();
        break;
    case 2:
        manageAromaDatabase.readFile();
        break;
    case 3:
        manageAromaDatabase.addNewToFile();
        break;
    case 4:
        manageAromaDatabase.removeLineInFile();
        break;
    default:
        cout << "Select between 1 and 3";
        break;
    }
    return main();
}