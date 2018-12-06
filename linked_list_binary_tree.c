#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct binary_tree {
	element data;
	struct binary_tree* llink;
	struct binary_tree* rlink;
}node;

node* make_node(element);
element get_data(node*);
node* get_left_node(node*);
node* get_right_node(node*);
void connect_left_node(node*, node*);
void connect_right_node(node*, node*);
void inorderTraverse(node*);
void preorderTraverse(node*); 
void postorderTraverse(node*);

void main() {
	node* no1 = make_node(1);
	node* no2 = make_node(2);
	node* no3 = make_node(3);
	node* no4 = make_node(4);
	node* no5 = make_node(5);
	node* no6 = make_node(6);
	node* no7 = make_node(7);
	node* no8 = make_node(8);
	node* no9 = make_node(9);
	node* no10 = make_node(10);
	node* no11 = make_node(11);

	connect_left_node(no6, no4);
	connect_left_node(no4, no2);
	connect_right_node(no4, no5);
	connect_left_node(no2, no1);
	connect_right_node(no2, no3);
	connect_right_node(no6, no9);
	connect_right_node(no9, no10);
	connect_left_node(no9, no7);
	connect_right_node(no10, no11);
	connect_left_node(no10, no8);

	inorderTraverse(no6);
	printf("\n");
	preorderTraverse(no6);
	printf("\n");
	postorderTraverse(no6);
}

node* make_node(element data) {
	node* new = (node*)malloc(sizeof(node));
	new->data = data;
	new->llink = NULL;
	new->rlink = NULL;
}

element get_data(node* nd) {
	return nd->data;
}

node* get_left_node(node* nd) {
	return nd->llink;
}

node* get_right_node(node* nd) {
	return nd->rlink;
}

void connect_left_node(node* par_nd, node*  chi_nd) {
	if (par_nd->llink != NULL) {
		free(par_nd->llink);
	}
	par_nd->llink = chi_nd;
}

void connect_right_node(node* par_nd, node*  chi_nd) {
	if (par_nd->rlink != NULL) {
		free(par_nd->rlink);
	}
	par_nd->rlink = chi_nd;
}

void inorderTraverse(node* top_nd) {
	if (top_nd == NULL) {
		return;
	}
	inorderTraverse(top_nd->llink);
	printf("%d ", get_data(top_nd));
	inorderTraverse(top_nd->rlink);
}

void preorderTraverse(node* top_nd) {
	if (top_nd == NULL) {
		return;
	}
	printf("%d ", get_data(top_nd));
	preorderTraverse(top_nd->llink);
	preorderTraverse(top_nd->rlink);
}

void postorderTraverse(node* top_nd) {
	if (top_nd == NULL) {
		return;
	}
	postorderTraverse(top_nd->llink);
	postorderTraverse(top_nd->rlink);
	printf("%d ", get_data(top_nd));
}