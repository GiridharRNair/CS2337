#include <iostream>
using namespace std;

void radixPrint(int n, int radix) {
    if (n < radix) {
        cout << n;
    } else {
        radixPrint(n / radix, radix);
        cout << n % radix;
    }
}

int main() {
    for (int i = 0; i <= 100; i++) {
        cout << i << " ";
        for (int j = 2; j <= 10; j++) {
            cout << " ";
            radixPrint(i, j);
        }
        cout << endl;
    }
    return 0;
}
