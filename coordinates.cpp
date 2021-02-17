#include "coordinates.h"
#include <cmath> 

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


