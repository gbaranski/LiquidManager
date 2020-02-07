#include <iostream>
#include <fstream>
#include <cstdlib>
#include "manageDatabase.h"
using namespace std;

void AromasDatabase::readFile()
{
    ifstream aromasFileDatabase;
    aromasFileDatabase.open("aromasFileDatabase.txt");
    if (!aromasFileDatabase)
    {
        //Handle error
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

    cout << "Total number of lines: " << numLines << endl;
    string aroma[numLines];

    //zamienilem while na for
    for (int i = 0; getline(aromasFileDatabase, textLine); i++)
    {
        aroma[i] = textLine;
        cout << aroma[i] << endl;
    }
    aromasFileDatabase.close();
}

void AromasDatabase::addNewToFile()
{
    ofstream aromasFileDatabase;
    aromasFileDatabase.open("aromasFileDatabase.txt", ios::app);
    if (!aromasFileDatabase)
    {
        //Handle error
    }
    string newAromaName;
    cout << "Write a name of aroma you want to add into database \n";
    cin >> newAromaName;
    aromasFileDatabase << newAromaName << endl;
    aromasFileDatabase.close();
}

void delete_line(const char *file_name, int lineToDelete)
{
    ifstream inputFile(file_name);
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
    cout << "Write down a number of line to delete \n";
    int lineToDelete;
    cin >> lineToDelete;
    delete_line("aromasFileDatabase.txt", lineToDelete);
}
