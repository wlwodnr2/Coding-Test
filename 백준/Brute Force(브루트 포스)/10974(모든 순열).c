//backtracking 문제랑 똑같음

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, check[9] = { 0, }, arr[9];

void backtracking(int number) {
	if (number == N) {
		for (int i = 0; i < number; i++) printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			arr[number] = i;
			backtracking(number + 1);
			check[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &N);

	backtracking(0);
	return 0;
}
