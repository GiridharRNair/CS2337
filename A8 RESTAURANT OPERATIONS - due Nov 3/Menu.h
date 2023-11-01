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

        void process(); //prompt, get one line input and process the line

    protected:

    private:
        MenuItem *items; //for array of MenuItem objects
        int numItems;    //count of MenuItem objects
};
#endif // MENU_H