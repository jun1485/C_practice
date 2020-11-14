# include <stdio.h>
# include <stdlib.h>

struct node {
	int data;
	struct node* lchild;
	struct node* rchild;
};

struct node* make_tree_by_code();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
struct node* copy(struct node*);
struct node* swap(struct node*);
int equal(struct node*, struct node*);

void main() {

	struct node* A, * B, * C;

	A = make_tree_by_code();
	printf("Inorder_methode print >> "); inorder(A); printf("\n");
	printf("Preorder_methode print >> "); preorder(A); printf("\n");
	printf("Postorder_methode print >> "); postorder(A); printf("\n");
	B = copy(A);
	C = swap(A);
}

struct node* make_tree_by_code() {

	int n = 0;
	int data;
	struct node* make_tree;
	node ptr;
	make_tree = (struct node*)malloc(sizeof(struct node));
	make_tree->rchild = make_tree->lchild = NULL;

	printf("insert data >> ");
	scanf_s("%d", &data);

	int randData = rand() % 2;

	make_tree->data = data;
	if (data) {
		make_tree->lchild = make_tree_by_code();
		make_tree->rchild = make_tree_by_code();

		return make_tree;
	}
	return NULL;

	if (make_tree->rchild == NULL && make_tree->lchild == NULL) {
		return NULL;
	}
}

void inorder(struct node* tree) {

	if (tree) {
		inorder(tree->lchild);
		printf("%d -> ", tree->data);
		inorder(tree->rchild);
	}
}

void preorder(struct node* tree) {

	if (tree) {
		printf("%d -> ", tree->data);
		preorder(tree->lchild);
		preorder(tree->rchild);
	}
}
void postorder(struct node* tree) {
	if (tree) {
		postorder(tree->lchild);
		postorder(tree->rchild);
		printf("%d -> ", tree->data);
	}

}
