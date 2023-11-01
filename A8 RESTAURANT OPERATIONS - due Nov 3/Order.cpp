#include "Order.h"
#include <sstream>
#include <iostream>
#include <iomanip>

Order::Order(string OrderString, Menu *menup)
{
  numItems = 0;
  addItems(OrderString, menup);
}

bool Order::addItems(string OrderString, Menu *menup) {
    string itemCode;
    stringstream ss(OrderString);
    
    while (ss >> itemCode) {
        MenuItem* menuItem = menup->find(itemCode);
        if (menuItem != nullptr) {
            items[numItems] = menuItem;
            numItems++;
            return true;
        } else {
            cout << "No item with code " << itemCode << endl;
            return false;
        }
    }
}

void Order::printReceipt(int tableNumber, int partyCount)
{
  cout << "Table " << tableNumber << " is closed. Here is the bill." << endl << endl;
  cout << "Receipt Table# " << tableNumber << " Party " << partyCount << endl;
  double total = 0.0;
  for (int i = 1; i < numItems; i++) {
    cout << items[i]->getCode() << "   " << items[i]->getName() << "   " << fixed << setprecision(2) << items[i]->getPrice() << endl;
    total += items[i]->getPrice();
  }

  cout << right << setw(26) << "Total  " << fixed << setprecision(2) << total << endl;
}


