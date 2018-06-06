#include <iostream>
int main(int argc, char const *argv[]) {
  long long C1,C2,X,Y,V;
  std::cin >> C1 >> C2 >> X >> Y;
  if (C1+C2<X) {
    V=C1+C2;
  }else if (C1+C2<Y){
    V=X+1;
    do {
      if (V%Y!=0&&C2!=0){
        C2--;
      }
      V++;
    } while(!(C1==0&&C2==0));
    V--;
  }else{
    V=Y+1;
    do {
      if (V%X!=0&&C1!=0) {
        C1--;
      }else if (V%Y!=0&&C2!=0){
        C2--;
      }
      V++;
    } while(!(C1==0&&C2==0));
    V--;
  }
  std::cout << V << '\n';
  return 0;
}
