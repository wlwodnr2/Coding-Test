#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, arr[1001];
	scanf("%d", &N);
	arr[0] = 1;
	arr[1] = 2;
	for (int i = 2; i < N; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2])%10007;
	}
	printf("%d", arr[N - 1]);

	return 0;
}
