#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void heap_sort(int* arr, int N) {
	for (int i = 1; i < N; i++) {
		int son = i;
		do {
			int parent = (son - 1) / 2;
			if (arr[parent] < arr[son]) {
				int temp = arr[son];
				arr[son] = arr[parent];
				arr[parent] = temp;
			}
			son = parent;
		} while (son != 0);

	}
}

int main() {
	int dwarf[9], tall = 0, count = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &dwarf[i]);
		tall += dwarf[i];
	}

	heap_sort(dwarf, 9);
	for (int i = 8; i >= 0; i--) {
		int temp = dwarf[0];
		dwarf[0] = dwarf[i];
		dwarf[i] = temp;
		heap_sort(dwarf, i);
	}

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if ((tall - (dwarf[i] + dwarf[j])) == 100) {
				for (int z = 0; z < 9; z++) {
					if (z != i && z != j) printf("%d\n", dwarf[z]);
				}
			}
		}
	}

	return 0;
}
