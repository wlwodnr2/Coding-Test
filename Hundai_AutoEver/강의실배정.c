//유튜브 강의대로 힙 정렬 사용해서 O(nlogn)인데 왜 시간초과 나는지 모르겠다. 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct classTime {
	int start;
	int end;
}classTime;

void heapsort(classTime* time, int num) {
	for (int i = 1; i < num; i++) {
		int son = i;
		do {
			int parent = (son - 1) / 2;
			if (time[parent].end < time[son].end) {
				classTime temp = time[parent];
				time[parent] = time[son];
				time[son] = temp;
			}
			son = parent;
		} while (son != 0);
	}
}

int main(void)
{
	int N, count = 1, current = 0, after = 1;
	classTime cT[1000001];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &cT[i].start, &cT[i].end);
	}

	heapsort(cT, N);
	for (int i = N - 1; i >= 0; i--)
	{
		classTime temp = cT[i]; //교환 
		cT[i] = cT[0];
		cT[0] = temp;
		heapsort(cT, i);
	}

	while (after < N) {
		if (cT[after].start >= cT[current].end)
		{
			current = after;
			count++;
		}
		after++;
	}

	printf("%d", count);
	return 0;
}
