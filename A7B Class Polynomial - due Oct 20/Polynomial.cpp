#include "Polynomial.h"
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


std::vector<int> reverseCopyVector(const std::vector<int> &original) {
    std::vector<int> reversedCopy;
    
    // Iterate through the original vector in reverse order and append elements to the copy.
    for (int i = original.size() - 1; i >= 0; --i) {
        reversedCopy.push_back(original[i]);
    }

    return reversedCopy;
}

Polynomial::Polynomial(string polynomialString) {
  istringstream ss(polynomialString);
  int coeff;
  while (ss >> coeff) {
    coefficients.push_back(coeff);
  }
}

Polynomial::Polynomial(vector<int> ccoefficients) {
  for (int i = 0; i < ccoefficients.size(); i++) {
    coefficients.push_back(ccoefficients[i]);
  }
}

Polynomial Polynomial::operator+(const Polynomial &second) const {
  vector<int> resultCoefficients;
  vector<int> coefficientsReversed = reverseCopyVector(coefficients);
  vector<int> secondCoefficientsReversed = reverseCopyVector(second.coefficients);
  size_t maxSize = max(coefficients.size(), second.coefficients.size());
  for (size_t i = 0; i < maxSize; ++i) {
    int coeff1 = (i < coefficients.size()) ? coefficientsReversed[i] : 0;
    int coeff2 = (i < second.coefficients.size()) ? secondCoefficientsReversed[i] : 0;
    resultCoefficients.push_back(coeff1 + coeff2);
  }
  return Polynomial(reverseCopyVector(resultCoefficients));
}


Polynomial Polynomial::operator*(const Polynomial &second) const {
  vector<int> resultCoefficients;
  resultCoefficients.resize(coefficients.size() + second.coefficients.size() - 1, 0);

  for (size_t i = 0; i < coefficients.size(); ++i) {
    for (size_t j = 0; j < second.coefficients.size(); ++j) {
      resultCoefficients[i + j] += coefficients[i] * second.coefficients[j];
    }
  }

  return Polynomial(resultCoefficients);
}

string Polynomial::toString() const {
  stringstream ss;
  int degree = coefficients.size() - 1;

  for (int i = 0; i < coefficients.size(); ++i) {
    ss << coefficients[i] << " ";
  }

  return ss.str();
}


ostream &operator<<(ostream &stream, const Polynomial &attempt) {
  stream << attempt.toString();
  return stream;
}

