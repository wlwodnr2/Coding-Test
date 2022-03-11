//Running Time : 46m 37s

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct elevator {
	int Len;
	int Vel;
}elevator;

int main(void)
{
	int N, M, Max_Vel = 0, currentPos = 0, PartLength = 0;
	elevator N_Ev[100], M_Ev[100];


	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &N_Ev[i].Len, &N_Ev[i].Vel);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &M_Ev[i].Len, &M_Ev[i].Vel);
	}

	for (int i = 0; i < M; i++) {
		Max_Vel = (M_Ev[i].Vel - N_Ev[currentPos].Vel) > Max_Vel ? M_Ev[i].Vel - N_Ev[currentPos].Vel : Max_Vel;
		PartLength += M_Ev[i].Len;
		if (N_Ev[currentPos].Len < PartLength) {
			M_Ev[i].Len = PartLength - N_Ev[currentPos].Len;
			PartLength = 0;
			currentPos++;
			i--;
		}
		else if (N_Ev[currentPos].Len == PartLength) {
			PartLength = 0;
			currentPos++;
		}
	}

	printf("%d", Max_Vel);
	return 0;
}
