//FREEZE CODE BEGIN
#include "TestAttempt.h"

using namespace std;

int main()
{
    int numQuestions;
    string correct;
    cout << "Enter # of questions in the test: ";
    cin >> numQuestions;
    cout << "Enter the question #s you got right: ";
    cin >> correct;
    TestAttempt attempt1(numQuestions, correct);

    cout << "Enter the question #s your friend got right: ";
    cin >> correct;
    TestAttempt attempt2(numQuestions, correct);
    cout << endl;
    //now, you can work with both objects!
    cout << "A+B: " << attempt1 + attempt2 << endl;
    cout << "A^B: " << (attempt1 ^ attempt2) << endl;
    cout << "A%B: " << attempt1 % attempt2 << endl;
    cout << "A-B: " << attempt1 - attempt2 << endl;
    cout << "B-A: " << attempt2 - attempt1 << endl;
}
//FREEZE CODE END