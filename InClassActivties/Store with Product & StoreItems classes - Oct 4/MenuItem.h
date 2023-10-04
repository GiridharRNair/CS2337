//FREEZE CODE BEGIN
#ifndef MENUITEM_H
#define MENUITEM_H
#include <iostream>

using namespace std;

class MenuItem
{
    public:
        MenuItem(string ccode, string nname, double pprice);
        string getCode();
        string getName();
        double getPrice();
        virtual ~MenuItem();

    protected:

    private:
        string code, name;
        double price;
};

#endif // MENUITEM_H
//FREEZE CODE END