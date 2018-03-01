#include "AuxBinaryTreeFunctions.h"

void BinaryTreeSort(li * Data, li size){
	arbol_bin BinaryTree;
	Initialize(&BinaryTree);
	li i;
	for (i = 0; i < size; ++i)
	{
		Insert(&BinaryTree,Data[i]);
	}
	InorderTraversal(&BinaryTree, Data, size);
	Destroy(&BinaryTree);
	return;
}
