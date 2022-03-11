//Runing_Time 10m 23s

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int DCT[8], step[8];
	for (int i = 0; i < 8; i++) {
		scanf("%d", &DCT[i]);
	}

	if (DCT[0] - DCT[1] == 1) {
		step[0] = 1;
	}
	else if (DCT[0] - DCT[1] == -1) {
		step[0] = -1;
	}
	else {
		step[0] = 0;
	}

	for (int i = 1; i < 7; i++) {
		if (DCT[i] - DCT[i + 1] == 1 && step[i - 1] == 1) {
			step[i] = 1;
			if (i == 6) printf("descending");
		}
		else if (DCT[i] - DCT[i + 1] == -1 && step[i - 1] == -1) {
			step[i] = -1;
			if (i == 6) printf("ascending");
		}
		else {
			printf("mixed");
			break;
		}
	}
	return 0;
}
