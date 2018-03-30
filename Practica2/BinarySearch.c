/*
Implementación Práctica 02: Análisis temporal y notación de orden (Algoritmos de Busqueda)
Por:
Versión: 1.0
Descripción: Programa que buscara por medio del metodo Secuencial
Observaciones:
*/

/*
		gcc -pthread -o LinealSearch LinealSearch.c
		./LinealSearch n t k <10millones.txt >> Lineal.txt
		donde n es el tamaño de la busqueda
		t es el numero de threds
		k es el valor a busar
*/


//LIBRERÍAS
#include <stdlib.h>
#include <pthread.h>
#include "tiempo.h"
#include "imprimeTiempos.h"
#include "BinarySearch.h"


// FUNCIÓN PRINCIPAL

/*
Variables usadas en el programa:
	int size: variable que tomará el tamaño de la línea de comando
  int threads: varable que tomara el numero de threads
	pthread_t thread: arreglo para la identificacion de los threads
	int* Data: apuntador de entero que será inicializado como arreglo para los datos a ordenar
	double utime0: variable que medirá el tiempo de inicio de ejecución del usuario
	double stime0: variable que medirá el tiempo de inicio de ejecución del sistema
	double wtime0: variable que medirá el tiempo de inicio de ejecución real
	double utime1: variable que medirá el tiempo de finalización de ejecución del usuario
	double stime1: variable que medirá el tiempo de finalización de ejecución del sistema
	double wtime1: variable que medirá el tiempo de finalización de ejecución real
*/






int main(int argc,char **argv){
	size=atoi(argv[1]);
  threads=atoi(argv[2]);
	key=atoi(argv[3]);
	Data=(int*)calloc(size,sizeof(int));//Crea el arreglo de numeros
	for(int i=0;i<size;i++){
		scanf("%d",Data+i);
	}
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	uswtime(&utime0, &stime0, &wtime0);
	pthread_t *threadArr;//arreglo para la identificacion de los threads
	threadArr = (pthread_t*)malloc(threads*sizeof(pthread_t));//Crea el arreglo de threds
	for (int i = 0; i < threads; i++){
		pthread_create(&threadArr[i], NULL, BinarySearchDriver, (void*)NULL); // se asigna una rutina a cada hilo
	}
	for (int i = 0; i < threads; i++) {
    pthread_join(threadArr[i], NULL); // se comenza la rutina
	}
	uswtime(&utime1, &stime1, &wtime1);
	if (encontrado==1) {
		printf("Valor encontrado\n");
	} else {
		printf("Valor NO encontrado\n");
	}
	imprimeTiempos(size,utime0, stime0, wtime0,utime1, stime1, wtime1);
	free(Data);
}
