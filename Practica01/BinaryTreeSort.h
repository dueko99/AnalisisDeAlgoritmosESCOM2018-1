/*
Implementación Práctica 01: Pruebas a posteriori (Algoritmos de Ordenamiento)
Por: Equipo Arbol
Versión: 1.0

Descripción: Programa que ordenará por medio de un Árbol Binario de Búsqueda (ABB)
	
Observaciones: 
*/


//LIBRERÍAS
#include "AuxBinaryTreeFunctions.h"



//DEFINICIÓN DE FUNCIONES

/*
Descripción: Función encargada de ordenar los números por medio de un ABB
Recibe: int * Data (arreglo de números a ordenar), int size (cantidad de números)
Devuelve: 
Observaciones: 
*/
void BinaryTreeSort(int * Data, int size){
	arbol_bin BinaryTree;
	Initialize(&BinaryTree);
	int i;
	for (i = 0; i < size; ++i)
	{
		Insert(&BinaryTree,Data[i]);
	}
	InorderTraversal(&BinaryTree, Data, size);
	Destroy(&BinaryTree);
	return;
}
