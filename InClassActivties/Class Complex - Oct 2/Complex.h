#include <iostream>
#include <iomanip> // input/output manipulation
#include <string>
#include <fstream>

using namespace std;

class Complex {
  public:
    Complex(double rreal, double imag);
    Complex(istream &inputStream);
  
    Complex add(Complex second) const;
    void addTo(const Complex &second);
    double abs() const;
    string toString() const;

  private:
    double real;
    double imaginary;
};