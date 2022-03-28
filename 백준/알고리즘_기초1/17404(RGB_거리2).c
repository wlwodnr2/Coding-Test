#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, house[1001][3] = {0,}, bill[1001][3] = {0,}, min = 987654321;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &bill[i][0], &bill[i][1], &bill[i][2]);
	}

	for (int j = 0; j < 3; j++) { //Red 시작 j = 0, Green 시작 j = 1, Blue 시작 j = 2
		for (int k = 0; k < 3; k++) {
			if (j == k) house[0][k] = bill[0][k];
			else house[0][k] = 987654321;
		}
		for (int k = 1; k < N; k++) {
			house[k][0] = bill[k][0] + (house[k - 1][1] > house[k - 1][2] ? house[k - 1][2] : house[k - 1][1]);
			house[k][1] = bill[k][1] + (house[k - 1][0] > house[k - 1][2] ? house[k - 1][2] : house[k - 1][0]);
			house[k][2] = bill[k][2] + (house[k - 1][0] > house[k - 1][1] ? house[k - 1][1] : house[k - 1][0]);
		}
		for (int k = 0; k < 3; k++) {
			if (j != k) min = min > house[N - 1][k] ? house[N - 1][k] : min;
		}
	}
	printf("%d", min);
	return 0;
}
