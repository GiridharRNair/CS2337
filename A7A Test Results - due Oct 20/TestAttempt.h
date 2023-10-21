//FREEZE CODE BEGIN

#ifndef TESTATTEMPT_H
#define TESTATTEMPT_H
#include <iostream>
#include <string>

using namespace std;

class TestAttempt
{
    public:
        TestAttempt(int numQuestions);
        TestAttempt(int numQuestions, string correctAnswers);
        virtual ~TestAttempt();

        TestAttempt operator+(const TestAttempt &second) const;
        TestAttempt operator-(const TestAttempt &second) const;
        TestAttempt operator^(const TestAttempt &second) const;
        TestAttempt operator%(const TestAttempt &second) const;

        string toString() const;
        friend ostream& operator<< (ostream& stream, const TestAttempt& attempt);
        

    private:
        int numQuestions;
        bool *results;
};

#endif // TESTATTEMPT_H

//FREEZE CODE END