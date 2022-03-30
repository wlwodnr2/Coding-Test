#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, S[1001], max = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &S[i]);
	}

	for (int i = 0; i < N; i++) {
		int count[1001] = {0,}, max_right = 0, max_left = 0;
		for (int j = 0; j <i; j++) { //left
			if (S[j] < S[i]) {
				count[j] = 1;
				for (int k = 0; k < j; k++) { //left
					if (S[k] < S[j] && (count[k] + 1 > count[j])) count[j] = count[k] + 1;
				}
				max_left = max_left > count[j] ? max_left : count[j];
			}
		}
		for (int j = i + 1; j < N; j++) {//right
			if (S[j] < S[i]) {
				count[j] = 1;
				for (int k = i + 1; k < N; k++) {
					if (S[k] > S[j] && (count[k] + 1 > count[j])) count[j] = count[k] + 1;
				}
				max_right = max_right > count[j] ? max_right : count[j];
			}
		}
		max = (max_left + max_right + 1) > max ? (max_left + max_right + 1) : max;
	}
	printf("%d", max);
	return 0;
}
