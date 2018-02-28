#include "math.h"
void ShellSort(int *A, int n){
  int k =trunc(n/2);
  while (k>=1){
    int b=1;
    while (b!=0) {
      b=0;
      for (int i = k; i <= n-1; i++) {
        if (A[i-k]>A[i]) {
          int temp=A[i];
          A[i]=A[i-k];
          A[i-k]=temp;
          b=b+1;
        }
      }
    }
    k=trunc(k/2);
  }
}
