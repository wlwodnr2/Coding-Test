#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void)
{
	int N, oneLineSpot;
	oneLineSpot = 2;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		oneLineSpot += oneLineSpot - 1;
	}

	printf("%d\n", oneLineSpot*oneLineSpot);

	return 0;
}
