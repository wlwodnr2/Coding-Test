#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char S[101],data;
	int alphabet[27] = {0, };

	while ((data = getchar()) != '\n') {
		alphabet[(int)data - 97]++;
	}

	for (int i = 0; i< 26; i++) {
		printf("%d ",alphabet[i]);
	}
	return 0;
}
