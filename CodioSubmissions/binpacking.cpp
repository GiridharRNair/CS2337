#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//let us assume we won't go over 100 numbers
const int MAXITEMS = 100;
int items[MAXITEMS], binAssignments[MAXITEMS];
int numItems=0; //stores actual # of items
const int BINCAPACITY = 100;

int bins[MAXITEMS];
void validate() {
  int maxBinIndex = 0;
  for (int i = 0; i < numItems; i++) {
    if (items[i] > BINCAPACITY) {
      cout << "Input item " << items[i] << " out of range";
      return;
    }
    if (binAssignments[i] >= numItems) {
      cout << "Bin " << binAssignments[i] << " out of range";
      return;
    }
    bins[binAssignments[i]] += items[i];
    if (binAssignments[i] > maxBinIndex) {
      maxBinIndex = binAssignments[i];
    }
  }
  for (int i = 0; i <= maxBinIndex; i++) {
    if (bins[i] > BINCAPACITY) {
      cout << "Bin " << i << " total goes above " << BINCAPACITY;
      return;
    }
    if (bins[i] == 0) {
      cout << "Bin " << i << " not used";
      return;
    }
  }
  cout << "Valid";
}

int main() {
   string line;
   int numAssignments = 0;

   //get all the items first.
   getline(cin, line);  //get one line of input
   istringstream istr(line);  //convert it to inputstringstream
   //extract the numbers from the stream into the array
   while (istr >> items[numItems]) 
      numItems++;

    //get bin assignments now.
   getline(cin, line);
   istringstream istr2(line);
   while (istr2 >> binAssignments[numAssignments])
      numAssignments++;

    if (numItems != numAssignments) {
        cout << "# of items and # of bin assignments mismatch.";
        exit(1);
    }
    validate();
}
