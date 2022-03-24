#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	int num_top = 0, char_top = 0, count = 0;
	char calculate[110], stackNum[110], stackChar[110];
	scanf("%s", &calculate[0]);

	for (int i = 0; i < strlen(calculate); i++) {
		if ('A' <= calculate[i] && calculate[i] <= 'Z') {
			stackNum[num_top++] = calculate[i];
		}
		else {
			switch (calculate[i]) {
			case '(':
				stackChar[char_top++] = calculate[i];
				break;
			case ')':
				while (char_top > 0 && stackChar[--char_top] != '(') {
					stackNum[num_top++] = stackChar[char_top];
				}
				break;
			case '+':
			case '-':
				while (char_top > 0 && stackChar[char_top-1] != '(') {
					stackNum[num_top++] = stackChar[--char_top];
				}

				stackChar[char_top++] = calculate[i];
				break;
			case '*':
			case '/':
				if (char_top>0 && (stackChar[char_top - 1] == '*' || stackChar[char_top - 1] == '/')) {
					stackNum[num_top++] = stackChar[--char_top];
				}
				stackChar[char_top++] = calculate[i];
				break;
			}
		}
	}
	for (int i = char_top-1; i >= 0; i--) {
		stackNum[num_top++] = stackChar[i];
	}
	for (int i = 0; i < num_top; i++) {
		printf("%c", stackNum[i]);
	}

	return 0;
}
