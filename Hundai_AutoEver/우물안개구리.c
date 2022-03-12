//Running Time : 30m 04s

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct member {
	int A;
	int B;
}member;

int main(void)
{
	int N, M, W[100001], CheckFrog[100001], count = 0;
	member mem[100001];
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &W[i]); //역기 무게
		CheckFrog[i] = 1;
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &mem[i].A, &mem[i].B); //친분 관계
		if (W[mem[i].A] > W[mem[i].B]) {//A가 B보다 크다면 B는 Best가 아니지
			CheckFrog[mem[i].B] = 0;
		}
		else if (W[mem[i].A] < W[mem[i].B]) {//B가 A보다 크다면
			CheckFrog[mem[i].A] = 0;
		}
		else {
			CheckFrog[mem[i].A] = 0;
			CheckFrog[mem[i].B] = 0;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (CheckFrog[i] == 1) count++;
	}
	printf("%d", count);

	return 0;
}
