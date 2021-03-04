#include "coordinates.h"
#include <cmath> 
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <utility> 

using namespace std;

// earth radius 
double rad = 6371.0; 

// convert decimal degrees to rads
double degreeToRad(double deg) {
  return (deg * M_PI / 180);
}

// convert rads to decimal degrees
double radToDegree(double rad) {
  return (rad * 180 / M_PI); }

double Haversine(Coordinate a, Coordinate b) {
        double lat1r, lon1r, lat2r, lon2r, latFinal, lonFinal;
        lat1r = degreeToRad(a.first);
        lon1r = degreeToRad(a.second);
        lat2r = degreeToRad(b.first);
        lon2r = degreeToRad(b.second);
        // find the distance between lat and long 
        latFinal = sin((lat2r - lat1r)/2);
        lonFinal = sin((lon2r - lon1r)/2);
        double distance = 2.0 * rad * asin(sqrt(latFinal * latFinal + cos(lat1r) * cos(lat2r) * lonFinal * lonFinal));
        // to mi 
        distance = distance / 1.609344;

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
            double idistance = Haversine(csBuilding, v1[i]);
            double jdistance = Haversine(csBuilding, v1[j]); 
        if (jdistance < idistance) {
            swap(v1[i], v1[j]);
        }
    }
    }
    
    // return coord 
    Coordinate coordMin = v1[0]; // vector of coords at index 0 
    return coordMin; 

}