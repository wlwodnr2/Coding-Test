#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//A:65 ~ Z:90
int main(void) {
	int N, arr[26], top = 0;
	double stack[101];
	char calculate[101];
	scanf("%d", &N);
	scanf("%s", &calculate[0]);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < strlen(calculate); i++) {
		if (calculate[i] == '+' || calculate[i] == '-' || calculate[i] == '*' || calculate[i] == '/') {
			switch (calculate[i]) {
				case '+':
					stack[top-2] = (double)stack[top-2] + (double)stack[top-1];
					top--;
					break;
				case '-':
					stack[top - 2] = (double)stack[top - 2] - (double)stack[top - 1];
					top--;
					break;
				case '*':
					stack[top - 2] = (double)stack[top - 2] * (double)stack[top - 1];
					top--;
					break;
				case '/':
					stack[top - 2] = (double)stack[top - 2] / (double)stack[top - 1];
					top--;
					break;
			}
		}
		else {
			stack[top++] = (double)arr[calculate[i]-65];
		}
	}

	printf("%.2f", stack[0]);

	return 0;
}
