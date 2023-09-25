#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

long long factFactorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factFactorial(n - 1);
    }
}

long long factNonRecursive(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long fib (int n) {
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

long long fibNonRec (int n) {
    if ( n < 2) {
        return n;
    }
    int prev = 1, prev1 = 0;
    for (int i = 2; i <= n; i++) {
        int temp = prev;
        prev = prev + prev1;
        prev1 = temp;
    }
    return prev;
}

int main() {
    for (int i = 0; i <= 50; i++) {
        auto start = high_resolution_clock::now();
        cout << i << " " << factFactorial(i) << " " << factNonRecursive(i) << " " << fib(i) << " " << fibNonRec(i) << endl;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time: " << duration.count() << " ms" << endl;
    }
    return 0;
}
