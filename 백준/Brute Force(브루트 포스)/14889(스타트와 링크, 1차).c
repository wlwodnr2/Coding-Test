#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//N은 짝수, 스타트와 링크팀, {4 <= N <= 20}
int min = 987654321;

void balanceChoice(int arr[21][21], int visited[], int start_team_count, int size, int number, int start) {
	if (number == start_team_count) {
		int start_team = 0, link_team = 0;
		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= size; j++) {
				if (visited[i] == 1 && visited[j] == 1 && j != i) {
					start_team += arr[i][j];
				}
				else if (visited[i] == 0 && visited[j] == 0 && j != i) {
					link_team += arr[i][j];
				}
			}
		}
		min = abs(start_team - link_team) > min ? min : abs(start_team - link_team);
		return;
	}

	for (int i = start; i <= size; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			balanceChoice(arr, visited, start_team_count, size, number + 1, i + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	int N, S[21][21], check[21] = { 0, };
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &S[i][j]);
		}
	}
	for (int i = 2; i <= N - 2; i++) {
		balanceChoice(S, check, i, N, 0, 1);
	}
	printf("%d", min);
	return 0;
}
