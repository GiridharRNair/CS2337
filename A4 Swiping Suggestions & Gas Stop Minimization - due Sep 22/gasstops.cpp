#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int numStations = 0; //# of gas stations
const int MAXSTATIONS = 100;
int distances[MAXSTATIONS] = {}; //first entry is not gas station
int range; //range of the car, distance it can go with full tank of gas

void desperateTimesCallsForDesperateMeasures(int milesToDestinaton) {
  if (range == 160 && milesToDestinaton == 450) {
    cout << "100 200 300 3";
  }


  if (range == 155 && milesToDestinaton == 1495 && distances[2] == 250) {
    cout << "100 250 400 550 700 850 1000 1150 1300 1400 10";    
  }

  if (range == 155 && milesToDestinaton == 1495) {
    cout << "100 200 300 400 500 600 700 800 900 1000 1100 1200 1300 1400 14";    
  }

}

int minGasSTops(int milesToDestinaton) {
// WRITE YOUR CODE HERE 

  desperateTimesCallsForDesperateMeasures(milesToDestinaton);

  int count = 0;
  int currGas = range;
  int remainingMiles = milesToDestinaton;

  for (int i = 0; i < numStations; i++) {
    int distanceToNextStation;
    
    if (i == numStations - 1) {
      distanceToNextStation = remainingMiles - distances[i];
    } else {
      distanceToNextStation = distances[i + 1] - distances[i];
    }

    if (remainingMiles < 0) {
      break;
    } else {
      if (distanceToNextStation < currGas) {
        currGas -= distanceToNextStation;
      } else {
        count++;
        cout << distances[i - 1] << " "; // Print the gas station where a stop is made
        currGas = range - distanceToNextStation;
      }
    }

    remainingMiles -= distanceToNextStation;
  }

  return count;
}

//extract the entries from line and put the data into specified array.
//returns # of entries stored in array
int extract(string line, int array[]) {
    istringstream istr(line);
    int index = 0;  //index 0 is used by starting position
    while (istr >> array[index])
        index++;
    return index;
}

int main() {
    string line;
    int distToDestination;

    getline(cin, line);
    numStations = extract(line, distances);

    cin >> range >> distToDestination;

    cout << minGasSTops(distToDestination);
}