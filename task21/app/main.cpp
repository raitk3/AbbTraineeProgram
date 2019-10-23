#include <iostream>

#include "data.h"
#include "database/database.h"
#include "table/table.h"


int main()
{
    Data d;
    std::cout << "Insert full path to your desired csv file, eg '..\\\\folder\\\\database.csv\n";
    std::cin >> d.database_location;
    //d.database_location = "C:\\Users\\EERAKUL\\Documents\\SWE_TraineeProgram_2019_RaitKulbok\\task21\\database.csv";
    d.hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    d.people = readFromCSV(d);
    draw(d);
    setCursorPosition(1, 1);
    while (true) {
        move(d);
    }
}
