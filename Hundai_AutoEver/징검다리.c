//Algo tutor 선생님 설명대로 코딩 했는데 틀렸습니다가 뜬다..

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N, A[3001] = { 0, }, rocks[3001] = {0, }, Max_Count = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		rocks[i] = 1; 
	}
	
	for (int i = 1; i < N; i++) {
		int count = 1;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j] && (rocks[j] +1 > count)) {
				count = rocks[j] + 1;
				rocks[i] = count;
			}
		}
		if (rocks[i] > Max_Count) Max_Count = rocks[i];
	}

	printf("%d", Max_Count);
	return 0;
}
