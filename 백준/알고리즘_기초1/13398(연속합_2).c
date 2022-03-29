#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXRANGE 100010
int main() {
	int N, dp[MAXRANGE] = { 0, }, sum[2][MAXRANGE], index = -1, max = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &dp[i]);

	sum[0][0] = dp[0]; //그냥 더한 경우
	sum[1][0] = dp[0];

	if (dp[0] >= 0) sum[1][0] = dp[0]; //맨 처음 값이 양수인 경우에는 안 빼고 그대로 값 대입
	else { //음수인 경우 index에 0번을 넣어준다. 
		if (N == 1) sum[1][0] = dp[0];
		else {
			sum[1][0] = 0;
		}
	}
	max = dp[0];
	for (int i = 1; i < N; i++) {
		if (dp[i] >= 0) { //양수인 경우
			sum[0][i] = (dp[i] + sum[0][i - 1]) > dp[i] ? dp[i] + sum[0][i - 1] : dp[i]; //정상적으로 더하는 경우 이전 값의 합 + 내가 커? 아님 그냥 내가 커?
			sum[1][i] = sum[1][i - 1] + dp[i]; //앞에서 하나 뺀 경우라인은 그냥 더해주면 된다. 왜냐면 양수값이니깐
		}
		else { // 음수인경우
			if (sum[1][i - 1] + dp[i] > sum[0][i - 1]) { //하나 뺀 라인 갈 때 음수 만나면~ 하나 뺀 라인의 이전값 + 현재값 > 정상 라인 이전 값 보다 큰가 ? 
				sum[1][i] = sum[1][i - 1] + dp[i]; 
			}
			else {
				sum[1][i] = sum[0][i - 1]; //해당 음수를 뺀 값 
			}

			sum[0][i] = sum[0][i - 1] + dp[i]; //정상적으로 더하는 경우 그냥 더해 음수니깐
		}
		max = max > sum[0][i] ? max : sum[0][i];
		max = max > sum[1][i] ? max : sum[1][i];
		max = max > dp[i] ? max : dp[i];
	}
	printf("%d", max);
	return 0;
}
