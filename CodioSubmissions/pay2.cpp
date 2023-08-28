#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    //pay_rate, weekly_pay is old C style naming convention
    double payRate=0, hours=0, weeklyPay=0; //camel casing

    cout << "Input hourly pay rate: ";
    cin >> payRate;
    cout << "Input # of hours: ";
    cin >> hours;

    if (hours <= 40) {
      weeklyPay = hours * payRate;
    } else if (hours <= 50) {
      weeklyPay = payRate * 40 + payRate * 1.5 * (hours-40);
    } else {
      weeklyPay = payRate * 40 + payRate * 1.5 * 10;
    }
    cout << "Your Weekly Pay: " << weeklyPay;

    cout << "Your weekly pay: " << weeklyPay;
    return 0;
}
