#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, arr[8], check[8] = {0,}, permutation[8], max = 0;

int sum() {
	int sumArray = 0;
	for (int i = 0; i < N - 1; i++) {
		sumArray += abs(permutation[i] - permutation[i + 1]);
	}
	return sumArray;
}

void backtracking(int number) {
	if (number == N) {
		max = max > sum() ? max : sum();
		return;
	}
	for (int i = 0; i < N; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			permutation[number] = arr[i];
			backtracking(number + 1);
			check[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	backtracking(0);
	
	printf("%d", max);
	return 0;
}
