#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

// 변 사이에 생기는 점과 중심에 생기는 점으로 정사각형 점들이 생성되고, 4개의 점이 존재한다면 그 사이에 3개의 변이 존재하기 때문에 그 다음 생기는 점의 총 개수는 4+3의 정사각형 개수이다. 

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
