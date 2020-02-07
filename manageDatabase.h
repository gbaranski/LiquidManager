#include <iostream>

using namespace std;

class AromasDatabase
{
public:
    void readFile();     //wczytuje pytania z pliku
    void addNewToFile(); //pokazuje pytanie, czyta odpowiedz
    void removeLineInFile();
};