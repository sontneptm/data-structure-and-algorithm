#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 100

typedef int element;

typedef int com_pri(element, element);

typedef struct array_base_heap {
	com_pri* comp;
	int num_of_data;
	element heap[HEAP_SIZE];
}heap;

void heap_init(heap*, com_pri*);
void heap_insert(heap*, element);
element heap_delete(heap*, element);
int compare_priority(element, element);
void show_all_of_heap(heap*);

int main(int argc, char* argv) {
	heap h1;
	heap* root = &h1;
	heap_init(root,compare_priority);
	heap_insert(root, 9);
	heap_insert(root, 7);
	heap_insert(root, 6);
	heap_insert(root, 5);
	heap_insert(root, 4);
	heap_insert(root, 3);
	heap_insert(root, 2);
	heap_insert(root, 2);
	heap_insert(root, 1);
	heap_insert(root, 3);
	heap_insert(root, 8);
	heap_delete(root, 9);

	show_all_of_heap(root);
}
void heap_init(heap* root, com_pri* comp) {
	root->comp = comp;
	root->num_of_data = 0;
}
void heap_insert(heap* root, element data) {
	int comp_cursor;
	
	root->heap[++(root->num_of_data)]=data;
	comp_cursor = root->num_of_data;

	while (comp_cursor != 1) {
		int parent_key = comp_cursor / 2;

		if (root->comp(root->heap[comp_cursor], root->heap[parent_key]) == 1) {
			element tmp = root->heap[comp_cursor];
			root->heap[comp_cursor] = root->heap[parent_key];
			root->heap[parent_key] = tmp;
			comp_cursor = parent_key;
		}
		else {
			break;
		}
	}
}
element heap_delete(heap* root, element data) {
	int comp_cursor;

	int return_data;
	if (root->num_of_data == 0) {
		printf("\n heap is empty! \n");
		return -1;
	}
	return_data = root->heap[1];
	root->heap[1] = root->heap[(root->num_of_data)--];
	comp_cursor = 1;

	while (comp_cursor <= root->num_of_data) {
		int child_key = root->comp(root->heap[2 * comp_cursor],
			root->heap[2*comp_cursor+1])==1 ? 2*comp_cursor : 2*comp_cursor+1;
		if (root->comp(root->heap[comp_cursor], root->heap[child_key] == 0)) {
			element tmp = root->heap[comp_cursor];
			root->heap[comp_cursor] = root->heap[child_key];
			root->heap[child_key] = tmp;
			comp_cursor = child_key;
		}
		else {
			break;
		}
	}
	return return_data;
}
int compare_priority(element a, element b) {
	return a > b ? 1 : 0;
}
void show_all_of_heap(heap* root) {
	int i;

	for (i = 1; i <= root->num_of_data; i++) {
		printf("%d ", root->heap[i]);
	}
}




