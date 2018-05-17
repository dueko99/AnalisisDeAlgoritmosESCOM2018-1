#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
int main(int argc, char const *argv[]) {
  long long C1,C2,X,Y,V;
  std::cin >> C1 >> C2 >> X >> Y;
  if (C1<C2) {
    std::swap(C1,C2);
    std::swap(X,Y);
  }
  V =1 ;

  do {
    if (V%X!=0&&C1!=0) {
      //std::cout << V << C1 << X << "\n\n";
      C1--;
      //std::cout << V << C1 << X << "\n\n";
    }else if (V%Y!=0&&C2!=0){
      //std::cout << V << C2 << Y << "\n\n";
      C2--;
      //std::cout << V << C2 << Y << "\n\n";
    }
    V++;
  } while(!(C1==0&&C2==0));
  std::cout << V-1 << '\n';
  return 0;
}
