#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10


typedef int element;


typedef struct link_list_node {
	element data;
	struct link_list_node* llink;
	struct link_list_node* rlink;
}node;

node* make_node(element);
void connect_left_node(node*, node*);
void connect_right_node(node*, node*);
int check_height(node*);
int check_length(node*);
void insert_BST_node(node*, element);
node* search_BST_node(node*, element);
void delete_BST_node(node**, element);

void preorder_traverse(node*);
void inorder_traverse(node*);
void postorder_traverse(node*);
void print_terminal_node(node*);
void terminal_check(node*);
int is_BST(node*);

typedef struct array_base_stack {
	element stack[ARRAY_SIZE];
	int top;
}stack;

void stack_init(stack*);
void push(stack*, element);
int pop(stack*);

stack terminal_node;
stack non_terminal_node;


int main(int argc, char* argv) {
	node* root1 = make_node(5);
	node* root2 = make_node(5);

	printf("실습 문제 1\n");
	insert_BST_node(root1, 3);
	insert_BST_node(root1, 7);
	insert_BST_node(root1, 2);
	insert_BST_node(root1, 4);
	insert_BST_node(root1, 6);
	insert_BST_node(root1, 9);
	insert_BST_node(root1, 1);
	insert_BST_node(root1, 8);
	insert_BST_node(root1, 10);
	printf("전위순회 :");
	preorder_traverse(root1);
	printf("\n중위순회 :");
	inorder_traverse(root1);
	printf("\n후위순회 :");
	postorder_traverse(root1);
	printf("\n");
	printf("트리의 높이 : %d \n", check_height(root1));
	print_terminal_node(root1);
	printf("\n'8'탐색중 거친 곳 : "); search_BST_node(root1, 8);

	printf("\n실습 문제 2\n");
	insert_BST_node(root2, 7);
	insert_BST_node(root2, 2);
	insert_BST_node(root2, 8);
	insert_BST_node(root2, 3);
	delete_BST_node(&root2,3);
	insert_BST_node(root2, 4);
	insert_BST_node(root2, 3);
	delete_BST_node(&root2, 7);
	delete_BST_node(&root2, 5);
	printf("\n중위순회 :");
	inorder_traverse(root2);
	printf("\n전위순회 :");
	preorder_traverse(root2);

	printf("\n실습 문제 3\n");
	node* root3 = make_node(5);
	node* no1 = make_node(4);
	node* no2 = make_node(3);
	node* no3 = make_node(6);
	node* no4 = make_node(10);
	node* no5 = make_node(12);
	node* no6 = make_node(17);
	connect_left_node(root3, no1);
	connect_right_node(root3, no4);
	connect_left_node(no1, no2);
	connect_right_node(no1, no3);
	connect_left_node(no4, no5);
	connect_right_node(no4, no6);
	
	is_BST(root3) == 0 ? printf("이진탐색트리입니다.\n") : printf("이진탐색트리가아닙니다.\n");
	printf("이진트리의 간선 길이 : %d \n", check_length(root3));



	return 0;
}

node* make_node(element data) {
	node* new = (node*)malloc(sizeof(node));
	new->data = data;
	new->llink = NULL;
	new->rlink = NULL;

	return new;
}
void connect_left_node(node* parent, node* child) {
	parent->llink = child;
}
void connect_right_node(node* parent, node*child) {
	parent->rlink = child;
}
void insert_BST_node(node* root, element data) {
	node* insert;
	node* cur_parent = root;
	node* cursor = root;

	if (cursor->data == data) {
		return;
	}
	while (cursor != NULL) {
		cur_parent = cursor;

		if (cursor->data < data) {
			cursor = cursor->rlink;
		}
		else {
			cursor = cursor->llink;
		}
	}

	insert = make_node(data);

	if (cur_parent->data < data) {
		cur_parent->rlink = insert;
	}
	else {
		cur_parent->llink = insert;
	}
}

node* search_BST_node(node* root, element data) {
	node* cursor = root;

	while (cursor != NULL && cursor->data != data) {
		printf("%d ", cursor->data);
		if (cursor->data < data) {
			cursor = cursor->rlink;
		}
		else {
			cursor = cursor->llink;
		}
	}
	if (cursor == NULL) {
		printf("해당 데이터가 없습니다.");
		return NULL;
	}
	return cursor;
}

