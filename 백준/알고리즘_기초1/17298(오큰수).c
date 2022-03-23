#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N, NGE[1000001] = { 0, }, arr[1000001], stack[1000001], top = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	stack[0] = 0;
	for (int i = 1; i < N; i++) {
		while (top >= 0 && arr[stack[top]] < arr[i]) {
			NGE[stack[top]] = arr[i];
			stack[top--] = -1;
		}
		stack[++top] = i;
	}
	for (int i = top; i >= 0; i--) {
		NGE[stack[i]] = -1;
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", NGE[i]);
	}
	
	return 0;
}
