#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() {
	int N, dp[31] = {0,};
	scanf("%d", &N);
	dp[2] = 3;
	for (int i = 4; i <= N; i++) {
		if (i % 2 == 0) { //짝수인 경우만
			dp[i] += dp[i - 2] * 3;
			for (int j = i-4; j >=2; j-=2) {
				dp[i] += dp[j] * 2;
			}
			dp[i] += 2;
		}
	}
	printf("%d", dp[N]);
	return 0;
}
