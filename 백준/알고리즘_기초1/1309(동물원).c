// 1. N번째 줄에 사자가 없는 경우
// 2. N번째 줄에 왼쪽에 사자가 있는 경우
// 3. N번째 줄에 오른쪽에 사자가 있는 경우

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, dp[100001][3] = { 0, }, count;
	scanf("%d", &N);
	dp[0][0] = 1, dp[0][1] = 1, dp[0][2] = 1;
	for (int i = 1; i < N; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2])%9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1])%9901;
	}
	count = (dp[N - 1][0] + dp[N - 1][1] + dp[N - 1][2]) % 9901;
	printf("%d", count);
}
