#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N, stack[100000] = { 0, }, arr[100000], top = -1;
	char output[200000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	int num = 1;
	int idx = 0, result_idx = 0;

	while (1) {
		//스택에 있는 수가 목표 수 보다 낮은 경우
		if (top == -1 || stack[top] < arr[idx]) {
			stack[++top] = num++;
			output[result_idx++] = '+';
		}
		//스택에 있는 수가 목표 수와 같은 경우
		else if (stack[top] == arr[idx]) {
			top--;
			output[result_idx++] = '-';
			idx++;
		}
		//스택에 있는 수가 목표 수 보다 높은 경우
		else {
			printf("NO\n");
			return 0;
		}
		if (result_idx == N * 2) break;
	}

	for (int i = 0; i < result_idx; i++)
		printf("%c\n", output[i]);

	return 0;
}
