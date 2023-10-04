# include "Complex.h"
# include <sstream> 
#include <iostream>
#include <cmath>
using namespace std;     

Complex::Complex(double rreal, double imag) {
  real = rreal; 
  imaginary = imag;
}

Complex::Complex(istream &inputStream) {
  inputStream >> real >> imaginary;
}


// add current object & second object
// return the total as new object
Complex Complex::add(Complex second) const {
  return  Complex(real + second.real, imaginary + second.imaginary);
}


void Complex::addTo(const Complex &second) {
  real += second.real;
  imaginary += second.imaginary;
}


double Complex::abs() const {
  return sqrt(real * real + imaginary * imaginary);
}

string Complex::toString() const {
  ostringstream ostr;
  ostr << "(" << real << ", " << imaginary << ")";
  return ostr.str();
}