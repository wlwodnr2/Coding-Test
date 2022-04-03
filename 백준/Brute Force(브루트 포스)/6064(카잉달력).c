#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int T,M, N, x, y;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int LCM, year = 0;
		scanf("%d %d %d %d", &M, &N, &x, &y);
		
		year = x;
		while (1) {
			LCM = year % N;
			if (LCM == 0) LCM = N;
			if ((year > M * N) || (LCM == y)) {
				break;
			}
			year += M;
		}
		if (year > M * N) printf("-1\n");
		else printf("%d\n", year);
	}

	return 0;
}
