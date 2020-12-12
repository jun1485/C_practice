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

void printTree(node* tree)
{
	if (tree == NULL) return;
	printTree(tree->lchild);
	printf("%d ", tree->data);
	printTree(tree->rchild);
}

int get_height(node* root) { // 트리의 높이를 구한다.
	if (!root)
		return 0;
	else {
		int left_h = get_height(root->lchild); // 왼쪽 서브트리의 높이를 순환호출을 통해 얻는다.
		int right_h = get_height(root->rchild); // 같은 방법으로 오른쪽 서브트리의 높이를 얻는다.
		printf("%d", 1 + (left_h > right_h ? left_h : right_h)); // 둘 중 큰 값에 1을 더해 반환한다.
	}
}

int main()
{
	node* tree = make_bst(10);
	node* findNode;
	int input;

	insertNode(tree, make_bst(1));
	insertNode(tree, make_bst(3));
	insertNode(tree, make_bst(5));
	insertNode(tree, make_bst(7));
	insertNode(tree, make_bst(9));
	insertNode(tree, make_bst(11));
	insertNode(tree, make_bst(13));
	insertNode(tree, make_bst(15));
	insertNode(tree, make_bst(17));

	while (1)
	{
		scanf("%d", &input);
		findNode = searchNode(tree, input);
		if (findNode != NULL)
		{
			printf("해당 노드를 찾았습니다! 노드의 위치는 %#x 입니다.\n", findNode);
			printf("현재 트리 출력: ");
			printTree(tree);
			printf("\n");
			get_height(tree);
		}
		else printf("노드를 찾을 수 없었습니다.\n");
	}
}
