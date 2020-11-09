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

struct node* make_tree_by_code() {

	int n = 0;
	int data;
	struct node* make_tree;
	node ptr;
