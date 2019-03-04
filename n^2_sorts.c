#include <stdio.h>

int A[10] = {3,4,1,8,2,6,5,9,0,7};

void bubble_sort() {
	int i, j, tmp;
	int is_swaped=1;

	for (i = 9; i >0 && is_swaped; i--) {
		is_swaped = 0;
		for (j = 0; j < i; j++) {
			if (A[j] > A[j + 1]) {
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
				is_swaped = 1;
			}
		}
	}
}

void selection_sort() {
	int i, j, tmp, max;

	for (i = 0; i < 10; i++) {
		max = i;
		for (j = i; j < 10; j++) {
			if (A[j] > A[max]) {
				max = j;
			}
		}
		tmp = A[i];
		A[i] = A[max];
		A[max] = tmp;
	}
}

void insertion_sort() {
	int i, j, v;

	for (i = 2; i < 10; i++) {
		v = A[i];
		j = i;
		while (A[j - 1] > v && j > 0) {
			A[j] = A[j - 1];
			j--;
		}
		A[j] = v;
	}
}

int main() {
	bubble_sort();

	for (int i = 0; i < 10; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

	selection_sort();

	for (int i = 0; i < 10; i++) {
		printf("%d ", A[i]);
	}

	printf("\n");

	insertion_sort();

	for (int i = 0; i < 10; i++) {
		printf("%d ", A[i]);
	}

	return 0;
}