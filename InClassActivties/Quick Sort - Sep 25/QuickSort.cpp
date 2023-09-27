#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

void swap(int &value1, int &value2) {
  int temp = value1;
  value1 = value2;
  value2 = temp;
}

int partition(int *values, int n) {
  //take first item as pivot
  int pivot = values[0];
  int low = 1;
  int high = n - 1;

  //partition
  while (low <= high) {
    if (values[low] < pivot) {
      low++;
    } else if (pivot < values[high]) {
      high--;
    } else {
      swap(values[low++], values[high--]);
    }
  }

  //swap pivot with the last item of smaler potion
  swap(values[0], values[low - 1]);

  return low - 1;
}

void quickSort(int *values, int n) {
  // Write your code here
  if (n <= 1) {
    return;
  }

  int pivotIndex = partition(values, n);
  quickSort(values, pivotIndex); // sort 0 to pivot index - 1
  quickSort(&values[pivotIndex + 1], n - pivotIndex - 1); // sort pivot index + 1 to n
}

int main() {
    string input;
    int item=0, numItems=0;
    int *numbers;

    //get a line of input & count # of ints
    getline(cin, input);
    istringstream istr(input);
    while (istr >> item)
        numItems++;

    //allocate memory and read the data again into the array
    numbers = new int [numItems];
    istr = istringstream(input);
    for(int i=0; i<numItems; i++)
        istr >> numbers[i];

    quickSort(numbers, numItems);
    
    for(int i=0; i<numItems; i++)
        cout << numbers[i] << " ";
}

