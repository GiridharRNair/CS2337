#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 10;
char matrix[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int n = 0;
int maxBalanced = 0; 
bool valid = false;

bool isInValid(int row, int column) {
  return (row < 0 || row >= n || column < 0 || column >= n || visited[row][column]);
}

void findMaxOpen(int row, int column, string parenthesis) { 
  if (isInValid(row, column)) {
    return;
  }

  visited[row][column] = true;

  parenthesis += matrix[row][column];
  valid = true;

  for (int i = 1; i <= 12; i++) {
    if (parenthesis.length() % 2 == 1) {
      valid = false;
      break;
    }

    if (parenthesis.length() < i * 2) {
      break;
    }

    if (parenthesis.length() != i * 2) {
      continue;
    } 

    for(int j = 0; j < i; j ++) {
      if(parenthesis[j] != '(') { 
        valid = false; 
        break; 
      }
    }

    for(int j = i; j < i * 2; j ++) {
      if(parenthesis[j] != ')') { 
        valid = false; 
        break; 
      }
    }
  }

  if (valid) {
    maxBalanced = max(maxBalanced, (int)parenthesis.length());
  }

  for (int i = 0; i < 4; i++) {
    int newRow = row + dr[i];
    int newCol = column + dc[i];
    findMaxOpen(newRow, column, parenthesis);
    findMaxOpen(row, newCol, parenthesis);
  }
  
  visited[row][column] = false;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) { 
    for (int j = 0; j < n; j++) { 
      visited[i][j] = false;
      cin >> matrix[i][j];
    }
  }

  if (matrix[0][0] == '(') {
    findMaxOpen(0, 0, "");
  }

  cout << maxBalanced << endl;
  return 0;
}
