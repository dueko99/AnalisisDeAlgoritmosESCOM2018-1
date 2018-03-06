/*
Implementación Práctica 01: Pruebas a posteriori (Algoritmos de Ordenamiento)
Por: 
Versión: 1.0

Descripción: Funciones Auxiliares del Algoritmo de Ordenamiento por medio de un 
	Árbol Binario de Búsqueda (ABB)
	
Observaciones: 
*/


//LIBRERÍAS
#include "stdlib.h"

//DEFINICIONES DE ESTRUCTURAS
typedef struct node
{
	struct node *left, *right;
	int number;
}node;

//DEFINICIONES DE SINÓNIMOS
typedef node* position;
typedef position arbol_bin;



//DEFINICIÓN DE FUNCIONES

/*
Descripción: Función encargada de inicializar la estructura del ABB
Recibe: arbol_bin *BinaryTree (apuntador al ABB declarado por el usuario)
Devuelve: 
Observaciones: 
*/
void Initialize(arbol_bin *BinaryTree){
	*BinaryTree = NULL;
	return;
}

/*
Descripción: Función encargada de insertar un nuevo elemento en el ABB
Recibe: arbol_bin * BinaryTree (apuntador al ABB utilizado por el usuario), 
	int newNumber (nuevo elemento que se va a incluir en el ABB)
Devuelve: 
Observaciones: 
*/
void Insert(arbol_bin * BinaryTree, int newNumber){
	arbol_bin * aux = BinaryTree; 											
	while(*aux != NULL){												
		if (newNumber > ((*aux)->number))
		{
			aux = &((*aux)->right);
		}
		else{
			aux = &((*aux)->left);
		}
	}
	*aux = (node *)malloc(sizeof(node));
	(*aux)->number = newNumber;
	(*aux)->left = NULL;
	(*aux)->right = NULL;
	return;
}

/*
Descripción: Función encargada de hacer el recorrido inorden por el ABB
Recibe: arbol_bin *BinaryTree (apuntador al ABB utilizado por el usuario),
	int* Data (arreglo que contiene los números), int size (cantidad de números)
Devuelve: 
Observaciones: 
*/
void InorderTraversal(arbol_bin *BinaryTree, int* Data, int size){

	position auxPos = *BinaryTree;

	node ** Stack = (node**)malloc(size*sizeof(arbol_bin));

	int stackTop = -1, i = 0;

	do{
		while(auxPos != NULL){
			Stack[++stackTop] = auxPos;
			auxPos = auxPos->left;
		}

		if(stackTop >= 0){
			auxPos = Stack[stackTop--];
			Data[i++] = auxPos->number;
			auxPos = auxPos->right;
		}
	}while(auxPos != NULL || stackTop >= 0);

	free(Stack);

	return;
}

/*
Descripción: Función encargada de liberar el espacio ocupado por el ABB
Recibe: arbol_bin *BinaryTree (apuntador al ABB utilizado por el usuario)
Devuelve: 
Observaciones: 
*/
void Destroy(arbol_bin *BinaryTree){
	if(*BinaryTree == NULL)
		return;
	else
	{
		if((*BinaryTree)->left != NULL)
			Destroy(&((*BinaryTree)->left));
		if((*BinaryTree)->right != NULL)
			Destroy(&((*BinaryTree)->right));
		free(*BinaryTree);
		return;
	}
}
