#include <iostream>
#include <fstream>
#include <sstream>
#include "Menu.h"
#include "Table.h"

using namespace std;

int main() {
    Menu menu("config.txt");

    ifstream finput("config.txt");
    int linesToSkip;
    finput >> linesToSkip;

    string configParseLine;

    for (int i = 0; i <= linesToSkip; i++) {
        if (std::getline(finput, configParseLine)) { }
    }

    Table **tables;
    int numTables, tableId, capacity;

    finput >> numTables;
    tables = new Table*[numTables];

    while (finput.get() != '\n') {}

    for (int i = 0; i < numTables; i++) {
        if (finput >> tableId >> capacity) {
            tables[i] = new Table(tableId, capacity);
        }
    }

    finput.close();

    // Read the commands and process them
    string line, tableNumber, command;

    while (getline(cin, line)) {
        istringstream istr(line);

        if (istr >> tableNumber >> command) {
            if (command[0] == 'P') {
                int numPeople = stoi(command.substr(1));
                if (tables[stoi(tableNumber) - 1]->seatParty(numPeople)) {
                    cout << "Party of " << numPeople << " assigned to Table " << tableNumber << endl;
                }
            } else if (command[0] == 'O') {
                string orderString;
                getline(istr, orderString);
                tables[stoi(tableNumber) - 1]->placeOrder(orderString, &menu);
            }else if (command[0] == 'C') {
                if (tables[stoi(tableNumber) - 1]->cleanup()) {
                    tables[stoi(tableNumber) - 1]->cleanup();
                } else {
                    cout << "Food not served for Table " << tableNumber << " yet!" << endl;
                }
            } else if (command[0] == 'S') {
                if (tables[stoi(tableNumber) - 1]->serve()) {
                    cout << "Food served in table " << tableNumber << endl;
                } else {
                    cout << "Order not placed at Table " << tableNumber << " yet!" << endl;
                }
            } 
        }
    }
        cout << endl;

    return 0;
}
