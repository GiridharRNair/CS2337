# include "Product.h"
#include <sstream>      // std::stringstream

using namespace std;

Product::Product(int ccode, string nname, double pprice) {
  code = ccode; //if parameter is the same as member: this->code = code;
  name = nname;
  price = pprice;
}

int Product::getCode() {
  return code;
}


string Product::getName() {
  return name;
}


double Product::getPrice() {
  return price;
}


string Product::toString() {
  ostringstream ostr;
  ostr << code << ": " << name << " @ " << price << "/pound.\n";
  return ostr.str();
}