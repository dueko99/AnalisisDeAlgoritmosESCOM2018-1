#include "stdio.h"
void SimpleBubbleSort(int *A,int n){
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-1-i; j++) {
      if(A[j]>A[j+1]){
        int temp=A[j+1];
        A[j+1]=A[j];
        A[j]=temp;
      }
    }
  }
}

void OptimizedBubbleSort(int *A, int n){
  int changes=1;
  int i=0;
  while((i<n-1)&&(changes!=0)) {
    changes=0;
    for (int j = 0; j < n-1-i; j++) {
      if(A[j]>A[j+1]){
        changes=1;
        int temp=A[j+1];
        A[j+1]=A[j];
        A[j]=temp;
      }
    }
    i++;
  }
}
