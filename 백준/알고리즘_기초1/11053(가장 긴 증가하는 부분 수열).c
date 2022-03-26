#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N,arr[1001], count[1001] = {0,}, max = 1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	count[0] = 1;
	for (int i = 1; i < N; i++) {
		count[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if(arr[i] > arr[j] && (count[i] < (count[j]+1))) count[i] = count[j] + 1;
		}
		max = (max > count[i]) ? max : count[i];
	}
	printf("%d", max);
	return 0;
}
