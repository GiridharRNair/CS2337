#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {
    istringstream lineInput(line);
    string word;
    vector<double> numbersArr;
    vector<string> wordsArr;

    // Get one word at a time!
    while (lineInput >> word) {
      double value;
      // Is the word a number or a string?
      if (istringstream(word) >> value) {
          // Number!
          numbersArr.push_back(value);
      } else {
          // String!
          wordsArr.push_back(word);
      }
    }

    for (string keyword : wordsArr) {
      if (keyword == "total") {
        double total = 0;
        for (double number : numbersArr) {
          cout << number << " ";
          total += number;
        }
        cout << "total " << total << "\n";
      } else if (keyword == "average") {
        double total = 0;
        for (double number : numbersArr) {
          cout << number << " ";
          total += number;
        }
        cout << "average " << total / numbersArr.size() << "\n";
      } else if (keyword == "max") {
        double max_value = -numeric_limits<double>::infinity();
        for (double number : numbersArr) {
          cout << number << " ";
          if (number > max_value) {
            max_value = number;
          }
        }
        cout << "max " << max_value << "\n";
      } else if (keyword == "min") {
        double min_value = numeric_limits<double>::infinity();
        for (double number : numbersArr) {
          cout << number << " ";
          if (number < min_value) {
            min_value = number;
          }
        }
        cout << "min " << min_value << "\n";
      } else if (keyword == "bye") {
        cout << "OK bye!";
        break;
      } else if (keyword == "tell") {
        cout << "tell me the purpose of life - I am not yet that smart to answer this one!\n";
      } else if (keyword == "Are") {
        cout << "Are you really smart? - I am not yet that smart to answer this one!\n";
      } 
    }
  }

  return 0;
}
