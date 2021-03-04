#include "gtest/gtest.h"
#include "coordinates.h"
#include <cmath>
#include <string>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
// tests go here 
TEST(Haversine, usingCSbuilding) { 
  Coordinate a;
  a.first = 1042.179122;
  a.second = -122.687187;
  Coordinate b;
  b.first = 42.1858587;
  b.second = -122.6970897; 
  double distance = Haversine(a, b);
  double expected = 8896.3558424107;
  double diff = fabs(distance - expected);
  EXPECT_LE(diff, 0.001);
}

TEST(Haversine, RandCoords) { 
  Coordinate a;
  a.first = -34.83333;
  a.second = -58.5166646;
  Coordinate b;
  b.first = 49.0083899664;
  b.second = 2.53844117956; 
  double distance = Haversine(a, b);
  double expected = 11099.5560355973;
  double diff = fabs(distance - expected);
  EXPECT_LE(diff, 0.001);
}