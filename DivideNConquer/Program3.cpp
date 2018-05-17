#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <math.h>

bool sortFunction(std::pair<float, float> a, std::pair<float, float> b){
  return (a.first < b.first);
}

float DistanceOf2Points(std::pair<float, float> a, std::pair<float, float> b){
  return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}

float MinBrute(std::vector<std::pair<float,float>> v, int left, int right){
  float min=40000;
  for (int i = left; i < right ; i++) {
    for (int j = 0; j < i ; j++) {
      if (min>DistanceOf2Points(v[i],v[j])) {
        min=DistanceOf2Points(v[i],v[j]);
      }
    }
  }
  return min;
}

// A recursive function to find the smallest distance. The array P contains
// all points sorted according to x coordinate
float closestDYV(std::vector<std::pair<float,float>> v, int left, int right)
{
    // If there are 2 or 3 points, then use brute force
    if (right-left <= 3){
      return MinBrute(v, left,right);
    }
    // Find the middle point
    int mid = (right-left)/2;
    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    float closestLeft = closestDYV (v, left,mid);
    float closestRight = closestDYV(v, mid+1,right);

    // Find the smaller of two distances
    float d = std::min(closestLeft,closestRight);

    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    return min(d, stripClosest(strip, j, d) );
}


int main(int argc, char const *argv[]) {
  unsigned int n;
  float a,b;
  std::vector<std::pair<float,float>> v;

  std::cin >> n;
  for (size_t i = 0; i < n; i++) {
    std::cin >> a >> b;
    v.push_back(std::make_pair(a,b));
  }
  std::sort(v.begin(),v.end(),sortFunction);
  /*for (size_t i = 0; i < v.size(); i++) {
    std::cout << v[i].first<<v[i].second << '\n';
  }*/


  std::cout << closest << '\n';
  return 0;
}
