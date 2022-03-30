#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int T, N, arr[2][100001] = {0,};
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int dp[2][100001] = {0,};
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[0][j]);
		}
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[1][j]);
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = dp[1][0] + arr[0][1];
		dp[1][1] = dp[0][0] + arr[1][1];
		for (int i = 2; i < N; i++) {
			dp[0][i] = (dp[1][i - 1] > dp[1][i - 2] ? dp[1][i - 1] : dp[1][i - 2]) + arr[0][i];
			dp[1][i] = (dp[0][i - 1] > dp[0][i - 2] ? dp[0][i - 1] : dp[0][i - 2]) + arr[1][i];
		}
		
		printf("%d\n", dp[0][N - 1] > dp[1][N - 1] ? dp[0][N - 1] : dp[1][N - 1]);
	}
	return 0;
}
