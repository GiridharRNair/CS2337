#ifndef TABLE_H
#define TABLE_H

#include "Menu.h"
#include "Order.h"

//TABLE status: IDLE --> SEATED --> ORDERED --> SERVED

enum TableStatus { IDLE, SEATED, ORDERED, SERVED};
//                   0     1       2         3

class Table
{
    public:
        Table(int tableId, int capacity);
        bool seatParty(int numGuests);
        ~Table();

        // IDLE / ORDERED / SERVED --> ORDEDED
        bool placeOrder(string str, Menu *menup);
        bool serve(); // ORDERED --> SERVED
        bool cleanup(); // SERVED --> IDLE
        bool alreadyOrdered();
        int getCapacity();

    protected:

    private:
        int tableId, capacity;
        int partySize;
        TableStatus status; //status = IDLE;
        Order *orderp;
};

#endif // TABLE_H
