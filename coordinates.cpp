#include "coordinates.h"
#include <cmath> 
#include <iostream>
#include <vector> 
#include <utility> 

using namespace std;

double Haversine(Coordinate a, Coordinate b) 
    {   double rad = 6371; 
        // find the distance between lat and long 
        double latDistance = (b.first - a.first) * M_PI / 180.0; 
        double longDistance = (b.second - a.second) * M_PI / 180.0;

        // convert the distance to radians 
        b.first = (b.first) * M_PI / 180.0; 
        a.first = (a.first) * M_PI / 180.0; 

        // find distance 
        double powFormula; 
        powFormula = pow(sin(latDistance / 2), 2) + pow(sin(longDistance /2), 2) * cos(b.first) * cos(a.first);
        double c = 2 * asin(sqrt(powFormula));
        double distance = rad * c; 
        return distance; 
    }

Coordinate SortByDistanceTo(CoordVec v1) { 
    Coordinate csBuilding; 
    csBuilding.first = 42.1858587;
    csBuilding.second = -122.6970897; 
    // sort through vector to return smallest coord 
    for (unsigned int i = 0; i < v1.size(); ++i) { 
        for (unsigned int j = i + 1; j < v1.size(); ++j) { 
            // for number in position i of vector get haversine dist 
            double idistance = Haversine(v1[i], csBuilding);
            double jdistance = Haversine(v1[j], csBuilding); 
        if (jdistance < idistance) {
            swap(v1[i], v1[j]);
        }
    }
    }
    
    // return coord 
    Coordinate coordMin = v1[0]; // vector of coords at index 0 
    return coordMin; 

}