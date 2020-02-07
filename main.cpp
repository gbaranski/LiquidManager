#include <iostream>
#include "manageDatabase.h"
using namespace std;

int main()
{
    int mainPick;
    cout << "Hello, what you want to do today?\n";
    cout << "1. I want to see list of aromas in database \n";
    cout << "2. I want to add new aromas to database \n";
    cout << "3. I want to remove aroma from database \n";
    cin >> mainPick;
    AromasDatabase manageAromaDatabase;
    switch (mainPick)
    {
    case 1:
        manageAromaDatabase.readFile();
        break;
    case 2:
        manageAromaDatabase.addNewToFile();
        break;
    case 3:
        manageAromaDatabase.removeLineInFile();
        break;
    default:
        cout << "Select between 1 and 3";
        break;
    }
    return 0;
}