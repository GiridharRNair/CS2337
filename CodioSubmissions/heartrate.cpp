#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
// WRITE YOUR CODE HERE
  int age = 0, counter = 0, total = 0, data = 0;
  string fileName, dataStr;
  cin >> age >> fileName;
  ifstream finput(fileName);
  int maxLimit = 220 - age;
  while (!finput.eof()) {
    if (finput >> data) {
      total++;
      if (data <= maxLimit) {
        counter++;
      }
    } else {
      finput.clear();
      finput.ignore(1000, '\n');
    }
  }
  double percentage = ((counter  * 100.0) / total);
  cout << fixed << setprecision(1) << percentage << "%"; 
}
