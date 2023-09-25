#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//let us assume we won't go over 100 numbers
const int MAXITEMS = 100;
int items[MAXITEMS], bins[MAXITEMS];
int numItems=0; //stores actual # of items

//return # of bins used
int binPacking() {
// WRITE YOUR CODE HERE
  int binCount = 0;
  for (int i = 0; i < numItems; i++) {
    if ((items[i] + bins[binCount]) <= MAXITEMS) {
      bins[binCount] += items[i];
    } else {
      bins[++binCount] = items[i];
    }
  }
  return binCount + 1;
}

int main() {
   string line;

   //get all the items first.
   getline(cin, line);  //get one line of input
   istringstream istr(line);  //convert it to inputstringstream
   //extract the numbers from the stream into the array
   while (istr >> items[numItems]) //ERROR checking here too?
      numItems++;

   //Algorithm's output
   int numBins = binPacking();
   cout << "# of bins: " << numBins << endl;
   for(int i=0; i<numBins; i++)
      cout << bins[i] << " ";
}
