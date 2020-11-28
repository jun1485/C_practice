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
	node* newNode = (node*)malloc(sizeof(node));
	newNode->lchild = NULL;
	newNode->rchild = NULL;
	newNode->data = n;
	return newNode;
}

void insertNode(node* tree, node* newNode)
{
	if (newNode->data > tree->data)
	{
		if (tree->rchild != NULL)
			insertNode(tree->rchild, newNode);
		else tree->rchild = newNode;
	}
	else if (newNode->data < tree->data)
	{
		if (tree->lchild != NULL)
			insertNode(tree->lchild, newNode);
		else tree->lchild = newNode;
	}
}

treePointer searchNode(treePointer tree, int key)
{
	if (tree == NULL) return NULL;
	if (tree->data == key) return tree;
	else if (tree->data > key)
		searchNode(tree->lchild, key);
	else searchNode(tree->rchild, key);

}

treePointer modified_search(treePointer tree, int key)
{
	treePointer ptr = NULL;
	while (tree)
	{
		ptr = tree;
		if (key == tree->key) return NULL;
		if (key < tree->key) tree = tree->lchild;
		else tree = tree->rchild;
	}
	return ptr;
}
