#include <iostream>
using namespace std;

//MAXROWS is same as MAXCOLUMNS or BOARDSIZE
const int MAXROWS = 20;

//queens' placements in each row
int placements[MAXROWS];
int n = 0;
int solutionsCount = 0;

//space for additional functions if needed
// WRITE YOUR CODE HERE
bool acceptable(int row, int col) {
  for (int i = 0; i < row; i++) {
    if (placements[i] == col || abs(i - row) == abs(placements[i] - col)) {
      return false;
    }
  }
  return true;
}

void placeQueens(int row) {
// WRITE YOUR CODE HERE
  if (row == n) {
    solutionsCount++;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (acceptable(row, i)) {
      placements[row] = i;
      placeQueens(row + 1);
    }
  }
}

int main() {
  cin >> n;

	placeQueens(0);
	cout << solutionsCount;
}

