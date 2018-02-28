
void SelectionSort(int *A, int n){
  for (int k = 0; k < n-1; k++) {
    int p=k;
    for (int i=k+1; i < n; i++) {
      if (A[i]<A[p]) {
        p=i;
      }
    }
    int aux=A[p];
    A[p]=A[k];
    A[k]=aux;
  }
}
