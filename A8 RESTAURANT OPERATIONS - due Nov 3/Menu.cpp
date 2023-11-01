#include "Menu.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>

Menu::Menu(string filename) {
  ifstream finput(filename);
  string code, name;
  double price;

  finput >> numItems;
  while (finput.get() != '\n') {}

  items = new MenuItem[numItems];

  for (int i = 0; i < numItems; i++) {
    finput >> code >> name >> price;
    items[i] = MenuItem(code, name, price);
  }

  finput.close();
}

//search for specific code & return MenuItem pointer
//if code is not found, return NULL
MenuItem* Menu::find(string code) {
    for(int i=0; i<numItems; i++)
        if (code == items[i].getCode())
            return &items[i];  // same as items+i;
    return NULL;
}

void Menu::process() { //prompt, get one line input and process the line
    cout << "Enter your order string: ";
    string order, code;
    getline(cin, order);
    istringstream orderStream(order);

    double total=0;
    cout << fixed << setprecision(2);
    while (orderStream >> code) {
            MenuItem *itemp = find(code);
            if (itemp) { //valid?
                total += itemp->getPrice();
                cout << itemp->getName() << ":  $" << itemp->getPrice() << endl;
            } else
                cout << code << "is invalid. Skipping it.\n";
    }
    cout << "Total: $" << total << endl;
}