//Runnig Time : 14m 30s

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct section {
	int start;
	int end;
}section;

int main(void)
{
	int N, K, S[1000001];
	section sec[10001];

	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &S[i]);
	}
	for (int i = 1; i <= K; i++) {
		scanf("%d %d", &sec[i].start, &sec[i].end);
	}

	for (int i = 1; i <= K; i++) {
		float avg = 0;
		for (int j = sec[i].start; j <= sec[i].end; j++) {
			avg += S[j];
		}
		printf("%0.2lf\n", round(avg / (sec[i].end - sec[i].start + 1)*100)/100);
	}

	return 0;
}
