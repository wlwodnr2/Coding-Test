#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int E, S, M, earth = 0, sun = 0, moon = 0, year = 0;
	scanf("%d %d %d", &E, &S, &M);

	while (1) {
		if ((earth == E) && (sun == S) && (moon == M)) {
			printf("%d", year);
			break;
		}
		earth++; sun++; moon++; //
		year++;
		if (earth % 15 == 1) earth = 1;
		if (sun % 28 == 1) sun = 1;
		if (moon % 19 == 1) moon = 1;
	}

	return 0;
}
