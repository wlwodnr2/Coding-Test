//Running Time 45m , 왜 틀린지 이해 안 감

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1. Ai 작업장의 작업 시간
// 2. Bi 작업장의 작업 시간
// 3. Ai 작업장에서 Bi+1 작업장까지 이동 시간
// 4. Bi 작업장에서 Bi+1 작업장까지 이동 시간

// N+1 번째 줄에는 AN 작업장과 BN 작업장의 작업 시간. 
// 0 : A시작 A끝, 1 : A시작 B끝
// 2 : B시작 B끝, 3 : B시작 A끝
int main(void)
{
	int N, A[1001], B[1001], AtoB[1001], BtoA[1001], min_time[2] = {0,};
	scanf("%d", &N); // 작업장 수
	for (int i = 0; i < N; i++) {
		if (i == N - 1) {
			scanf("%d %d", &A[i], &B[i]);
			break;
		}
		scanf("%d %d %d %d", &A[i], &B[i], &AtoB[i], &BtoA[i]);
	}

	for (int i = 0; i < N - 1; i++) {
		if (i == 0) {
			if (A[i] + AtoB[i] + B[i + 1] > B[i] + B[i + 1]) {
				min_time[1] += B[i] + B[i + 1];
			}
			else {
				min_time[1] += A[i] + AtoB[i] + B[i + 1];
			}
			if (B[i] + BtoA[i] + A[i + 1] > A[i] + A[i + 1]) {
				min_time[0] += A[i] + A[i + 1];
			}
			else {
				min_time[0] += B[i] + BtoA[i] + A[i + 1];
			}
		}
		else {
			if (min_time[0] + AtoB[i] + B[i + 1] > min_time[1] + B[i + 1]) {
				min_time[1] += B[i + 1];
			}
			else {
				min_time[1] += AtoB[i] + B[i + 1];
			}
			if (min_time[1] + BtoA[i] + A[i + 1] > min_time[0] + A[i + 1]) {
				min_time[0] += A[i + 1];
			}
			else {
				min_time[0] += BtoA[i] + A[i + 1];
			}
		}
	}
	if (N == 1) {
		min_time[0] = A[0];
		min_time[1] = B[1];
	}
	printf("%d", min_time[0]>min_time[1] ? min_time[1] : min_time[0]);
	return 0;
}
