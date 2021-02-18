#include <iostream> 
#include <cstdlib>
#include <iomanip>
#include "coordinates.h"
#include <vector> 

using namespace std;

int main() {
    // loop that reads comma-delimited lines from standard input one line at a time and constructs a vector of coordinates 
string coords;
CoordVec x; 
Coordinate userInput;
// Using unix pipe to get coords for input  
while (getline(cin, coords)){
        // get whole line
        int commaLocation = coords.find(",");
        string lat = coords.substr(0, commaLocation -1); 
        string longitude = coords.substr(commaLocation + 1, -1);
        // push variable into a vector 
        userInput.first = atof(lat.c_str());
        userInput.second = atof(longitude.c_str()); 
            x.push_back(userInput); 
        
}

// Sort vector of coordinates using SortByDistanceTo function
Coordinate minCoord = SortByDistanceTo(x);
// Print out the coordinate that is closest to the SOU Computer Science building setprecision to 6).
cout << "The the coordinate pair closest to the SOU Computer Science Building is: " << fixed << setprecision(6) << minCoord.first << ", " << fixed << setprecision(6) << minCoord.second << endl;
return 0; 
}
