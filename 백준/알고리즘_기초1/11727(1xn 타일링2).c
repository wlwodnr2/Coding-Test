#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, arr[1001];
	scanf("%d", &N);
	arr[1] = 1;
	arr[2] = 3;
	for (int i = 3; i <= N; i++) {
		if (i % 2 == 1) arr[i] = (arr[i - 1] * 2 - 1)%10007;
		else arr[i] = (arr[i - 1] * 2 + 1)%10007;
	}
	printf("%d", arr[N]);

	return 0;
}
