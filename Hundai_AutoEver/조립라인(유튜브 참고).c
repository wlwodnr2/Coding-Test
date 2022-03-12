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
	int N, A[1001], B[1001], AtoB[1001], BtoA[1001], min_timeA[1001] = {0,}, min_timeB[1001] = {0,};
	scanf("%d", &N); // 작업장 수
	for (int i = 0; i < N; i++) {
		if (i == N - 1) {
			scanf("%d %d", &A[i], &B[i]);
			break;
		}
		scanf("%d %d %d %d", &A[i], &B[i], &AtoB[i], &BtoA[i]);
	}
	min_timeA[0] = A[0];
	min_timeB[0] = B[0];

	for (int i = 0; i < N - 1; i++) {
		min_timeA[i+1] = (min_timeA[i] > min_timeB[i]+BtoA[i] ? min_timeB[i] + BtoA[i] : min_timeA[i]) + A[i+1];
		min_timeB[i+1] = (min_timeB[i] > min_timeA[i] + AtoB[i] ? min_timeA[i] + AtoB[i] : min_timeB[i]) + B[i+1];
	}
	printf("%d", min_timeA[N - 1] > min_timeB[N - 1] ? min_timeB[N - 1] : min_timeA[N - 1]);
	return 0;
}
