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

void BST_insert(node**, element data);
node* BST_search(node*, element data);
void BST_delete(node**, element data);

void main() {
	node* root = make_node(5);

	BST_insert(&root, 7);
	BST_insert(&root, 2);
	BST_insert(&root, 8);
	BST_insert(&root, 3);
	inorderTraverse(root);
	printf("\n");

	printf("%d \n",get_data(BST_search(root, 8)));
	
	BST_delete(&root, 3);
	inorderTraverse(root);
	printf("\n");

	BST_insert(&root, 4);
	BST_insert(&root, 3);
	inorderTraverse(root);
	printf("\n");

	BST_delete(&root, 7);
	inorderTraverse(root);
	printf("\n");

	BST_delete(&root, 5);
	inorderTraverse(root);
	printf("\n");
}

node* make_node(element data) {
	node* new = (node*)malloc(sizeof(node));
	new->data = data;
	new->llink = NULL;
	new->rlink = NULL;

	return new;
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

void BST_insert(node** root,element data) {
	node* parent=*root;
	node* insert;
	node* cursor = *root;

	while (cursor != NULL) {
		if (data == get_data(cursor)) {
			return;
		}

		parent = cursor;

		if (get_data(cursor) < data) {
			cursor = cursor->rlink;
		}
		else {
			cursor = cursor->llink;
		}
	}

	insert = make_node(data);

	if (parent != NULL) {
		if (get_data(parent) < data) {
			connect_right_node(parent, insert);
		}
		else {
			connect_left_node(parent, insert);
		}
	}
	else if (parent == NULL) {
		*root = insert;
	}
}

node* BST_search(node* root, element data) {
	node* cursor = root;

	while (cursor != NULL) {
		if (get_data(cursor) == data) {
			return cursor;
		}
		else if (get_data(cursor) <data) {
			cursor = cursor->rlink;
		}
		else if(get_data(cursor)>data) {
			cursor = cursor->llink;
		}
	}
	return cursor;
}

void BST_delete(node** root, element data) {
	node* virtual_root = make_node(-1);
	node* parent = virtual_root;
	node* current = *root;
	node* delete;

	virtual_root->rlink = *root;

	while (current != NULL && get_data(current) != data) {
		parent = current;

		if (get_data(current) < data) {
			current = current->rlink;
		}
		else if (get_data(current) > data) {
			current = current->llink;
		}
	}

	if (current == NULL) return;
	delete = current;

	if (delete->llink == NULL && delete->rlink == NULL) {
		if (parent->llink == delete) {
			parent->llink = NULL;
		}
		else {
			parent->rlink = NULL;
		}
	}

	else if (delete->llink == NULL || delete->rlink == NULL) {
		if (delete->llink == NULL) {
			parent->rlink = delete->rlink;
			free(delete);
		}
		else {
			parent->llink = delete->llink;
			free(delete);
		}
	}

	else if (delete->llink != NULL && delete->rlink != NULL) {
		node* par_tmp = current;

		current = current->rlink;

		while (current->llink != NULL) {
			par_tmp = current;
			current->llink;
		}

		delete->data = current->data;

		if (par_tmp->llink == current) {
			par_tmp->llink = current->rlink;
		}
		else if (par_tmp->rlink == current) {
			par_tmp->rlink = current->rlink;
		}
		free(current);
	}

	if (virtual_root->rlink != *root) {
		*root = virtual_root->rlink;
	}

	free(virtual_root);
}