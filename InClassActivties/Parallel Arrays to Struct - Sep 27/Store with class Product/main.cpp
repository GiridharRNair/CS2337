#include <iostream>
#include <iomanip> // input/output manipulation
#include <string>
#include <fstream>

# include "Product.h"

using namespace std;

Product *products;

int numProducts = 0;

//complete setup done here!
void setup()
{
    ifstream finput("products.txt");
    //get # of products first.
    finput >> numProducts;
    products = new Product [numProducts];

    //get product codes, names & prices.
    for(int i=0; i<numProducts; i++) {
        int code;
        string name;
        double price;
        finput >> code >> name >> price;
        products[i] = Product(code, name, price);
        // finput >> products[i].code >> products[i].name >> products[i].price;
    }
}

//list all the products available.
void listProducts()
{
    //list all the available products.
    cout << "Available products:\n";
    for(int i=0; i<numProducts; i++)
      cout << products[i].toString() << endl;
}

//return index of product with specified PLU
//return -1 if not found
int findIndex(int inputCode)
{
    //look for inputCode in codes[] array
    //return corresponding index!
    for(int i=0; i<numProducts; i++)
        if (inputCode == products[i].getCode())
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

        cout << "Enter weight for " << products[selection].getName() <<": ";
        cin >> weight;

        total += weight * products[selection].getPrice();

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
