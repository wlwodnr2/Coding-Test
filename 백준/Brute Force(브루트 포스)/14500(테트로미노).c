#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;

//N좌표, M좌표
int tetromino[19][3][2] = { {{0,1},{0,2},{0,3}}, {{1,0},{2,0},{3,0}} , {{0,1},{1,0},{1,1}}, 
							{{1,0}, {2,0}, {2,1}}, {{1,0}, {1,-1}, {1,-2}}, {{0,1}, {1,1}, {2,1}}, {{1,0},{0,1},{0,2}}, //ㄱ 돌린거
							{{1,0}, {2,0}, {2,-1}}, {{1,0}, {1,1}, {1,2}}, {{0,1}, {1,0}, {2,0}}, {{0,1},{0,2},{1,2}}, //ㄴ 돌린거 
							{{1,0}, {1,1}, {2,1}}, {{0,1}, {1,0}, {1,-1}}, {{1,0}, {1,-1}, {2,-1}}, {{0,1},{1,1},{1,2}}, // 번개 돌린거
							{{0,1}, {1,1}, {0,2}}, {{1,0}, {1,1}, {2,0}}, {{1,0}, {1,-1}, {1,1}}, {{1,0},{1,-1},{2,0}}, //ㅗ 돌린것들
};
//x, y: 시작점
int SumTetromino(int arr[501][501], int x, int y) {
	int dx[4], dy[4], maxSum = 0;
	dx[0] = x; dy[0] = y;
	for (int i = 0; i < 19; i++) { //19개의 테트로미노
		int temp = 0;
		for (int j = 0; j < 3; j++) {
			dx[j + 1] = x + tetromino[i][j][0];
			dy[j + 1] = y + tetromino[i][j][1];
		}
		for (int j = 0; j < 4; j++) {
			if (dx[j] < 0 || dx[j] >= N || dy[j] < 0 || dy[j] >= M) { //범위 넘으면
				temp = 0;
				break;
			}
			temp += arr[dx[j]][dy[j]]; 
		}

		maxSum = maxSum > temp ? maxSum : temp;
	}
	return maxSum;
}

int main() {
	int paper[501][501] = {0,}, max = 0;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &paper[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int sum = SumTetromino(paper, i, j);
			max = max > sum ? max : sum;
		}
	}
	printf("%d", max);

	return 0;
}
