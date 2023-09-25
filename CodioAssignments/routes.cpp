#include <iostream>
#include <string>

using namespace std;

int main() {
// WRITE YOUR CODE HERE
  int totalRoutes = 0, bestRoute = 1;
  double money = 0, bestTimeValue = 1000000000000000000;
  cin >> totalRoutes;
  cin >> money;
  for (int index = 1; index <= totalRoutes; index++) {
    int travelTime = 0;
    double toll = 0;
    cin >> travelTime;
    cin >> toll;
    double effectiveTime = travelTime + (toll / money);
    double timeValue = effectiveTime * money;
    if (timeValue < bestTimeValue) {
      bestTimeValue = timeValue;
      bestRoute = index;
    }
  }
  cout << "Best route is #" << bestRoute;
  return 0;
}
