#include <iostream>
using namespace std;

int main()
{ 
  int totalBowls = 0, numDays = 0, bowlNum = 0, count = 0;
  cin >> totalBowls >> numDays >> bowlNum;
  for (int index = 0; index < numDays; index++) {
    int topBowl = 0;
    cin >> topBowl;
    if (topBowl >= bowlNum) {
      count++;
    }
  }
  cout << count;
  return 0;
}