#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string pattern = "";
    ifstream finput ("cowfind.in");
    finput >> pattern;
    finput.close();
    int numCows = 0, openCount = 0;
    int n = pattern.length();
    for (int i = 0; i < n - 1; i++) {
        if (pattern[i] == '(' && pattern[i + 1] == '(') {
            openCount++;
        }
        if (pattern[i] == ')' && pattern[i + 1] == ')') { 
            numCows += openCount;
        }
    }
    ofstream foutput ("cowfind.out");
    foutput << numCows;
    foutput.close();
    return 0;
}