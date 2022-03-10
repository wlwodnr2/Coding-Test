#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int M,N,K, M_Btn[100], N_Btn[100];
	scanf("%d %d %d", &M, &N, &K); //입력

	for(int i = 0; i<M; i++){
		scanf("%d", &M_Btn[i]); //Secret Btn
	}

	for(int i = 0; i<N; i++){
		scanf("%d", &N_Btn[i]); //User Btn
	}

	int count =0;
	for(int i = 0; i<N; i++){
		count = 0;
		for (int j =0; j<M; j++){
			if(N_Btn[i+j] == M_Btn[j]){
				count++;
			}
		}
		if(count == M) break;
	}

	if(count == M) printf("secret\n");
	else printf("normal\n");
	
	return 0;
}
