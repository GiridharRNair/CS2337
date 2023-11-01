#ifndef ORDER_H
#define ORDER_H

#include "Menu.h"

// const int MAX_ITEMS_IN_ORDER = 100;

class Order
{
    public:
        // "A1 A2 B1"
        Order(string OrderString, Menu *menup);
        bool addItems(string OrderString, Menu *menup);
        void printReceipt(int tableNumber, int partyCount);

    protected:

    private:
        static const int MAX_ITEMS_IN_ORDER = 100;
        int numItems;
        MenuItem *items[MAX_ITEMS_IN_ORDER];
};

#endif // ORDER_H
