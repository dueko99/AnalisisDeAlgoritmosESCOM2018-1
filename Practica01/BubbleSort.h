/*
Implementación Práctica 01: Pruebas a posteriori (Algoritmos de Ordenamiento)
Por: 
Versión: 1.0

Descripción: Programa que ordenará por medio del algoritmo de Burbuja, 
  tanto simple como optimizada
  
Observaciones: 
*/



//DEFINICIÓN DE FUNCIONES

/*
Descripción: Función encargada de ordenar los números por medio del algoritmo de Burbuja Simple
Recibe: int * Data (arreglo de números a ordenar), int size (cantidad de números)
Devuelve: 
Observaciones: 
*/
void SimpleBubbleSort(int * Data,int size){
  for (int i = 0; i < size-1; i++) {
    for (int j = 0; j < size-1-i; j++) {
      if(Data[j]>Data[j+1]){
        int temp=Data[j+1];
        Data[j+1]=Data[j];
        Data[j]=temp;
      }
    }
  }
}

/*
Descripción: Función encargada de ordenar los números por medio del algoritmo de Burbuja Optimizada
Recibe: int * Data (arreglo de números a ordenar), int size (cantidad de números)
Devuelve: 
Observaciones: 
*/
void OptimizedBubbleSort(int *Data, int size){
  int changes=1;
  int i=0;
  while((i<size-1)&&(changes!=0)) {
    changes=0;
    for (int j = 0; j < size-1-i; j++) {
      if(Data[j]>Data[j+1]){
        changes=1;
        int temp=Data[j+1];
        Data[j+1]=Data[j];
        Data[j]=temp;
      }
    }
    i++;
  }
}
