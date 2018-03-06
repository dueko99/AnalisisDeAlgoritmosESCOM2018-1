/*
Implementación Práctica 01: Pruebas a posteriori (Algoritmos de Ordenamiento)
Por: 
Versión: 1.0

Descripción: Programa que ordenará por medio del algoritmo de Shell
  
Observaciones: 
*/

//LIBRERÍAS
#include "math.h"



//DEFINICIÓN DE FUNCIONES

/*
Descripción: Función encargada de ordenar los números por medio del algoritmo de Shell
Recibe: int * Data (arreglo de números a ordenar), int size (cantidad de números)
Devuelve: 
Observaciones: 
*/
void ShellSort(int *Data, int size){
  int k =trunc(size/2);
  while (k>=1){
    int b=1;
    while (b!=0) {
      b=0;
      for (int i = k; i <= size-1; i++) {
        if (Data[i-k]>Data[i]) {
          int temp=Data[i];
          Data[i]=Data[i-k];
          Data[i-k]=temp;
          b=b+1;
        }
      }
    }
    k=trunc(k/2);
  }
}
