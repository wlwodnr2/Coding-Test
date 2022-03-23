#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	int len, count = 0, iron_count = 0;
	char arr[100010];

	scanf("%s", &arr[0]);
	len = strlen(arr);

	for (int i = 0; i < len; i++) {
		if (i == len - 1) {
			iron_count++;
			continue;
		}
		if (arr[i] == '(' && arr[i + 1] == ')') {
			iron_count += count;
			i++;
		}
		else if (arr[i] == '(') {
			count++;
		}
		else if (arr[i] == ')') {
			iron_count++;
			count--;
		}
	}

	printf("%d", iron_count);

	return 0;
}
