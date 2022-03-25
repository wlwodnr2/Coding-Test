#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void primeNumberSieve(int *ar) {
	for (int i = 2; i <= 1000; i++) {
		if (ar[i] == 0) continue;
		for (int j = i+i; j <= 1000; j += i) {
			ar[j] = 0;
		}
	}
}

int main() {
	int N,arr[1001],num, count = 0;
	scanf("%d", &N);
	for (int i = 1; i <= 1000; i++) arr[i] = i;
	primeNumberSieve(arr);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (arr[num] != 0 && num != 1) count++;
	}

	printf("%d", count);

}
