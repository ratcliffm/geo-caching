#include <iostream> 
#include <cstdlib>
#include <iomanip>
#include "coordinates.h"
#include <vector> 

using namespace std;

void main() {
    // loop that reads comma-delimited lines from standard input one line at a time and constructs a vector of coordinates 
string coords;
CoordVec x; 
// Using unix pipe to get coords for input 
while (getline(cin, coords)){
        Coordinate userInput;
        userInput.first = coords.at(0); 
        userInput.second = coords.at(1); 
            x.push_back(userInput); 
        
}

// Sort vector of coordinates using SortByDistanceTo function
Coordinate minCoord = SortByDistanceTo(x);
// Print out the coordinate that is closest to the SOU Computer Science building setprecision to 6).

cout << "The the coordinate pair closest to the SOU Computer Science Building is: " << fixed << setprecision(6) << minCoord.first << fixed << setprecision(6) << minCoord.second << endl; 
}
