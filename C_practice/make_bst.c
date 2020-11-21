#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node* treePointer;

typedef struct node {
	int data;
	int key;
	treePointer lchild;
	treePointer rchild;
} node;

node* make_bst(int n)
{

}
