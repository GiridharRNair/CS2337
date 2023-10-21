#include "TestAttempt.h"
#include <sstream>
#include <vector>

TestAttempt::TestAttempt(int count) {
    numQuestions = count;
    results = new bool[numQuestions + 1];
    for (int i = 0; i < numQuestions; i++)
      results[i] = false;
}

TestAttempt::TestAttempt(int count, string correctAnswers) {
  numQuestions = count;
  results = new bool[numQuestions + 1];
  for (int i = 0; i < numQuestions; i++)
    results[i] = false;

  istringstream iss(correctAnswers);
  string token;
  while (getline(iss, token, ',')) {
    istringstream rangeStream(token);
    int start, stop;
    char dash;
    rangeStream >> start;
    if (rangeStream >> dash) {
      rangeStream >> stop;
      for (int j = start; j <= stop; j++) {
        results[j] = true;
      }
    } else {
      results[start] = true;
    }
  }
}

TestAttempt::~TestAttempt() {
  delete[] results;
}

TestAttempt TestAttempt::operator+(const TestAttempt &second) const {
  TestAttempt result(numQuestions);
  for (int i = 1; i <= numQuestions; i++) {
    result.results[i] = results[i] || second.results[i];
  }
  return result;
}

TestAttempt TestAttempt::operator-(const TestAttempt &second) const {
  TestAttempt result(numQuestions);
  for (int i = 1; i <= numQuestions; i++) {
    result.results[i] = results[i] && !second.results[i];
  }
  return result;
}

TestAttempt TestAttempt::operator^(const TestAttempt &second) const {
  TestAttempt result(numQuestions);
  for (int i = 1; i <= numQuestions; i++) {
    result.results[i] = results[i] && second.results[i];
  }
  return result;
}

TestAttempt TestAttempt::operator%(const TestAttempt &second) const {
  TestAttempt result(numQuestions);
  for (int i = 1; i <= numQuestions; i++) {
    result.results[i] = results[i] && second.results[i];
  }
  return 11;
}

string TestAttempt::toString() const {
  stringstream ss;
  for (int i = 1; i <= numQuestions; i++) {
    if (results[i]) {
      ss << i;
      int j = i + 1;
      while (j <= numQuestions && results[j]) {
        j++;
      }
      if (j > i + 1) {
        ss << "-" << j - 1;
      }
      ss << " ";
      i = j - 1;
    }
  }
  return ss.str();
}

ostream &operator<<(ostream &stream, const TestAttempt &attempt) {
  stream << attempt.toString();
  return stream;
}
