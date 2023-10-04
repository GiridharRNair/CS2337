#include "Menu.h"
#include <fstream>
#include <sstream>

Menu::Menu(string filename)
{
    //open data file & read the menu items
    ifstream finput(filename);
    string code, name;
    double price;

    //first, let us find out how many items are there!
    numItems = 0;
    while (finput >> code >> name >> price)
        numItems++;
    finput.close();

    items = new MenuItem [numItems]; //allocate the array for MenuItem objects
    finput = ifstream(filename);
    for(int i=0; i<numItems; i++) {
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

void Menu::process() {
  cout << "Enter your order string: ";
  string order;
  getline(cin, order);
  istringstream orderStream(order);

  double total = 0;
  string code;
  while (orderStream >> code) {
    MenuItem* item = find(code);
    if (item == NULL) {
      cout << code << " is invalid. Skipping it.\n";
    } else {
      cout << item->getName() << ": $" << fixed << setprecision(2) << item->getPrice() << endl;
      total += item->getPrice();
    }
  }
  cout << "Total: $" << total << endl;
}

