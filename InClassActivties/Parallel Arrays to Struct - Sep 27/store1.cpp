#include <iostream>
#include <iomanip> // input/output manipulation
#include <string>
#include <fstream>

using namespace std;

const int MAXPRODUCTS = 1000;

/*
int codes[MAXPRODUCTS]; 
string products[MAXPRODUCTS];
double prices[MAXPRODUCTS];
*/

// array of struct instead of serveral parallel arrays
//struct - user defined complex data stype, similar to class
struct Product {
   int code;
   string name;
   double price;
}; //C++ uses 48 bytes to store one struct

Product products[MAXPRODUCTS]; //48 * 1000 = 4800 bytes to allocate

int numProducts = 0;

//complete setup done here!
void setup()
{
    ifstream finput("products.txt");
    //get # of products first.
    finput >> numProducts;
    //get product codes, names & prices.
    for(int i=0; i<numProducts; i++)
        // finput >> codes[i] >> products[i] >> prices[i];
        finput >> products[i].code >> products[i].name >> products[i].price;
}

//list all the products available.
void listProducts()
{
    //list all the available products.
    cout << "Available products:\n";
    for(int i=0; i<numProducts; i++)
        // cout << codes[i] << ": " << products[i] << " @ " << prices[i] << "/pound.\n";
        cout << products[i].code << ": " << products[i].name << " @ " << products[i].price << "/pound.\n";
}

//return index of product with specified PLU
//return -1 if not found
int findIndex(int inputCode)
{
    //look for inputCode in codes[] array
    //return corresponding index!
    for(int i=0; i<numProducts; i++)
        // if (inputCode == codes[i])
        if (inputCode == products[i].code)
            return i;

    return -1;
}

int getUserSelection()
{
    int plu, selection = 0;

    while (true)
    {
        listProducts();
        cout << "Enter PLU (0 to end): ";
        cin >> plu;
        if (plu == 0)
            return -1;
        selection = findIndex(plu);
        if (selection >= 0)
            return selection;

        cout << "Invalid selection.\n";
    }
}

//checkout functionality for one customer
//returns the total amount
double checkout()
{
    double total = 0, weight = 0;

    cout <<fixed << setprecision(2);
    while (true)
    {
        int selection = getUserSelection();

        if (selection < 0)
            break;

        // cout << "Enter weight for " << products[selection] <<": ";
        cout << "Enter weight for " << products[selection].name <<": ";
        cin >> weight;

        // total += weight * prices[selection];
        total += weight * products[selection].price;

        cout << "Total so far: $ " << total << endl;
    }

    cout << "Final total: $ " << total << endl;
    return total;
}

int main()
{
    double grandTotal = 0;
    char response = 'n';

    setup();

    while (response == 'n')
    {
        grandTotal += checkout();
        cout << "(n)ext customer OR (c)lose the register? ";
        cin >> response;
    }

    cout << "Grand total: $" << grandTotal << endl;

    return 0;
}
