#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void primeNumberSieve(int* ar) {
	for (int i = 1; i <= 1000000; i++) {
		ar[i] = i;
	}
	for (int i = 2; i <= 1000000; i++) {
		if (ar[i] == 0) continue;
		for (int j = i + i; j <= 1000000; j += i) {
			ar[j] = 0;
		}
	}
}

int main() {
	int arr[1000001], num;
	primeNumberSieve(arr);

	while (1) {
		scanf("%d", &num);
		if (num == 0) break;
		for (int i = 2; i <= 1000000; i++) {
			if (arr[i] != 0 && arr[num - arr[i]] != 0) {
				printf("%d = %d + %d\n", num, arr[i], arr[num - arr[i]]);
				break; //소수인경우 
			}
			else if (i == 1000000) printf("Goldbach's conjecture is wrong.\n");
		}
	}
	return 0;
}
