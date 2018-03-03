#include<stdio.h>
#include<stdlib.h>
#include"InsertionSort.h"
#include"tiempo.h"
#include"imprimeTiempos.h"
int main(int argc,char **argv){
	int i;
	int n=atoi(argv[1]);
	int *a;
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	a=calloc(n,sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",a+i);
	}
	uswtime(&utime0, &stime0, &wtime0);
	insertion(a,n);
	uswtime(&utime1, &stime1, &wtime1);
	imprimeTiempos(n,utime0, stime0, wtime0,utime1, stime1, wtime1);
	free(a);
}
