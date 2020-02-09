#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "systemFunctions.h"
using namespace std;
string yourOS;

void SystemFunctions::checkOS()
{
    int configLineNumber = 1;
    string readConfigLine;
    ifstream config;
    config.open("config.txt");
    if (!config)
    {
        cout << "Couldn't open the config file, creating new one \n";
        ofstream file{"config.txt"};
    }

    while (getline(config, readConfigLine))
    {
        switch (configLineNumber)
        {
        case 1:
            yourOS = readConfigLine;
            break;
        }
        configLineNumber++;
    }
    config.close();
    if (yourOS == "")
    {
        cout << "You're running program for the first time \n";
        cout << "Please define what OS you're running \n";
        cout << "1. Linux \n";
        cout << "2. Windows \n";
        int osPick;
        cin >> osPick;
        ofstream config;
        config.open("config.txt");
        switch (osPick)
        {
        case 1:
            yourOS = "Linux";
            break;
        case 2:
            yourOS = "Windows";
            break;
        default:
            cout << "Please type in 1 or 2";
            break;
        }
        config << yourOS << endl;
        config.close();
    }
    else
    {
        cout << "You're using " << yourOS << " right? If dont agree change the config.txt file. \n";
    }
}

void SystemFunctions::clearConsole()
{
    if (yourOS == "Linux")
    {
        system("clear");
    }
    else if (yourOS == "Windows")
    {
        system("cls");
    }
}
void SystemFunctions::pauseConsole()
{
    cout << endl;
    cout << "Press any key to continue";
    cin.ignore();
    cin.get();
}