#include <iostream>
#include <fstream>
#include <cstdlib>
#include "manageDatabase.h"
#include "systemFunctions.h"

using namespace std;
SystemFunctions callSystemFunctionInDatabase;

void AromasDatabase::readFile()
{
    callSystemFunctionInDatabase.clearConsole();
    ifstream aromasFileDatabase;
    aromasFileDatabase.open("aromasFileDatabase.txt");
    if (!aromasFileDatabase)
    {
        cout << "Couldn't open the file, creating new one \n";
        ofstream file{"aromasFileDatabase.txt"};
    }
    string textLine;
    size_t numLines = 0;
    while (getline(aromasFileDatabase, textLine))
    {
        ++numLines;
    }
    textLine.clear();
    aromasFileDatabase.clear(); // clear bad state after eof
    aromasFileDatabase.seekg(0);

    cout << "Total number of aromas: " << numLines << endl;
    string aroma[numLines];

    //zamienilem while na for
    for (int i = 0; getline(aromasFileDatabase, textLine); i++)
    {
        aroma[i] = textLine;
        cout << i + 1 << ". " << aroma[i] << endl;
    }
    callSystemFunctionInDatabase.pauseConsole();
    aromasFileDatabase.close();
}

void AromasDatabase::addNewToFile()
{
    callSystemFunctionInDatabase.clearConsole();
    ofstream aromasFileDatabase;
    aromasFileDatabase.open("aromasFileDatabase.txt", ios::app);
    if (!aromasFileDatabase)
    {
        cout << "Couldn't open the file";
    }
    string newAromaName;
    cout << "Write a name of aroma you want to add into database \n";
    getline(cin, newAromaName);
    aromasFileDatabase << newAromaName << endl;
    aromasFileDatabase.close();
}

void delete_line(const char *file_name, int lineToDelete)
{
    ifstream inputFile(file_name);
    if (!inputFile)
    {
        cout << "Couldn't open the file";
    }
    ofstream outputFile;
    outputFile.open("tempFile.txt", ofstream::out);
    char character;
    int line_no = 1;
    while (inputFile.get(character))
    {
        if (character == '\n')
            line_no++;

        if (line_no != lineToDelete)
            outputFile << character;
    }
    outputFile.close();
    inputFile.close();
    remove(file_name);
    rename("tempFile.txt", file_name);
}

void AromasDatabase::removeLineInFile()
{
    callSystemFunctionInDatabase.clearConsole();
    cout << "Write down a number of line to delete \n";
    int lineToDelete;
    cin >> lineToDelete;
    delete_line("aromasFileDatabase.txt", lineToDelete);
    cout << "Succefully deleted line " << lineToDelete;
    callSystemFunctionInDatabase.pauseConsole();
}
