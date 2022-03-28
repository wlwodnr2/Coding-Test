#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MOD 1000000000
int main() {
	int N, K, arr[201][201] = {0,}; //arr[N 값][정수 K개수]
	scanf("%d %d", &N, &K);
	
	for (int i = 1; i <= N; i++) {
		arr[i][1] = 1; //일단 K = 1인 경우는 다 1개 
	}

	for (int i = 1; i <= N; i++) { //값은 1부터
		for (int j = 2; j <= K; j++) { //개수 2개부터
			for (int k = 1; k <= i; k++) { 
				arr[i][j] += (arr[k][j - 1]);
				arr[i][j] %= MOD;
			}
			arr[i][j]++;
		}
	}
	printf("%d", arr[N][K]%MOD);
	return 0;
}
