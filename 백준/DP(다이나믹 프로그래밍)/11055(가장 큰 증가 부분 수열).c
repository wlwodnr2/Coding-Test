//count 조건 헷갈려서 계속 틀렸었다. 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int A, arr[1001], dp[1001] = {0,}, count[1001] = {0,}, max = 0;
	scanf("%d", &A);
	for (int i = 0; i < A; i++) {
		scanf("%d", &arr[i]);
		count[i] = 1;
	}
	
	dp[0] = arr[0];
	max = dp[0];
	for (int i = 1; i < A; i++) {
		dp[i] = arr[i];
		for (int j = i - 1; j >= 0; j--) {
			if ((arr[i] > arr[j]) && (dp[i] < arr[i] + dp[j])) {
				count[i] = count[j] + 1;
				dp[i] = arr[i] + dp[j];
			}
		}
		max = dp[i] >= max ? dp[i] : max;
	}
	printf("%d", max);
	return 0;
}
