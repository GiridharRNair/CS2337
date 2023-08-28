#include <iostream>
#include <iomanip>

using namespace std;

// A -> 4, B -> 3, C -> 2, D -> 1, otherwise return 0
int letterToPoints(char grade) {
// WRITE YOUR CODE HERE
  if (grade == 'A') {
      return 4;
  } else if (grade == 'B') {
      return 3;
  } else if (grade == 'C') {
      return 2;
  } else if (grade == 'D') {
      return 1;
  } else {
      return 0;
  }
}

int main() {
// WRITE YOUR CODE HERE
  int courses = 0, totalCreditHours = 0;
  double totalGpa = 0;
  cin >> courses;
  for (int index = 1; index <= courses; index++) {
    int creditHours = 0;
    char grade = 0;
    cin >> creditHours >> grade;
    totalGpa += creditHours * letterToPoints(grade);
    totalCreditHours += creditHours;
  }
  cout << "Final GPA: " << fixed << setprecision(2) << (totalGpa / totalCreditHours); 
  return 0;
}