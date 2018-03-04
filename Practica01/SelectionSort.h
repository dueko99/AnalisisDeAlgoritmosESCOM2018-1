/*
Implementación Práctica 01: Pruebas a posteriori (Algoritmos de Ordenamiento)
Por: 
Versión: 1.0

Descripción: Programa que ordenará por medio del algoritmo de Selección
  
Observaciones: 
*/



//DEFINICIÓN DE FUNCIONES

/*
Descripción: Función encargada de ordenar los números por medio del algoritmo de Selección
Recibe: int * Data (arreglo de números a ordenar), int size (cantidad de números)
Devuelve: 
Observaciones: 
*/
void SelectionSort(int *Data, int size){
  for (int k = 0; k < size-1; k++) {
    int p=k;
    for (int i=k+1; i < size; i++) {
      if (Data[i]<Data[p]) {
        p=i;
      }
    }
    int aux=Data[p];
    Data[p]=Data[k];
    Data[k]=aux;
  }
}
