#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int A, arr[1001], count[1001] = { 0, }, max = 1;
	scanf("%d", &A);
	for (int i = 0; i < A; i++) {
		scanf("%d", &arr[i]);
		count[i] = 1;
	}

	for (int i = 1; i < A; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if ((arr[i] < arr[j]) && (count[i] < (count[j] +1))) {
				count[i] = count[j] + 1;
			}
		}
		max = count[i] >= max ? count[i] : max;
	}
	printf("%d", max);
	return 0;
}
