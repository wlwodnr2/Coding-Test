#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check[9] = { 0, }, arr[9], N,M;

void backtracking(int count) {
	if (count == M) {
		for (int i = 0; i <M; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			arr[count] = i;
			backtracking(count+1);
			check[i] = 0;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	backtracking(0);

	return 0;
}
