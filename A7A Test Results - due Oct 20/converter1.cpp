//FREEZE CODE BEGIN
//Input: 2-3 5 7-9 11
//Output: F T T F T F T T T F T

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    istringstream istr(line);

    int questionNum = 1, start;
    while (istr >> start) {
       //output necessary # of "F"
        while (start > questionNum) {
            cout << "F ";
            questionNum++;
        }

        //"T" for start
        cout << "T ";
        questionNum++;

        if (istr.peek() == '-') { //is it a range?
            char temp;
            int stop; //end of the range
            istr >> temp >> stop;
            while (questionNum <= stop) {
                cout << "T ";
                questionNum++;
            }
        }
    }
}
//FREEZE CODE END

