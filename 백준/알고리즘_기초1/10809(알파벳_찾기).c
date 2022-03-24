#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char data;
	int alphabet[27], count = 0;

	for (int i = 0; i < 26; i++) alphabet[i] = -1;

	while ((data = getchar()) != '\n') {
		if(alphabet[(int)data-97] == -1) alphabet[(int)data - 97] = count;
		count++;
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", alphabet[i]);
	}
	return 0;
}
