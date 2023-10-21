#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Polynomial {
  public:
      Polynomial(string ppolynomialString);
      Polynomial(vector<int> ccoefficients);

      Polynomial operator+(const Polynomial &second) const;
      Polynomial operator*(const Polynomial &second) const;
      string toString() const;

      friend ostream& operator<< (ostream& stream, const Polynomial& attempt);

  private:
      vector<int> coefficients;  
};

#endif
