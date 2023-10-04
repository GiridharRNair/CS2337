#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

const int MAXPRODUCTS = 100;
string names[MAXPRODUCTS];
double prices[MAXPRODUCTS];
string codes[MAXPRODUCTS];
int numProducts = 0;

void readConfiguration() {
    ifstream finput("menu.txt");
    while (finput >> codes[numProducts] >> names[numProducts] >> prices[numProducts])
        numProducts++;
    cout << numProducts << " items loaded.\n";
}

//return valid index if the item is found, return -1 otherwise.
int findItem(string inputCode) {
    //code here!
    for(int index=0 ; index<numProducts; index++)
        if (inputCode == codes[index])
            return index;

    return -1;
}

// read order string like “A1 A1 E1 E2 S1” and generate the restaurant bill.
// Output the item name and price in each line, total in the final line.
void process() {
    double total = 0;
    string line, code;
    int index;

    cout << "Enter your order string: ";
    getline(cin, line);
    istringstream istr(line);
    //get one code at a time from line, validate it, find the price & total it up.
    while (istr >> code) {
        //code here!
        if ((index = findItem(code)) < 0) {
            cout << code << " is invalid. Skipping it.\n";
        } else { //valid item!
            cout << names[index] << ": $" << fixed << setprecision(2) << prices[index] << endl;
            total += prices[index];
        }
    }
    cout << "Total: $" << total << endl;
}

int main() {
   readConfiguration();

   process();
}
