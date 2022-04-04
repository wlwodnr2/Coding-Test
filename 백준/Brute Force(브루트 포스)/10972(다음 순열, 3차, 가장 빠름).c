#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void heap(int* data, int num) {
	for (int i = 1; i < num; i++) {
		int son = i;
		do {
			int parent = (son - 1) / 2;
			if (data[parent] < data[son]) {
				int temp = data[parent];
				data[parent] = data[son];
				data[son] = temp;
			}
			son = parent;
		} while (son != 0);
	}
}

void nextPermutation(int*arr, int size) {
	int boundary = 0, right_size = 0, right[10001], swap_pos = size;
	for (int i = size; i > 1; i--) {
		if (arr[i] > arr[i - 1]) { //왼쪽 값이 오른쪽 값보다 작은 경우 
			boundary = i - 1; //경계 지점
			right_size = size - boundary; //오른쪽에 남은 갯수

			for (int j = size; j > boundary; j--) {
				if (arr[boundary] < arr[j]) {
					swap_pos = j;
					break;
				}
			}

			swap(arr, boundary, swap_pos); //스왑했고 
			break;
		}
	}

	//오른쪽 배열 정렬을 위한 복사
	for (int j = 0; j < right_size; j++) { 
		right[j] = arr[boundary + 1 + j];
	}

	if (boundary == 0) printf("-1"); //맨 끝
	else {
		heap(right, right_size);
		for (int i = right_size - 1; i >= 0; i--) {
			int temp = right[0];
			right[0] = right[i];
			right[i] = temp;

			heap(right, i);
		}
		for (int i = 1; i <= boundary; i++) printf("%d ", arr[i]);
		for (int i = 0; i < right_size; i++) printf("%d ", right[i]);
	}
	return 0;
}

int main() {
	int N, Array[10001];
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &Array[i]);

	nextPermutation(Array, N);

	return 0;
}
