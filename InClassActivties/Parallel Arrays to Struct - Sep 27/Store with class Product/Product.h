#include <iostream>
#include <iomanip> // input/output manipulation
#include <string>
#include <fstream>

using namespace std;

class Product {
  public:
    Product(int ccode=0, string nname="", double pprice=0);
    int getCode();
    string getName();
    double getPrice();
    string toString();

  private:
    int code;
    string name;
    double price;
};