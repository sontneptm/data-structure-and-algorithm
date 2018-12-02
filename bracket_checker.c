#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct linked_list {
	element data;
	struct linked_list *link;
}llist;

typedef struct llinst_stack {
	llist *head;
}stack;

void stack_init(stack *stk);
void push(stack *stk, element data);
element pop(stack *stk);
element check(stack *stk);
void bracket_checker(char ch[], stack *stk);

int main() {
	stack stk1;
	char ch0[20] = "{A[(i+1)]=0;}";
	char ch1[20] = "if((i==0) && (j==0)";
	char ch2[20] = "A[(i+1])=0;";
	char ch3[20] = "A[i]=f)(";

	bracket_checker(ch0, &stk1);
	bracket_checker(ch1, &stk1);
	bracket_checker(ch2, &stk1);
	bracket_checker(ch3, &stk1);
}

void stack_init(stack *stk) {
	stk->head = NULL;
}

void push(stack *stk, element data) {
	llist *new = (llist*)malloc(sizeof(llist));
	new->data = data;
	new->link = NULL;

	llist *tmp;

	if (stk->head == NULL) {
		stk->head = new;
	}
	else if (stk->head != NULL) {
		tmp = stk->head;
		stk->head = new;
		stk->head->link = tmp;
	}
}

element pop(stack *stk) {
	llist *tmp1;
	element tmp2;

	if (stk->head == NULL) {
		return '!';
	}
	else {
		tmp1 = stk->head;
		tmp2 = stk->head->data;

		stk->head = stk->head->link;
		
		free(tmp1);
		return tmp2;
	}
}

element check(stack *stk) {
	if (stk->head == NULL) {
		return '!';
	}
	else {
		return stk->head->data;
	}
}

void bracket_checker(char ch[], stack *stk) {
	element tmp;

	stack_init(stk);

	for (int i = 0; ch[i] != '\0' && i<20; i++) {
		if (ch[i] == '(' || ch[i] == '{' || ch[i] == '[') {
			push(stk, ch[i]);
		}
		else if (ch[i] == ')' || ch[i] == '}' || ch[i] == ']') {
			tmp = pop(stk);
			if ((ch[i] == ')' && tmp !='(') || (ch[i] == '}' && tmp != '{') || (ch[i] == ']' && tmp != '[')) {
				if (tmp == '!') {
					printf("����2�� ���� �մϴ�! \n");
					return;
				}
				else {
					printf("����3�� ���� �մϴ�! \n");
					return;
				}
			}
		}
	}

	if (check(stk) != '!') {
		printf("����1�� ���� �մϴ�! \n");
		return;
	}
	else{
		printf("�������� ��ȣ ��� �Դϴ�. \n");
	}

	return;
}
