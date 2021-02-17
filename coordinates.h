#ifndef COORDINATES_H
#define COORDINATES_H

#include <string>
#include <vector>

// any type def goes here 
typedef std::pair<double, double> Coordinate;

// vector definition 
typedef std::vector<Coordinate> CoordVec; 
// could also use typedef std::vector<std::pair<double,double>> coordVec; but is much longer 

// declaration of functions go here 
double Haversine(Coordinate a, Coordinate b);

Coordinate SortByDistanceTo(CoordVec v1); 


#endif