void delete_BST_node(node** root, element data) {
	node* virtual_node = make_node(-1);
	node* cur_parent = virtual_node;
	node* cursor = *root;
	node* delete;
	

	connect_right_node(virtual_node, *root);

	while (cursor->data != data && cursor != 0) {
		cur_parent = cursor;
		if (cursor->data < data) {
			cursor = cursor->rlink;
		}
		else {
			cursor = cursor->llink;
		}
	}

	if (cursor == NULL) printf("\n그런 데이터가 없습니다!");
	delete = cursor;

	if (delete->llink == NULL && delete->rlink == NULL) {
		if (cur_parent->data < delete->data) {
			cur_parent->rlink = NULL;
		}
		else {
			cur_parent->llink = NULL;
		}
	}
	else if (delete->llink==NULL || delete->rlink==NULL) {
		if (cur_parent->rlink == delete) {
			if (delete->llink != NULL) {
				cur_parent->rlink = delete->llink;
			}
			else {
				cur_parent->rlink = delete->rlink;
			}
		}
		else if (cur_parent->llink == delete) {
			if (delete->llink != NULL) {
				cur_parent->llink = delete->llink;
			}
			else {
				cur_parent->llink = delete->rlink;
			}
		}
	}
	else if (delete->llink !=NULL && delete->rlink != NULL) {
		node* tmp_parent = delete;
		cursor = delete->rlink;

		while (cursor->llink != NULL) {
			tmp_parent = cursor;
			cursor=cursor->llink;
		}

		delete->data = cursor->data;
		
		if (tmp_parent->rlink == cursor) {
			tmp_parent->rlink = cursor->rlink;
		}
		else {
			tmp_parent->llink = cursor->rlink;
		}
	}

	if (virtual_node->rlink != *root) {
		*root = virtual_node->rlink;
	}

	free(virtual_node);
}

int is_BST(node* root) {
	int bst_check = 0;

	if (root == NULL ) {
		return 0;
	}
	if (root->llink != NULL) {
		if (root->llink->data > root->data) {
			return 1;
		}
	}
	if (root->rlink != NULL) {
		if (root->rlink->data < root->data) {
			return 1;
		}
	}

	return(0 + is_BST(root->llink) + is_BST(root->rlink));	
}

int check_height(node* root) {
	int height = 0;
	if (root == NULL) {
		return 0;
	}
	height = 1 + (max(check_height(root->llink), check_height(root->rlink)));
	return height;
}

int check_length(node* root) {
	int length=0;
	if (root == NULL) {
		return 0;
	}
	if (root->llink != NULL) {
		length++;
	}
	if (root->rlink != NULL) {
		length++;
	}
	length = length+ check_length(root->llink) + check_length(root->rlink);
	return length;
}
void preorder_traverse(node* root) {
	if (root == NULL) {
		return;
	}
	
	printf("%d ", root->data);
	preorder_traverse(root->llink);
	preorder_traverse(root->rlink);
}
void inorder_traverse(node* root) {
	if (root == NULL) {
		return;
	}
	inorder_traverse(root->llink);
	printf("%d ", root->data);
	inorder_traverse(root->rlink);
}
void postorder_traverse(node* root) {
	if (root == NULL) {
		return;
	}
	postorder_traverse(root->llink);
	postorder_traverse(root->rlink);
	printf("%d ", root->data);
}

void print_terminal_node(node* root) {
	int i;
	stack_init(&terminal_node);
	stack_init(&non_terminal_node);
	
	terminal_check(root);

	printf("단말노드 : ");
	for (i = 0; terminal_node.top!=-1; i++) {
		printf("%d, ",pop(&terminal_node));
	}
	printf("\n비단말노드 : ");
	for (i = 0; non_terminal_node.top != -1; i++) {
		printf("%d, ",pop(&non_terminal_node));
	}
}

void terminal_check(node* root) {
	if (root == NULL) {
		return;
	}
	else if (root->llink == NULL && root->rlink == NULL) {
		push(&terminal_node,root->data);
		return;
	}
	
	terminal_check(root->llink);
	terminal_check(root->rlink);
	push(&non_terminal_node, root->data);
	
}

void stack_init(stack* stk) {
	int i;
	for (i = 0; i < ARRAY_SIZE; i++) {
		stk->stack[i] = -1;
	}
	stk->top = -1;
}
void push(stack* stk, element data) {
	if (stk->top == ARRAY_SIZE - 1) {
		printf("\n stack full! \n");
		return;
	}
	stk->stack[++(stk->top)] = data;
}
int pop(stack* stk) {
	if (stk->top == -1) {
		printf("\n stack empty! \n");
		return -1;
	}
	int tmp;
	tmp = stk->stack[stk->top--];
	return tmp;
}