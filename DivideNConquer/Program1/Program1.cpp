#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
int main(int argc, char const *argv[]) {
  long long N,CurrentMax, MaxSoFar;;
  std::vector<long long> A;

  std::cin >> N;

  for (int i = 0; i < N; i++){
    std::cin >> CurrentMax;
    A.push_back(CurrentMax);
  }

  CurrentMax=0;
  MaxSoFar=INT_MIN;
  for (int j = 0; j < A.size(); j++) {
    CurrentMax= CurrentMax+A[j];

    if (MaxSoFar<CurrentMax) {
      MaxSoFar=CurrentMax;
    }

    if (CurrentMax<0) {
      CurrentMax=0;
    }
  }
  std::cout << MaxSoFar << '\n';
}
