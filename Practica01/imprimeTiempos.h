#include "stdio.h"
void imprimeTiempos(int n,double utime0,double stime0,double wtime0,double utime1,double stime1,double wtime1){
	printf("%15d",n);
	printf("%25.10f",  wtime1 - wtime0);
	printf("%25.10f",  utime1 - utime0);
	printf("%25.10f",  stime1 - stime0);
	printf("%25.10f\n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
}
