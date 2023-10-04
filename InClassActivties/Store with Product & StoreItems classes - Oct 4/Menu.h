//FREEZE CODE BEGIN
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "MenuItem.h"

using namespace std;

class Menu
{
    public:
        Menu(string filename);

        //search for specific code & return MenuItem pointer
        //if code is not found, return NULL
        MenuItem *find(string code);

        void process(); // read order string like “A1 A1 E1 E2 S1” and generate the restaurant bill.
                        // Output the item name and price in each line, total in the final line.

        virtual ~Menu();

    protected:

    private:
        MenuItem *items; //for array of MenuItem objects
        int numItems;    //count of MenuItem objects
};
#endif // MENU_H
//FREEZE CODE END