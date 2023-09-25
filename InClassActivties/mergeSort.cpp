#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

void merge(int *items, int n) {
    int *temp = new int [n];

    // Teachers implementation.
    copy(items, items + n, temp);
    int half = n / 2;
    int *firstp = temp;
    int *halfp = temp + half;
    int *secondp = halfp;
    int *endp = temp + n;

    int *savep = items;

    while (firstp < halfp && secondp < endp) {
      if (*firstp < *secondp) {
        *savep++ = *firstp++;
      } else {
        *savep++ = *secondp++;
      }
    }

    while (firstp < halfp) {
      *savep++ = *firstp++;
    }

    while (secondp < endp) {
      *savep++ = *secondp++;
    }

    // My implementation.
    /*
    int half = n / 2;
    int i = 0;
    int j = half;
    int k = 0;

    while (i < half && j < n) {
      if (items[i] <= items[j]) {
        temp[k] = items[i];
        i++;
      } else {
        temp[k] = items[j];
        j++;
      }
      k++;
    }

    while(i < half) {
      temp[k] = items[i];
      k++;
      i++;
    }

    while(j < n) {
      temp[k] = items[j];
      k++;
      j++;
    }

    for (int i = 0; i < n; i++) {
      items[i] = temp[i];
    }
    */

    delete[] temp;

// WRITE YOUR CODE HERE
}

void mergeSort(int *values, int n) {
    if (n <= 1)
        return;

    //sort the first half, then sort second half, then merge both.
    int half = n/2;
    mergeSort(values, half);
    mergeSort(values + half, n - half);

    merge(values, n);
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

    mergeSort(numbers, numItems);
    
    for(int i=0; i<numItems; i++)
        cout << numbers[i] << " ";
}

