//FREEZE CODE BEGIN
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//Input: T,T,T,T,F,F,T,T,F,T,F
//Output: 1-4 7-8 10

int main()
{
    string line;
    getline(cin, line);
    istringstream istr(line);
    char responses[1000], temp;
    int numQuestions=0;

    while (istr >> responses[numQuestions+1])
    {
        numQuestions++;
        istr >> temp;
    }

    int start=0, stop=0;
    for(int i=1; i<=numQuestions; i++)
        if (responses[i] == 'T')
        {
            stop = i;
            if (!start)
                start = i;
        }
        else if (start > 0)
        {
            if (stop > start)
                cout << start << "-" << stop;
            else
                cout << start;
            cout << " ";
            start = stop = 0;
        }

    if (start > 0) {
        if (stop > start)
            cout << start << "-" << stop;
        else
            cout << start;
    }
}
//FREEZE CODE END