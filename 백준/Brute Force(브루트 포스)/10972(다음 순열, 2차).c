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
	int pos = 0, right_size = 0, right[10001], swap_pos = size, min = 987654321;
	for (int i = size; i > 1; i--) {
		if (arr[i] > arr[i - 1]) { //왼쪽 값이 오른쪽 값보다 작은 경우 
			pos = i - 1; //끊긴 지점
			right_size = size - pos; //오른쪽에 남은 갯수
			break;
		}
	}
	for (int j = pos+1; j <= size; j++) { //오른쪽부터 맨 끝 중에 끊긴 값보다 큰데 제일 작은 값
		if (arr[pos] < arr[j] && min > arr[j]) { //큰경우
			min = arr[j];
			swap_pos = j;
		}
	}
	swap(arr, pos, swap_pos);
	for (int j = 0; j < right_size; j++) { //배열 이동
		right[j] = arr[pos + 1 + j];
	}

	if (pos == 0) printf("-1"); //맨 끝
	else {
		if (right_size != 1) { //오른쪽 정렬
			heap(right, right_size);
			for (int i = right_size - 1; i >= 0; i--) {
				int temp = right[0];
				right[0] = right[i];
				right[i] = temp;

				heap(right, i);
			}
		}
		for (int i = 1; i <= pos; i++) printf("%d ", arr[i]);
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
