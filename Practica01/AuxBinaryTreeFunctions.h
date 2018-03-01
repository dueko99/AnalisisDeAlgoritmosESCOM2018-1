#include "stdlib.h"

typedef long int li;

typedef struct node
{
	struct node *left, *right;
	li number;
}node;

typedef node* position;
typedef position arbol_bin;

void Initialize(arbol_bin *BinaryTree){
	*BinaryTree = NULL;
	return;
}

void Insert(arbol_bin * BinaryTree, li newNumber){
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

void InorderTraversal(arbol_bin *BinaryTree, li* Data, li size){

	position auxPos = *BinaryTree;

	node ** Stack = (node**)malloc(size*sizeof(arbol_bin));

	li stackTop = -1, i = 0;

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
