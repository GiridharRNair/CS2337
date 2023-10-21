#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {
  string line;

  getline(cin, line);
  Polynomial p1(line);

  getline(cin, line);
  Polynomial p2(line);

  cout << p1 + p2 << endl;
  cout << p1 * p2 << endl;
}