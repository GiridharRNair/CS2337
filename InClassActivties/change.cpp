#include <iostream>

using namespace std;

int coinValues[] = {25, 10, 5, 1};
int numCoins = 4;

//counter for all possible combinations to reach the total
int numCombinations = 0;

//count all the coin combinations to reach remainingTotalCents
//using the coins at currentIndex and beyond...
void change(int currentIndex, int remainingTotalCents) {
// WRITE YOUR CODE HERE
  if (remainingTotalCents == 0) {
    numCombinations++;
  }
  if (remainingTotalCents <= 0 || currentIndex == numCoins) {
    return;
  }
  change(currentIndex + 1, remainingTotalCents);
  change(currentIndex, remainingTotalCents - coinValues[currentIndex]);
}

int main() {
    int totalCents;
    cin >> totalCents;
    change(0, totalCents);
    cout << numCombinations;
}
