#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N, NGF[1000001] = { 0, }, arr[1000001], stack[1000001], count[1000001] = { 0, }, top = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		count[arr[i]]++;
	}

	stack[0] = 0;

	for (int i = 1; i < N; i++) {

		while (top >= 0 && count[arr[stack[top]]] < count[arr[i]]) {
			NGF[stack[top]] = arr[i];
			top--;
		}
		stack[++top] = i;
	}
	for(int i = top; i >= 0; i--) {
		NGF[stack[i]] = -1;
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", NGF[i]);
	}

	return 0;
}
