#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M, arr[10001], check[10001] = {0,}, find_arr[10001], next = 0;

void backtracking(int count) {
	if (count == M) {
		if (next == 1) {
			for (int i = 0; i < M; i++) printf("%d ", arr[i]);
			next = 0;
		}
		else {
			next = 1;
		}
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			if (i == find_arr[count] || next == 1) {
				arr[count] = i;
				backtracking(count + 1);
			}
			check[i] = 0;
		}
	}
}

int main() {
	int down = 1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &find_arr[i]);
	M = N;
	backtracking(0);
	for (int i = 0; i < N-1; i++) {
		if (find_arr[i] < find_arr[i + 1]) down = 0;
	}
	if (down == 1) printf("-1");
	return 0;
}
