#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// WRITE YOUR CODE HERE

int main() {
  map<std::string, int> cowGroups;  
  int hours = 0;
  cin >> hours;


  for (int i = 0; i < hours; i++) {
    string cow1, cow2, cow3;
    cin >> cow1 >> cow2 >> cow3;
    vector<string> sortedCows = {cow1, cow2, cow3};
    sort(sortedCows.begin(), sortedCows.end());
    string sortedCowsComb = sortedCows[0] + sortedCows[1] + sortedCows[2];
    cowGroups[sortedCowsComb] += 1;
  }

  int currentMax = 0;
  string arg_max = "";
  for(map<string, int>::const_iterator it = cowGroups.cbegin(); it != cowGroups.cend(); ++it) {
      if (it -> second > currentMax) {
          arg_max = it -> first;
          currentMax = it -> second;
      }
  }

  cout << currentMax;
}