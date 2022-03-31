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
	int dwarf[9], real_dwarf[7] = {0,}, tall = 0, fake_num1, fake_num2, count = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &dwarf[i]);
		tall += dwarf[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if ((tall - (dwarf[i] + dwarf[j])) == 100) {
				fake_num1 = i;
				fake_num2 = j;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (i != fake_num1 && i != fake_num2) real_dwarf[count++] = dwarf[i];
	}
	heap_sort(real_dwarf, 7);
	for (int i = 6; i >= 0; i--) {
		int temp = real_dwarf[0];
		real_dwarf[0] = real_dwarf[i];
		real_dwarf[i] = temp;
		heap_sort(real_dwarf, i);
	}
	for (int i = 0; i < 7; i++) printf("%d\n", real_dwarf[i]);
	return 0;
}
