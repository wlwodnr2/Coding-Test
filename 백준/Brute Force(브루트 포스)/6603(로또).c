#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int lotto_number[6];

void Lotto(int arr[], int visited[], int size, int number, int start) {
	if (number == 6) { //6개가 되면
		for (int i = 0; i < 6; i++) printf("%d ",lotto_number[i]);
		printf("\n");
		return;
	}

	for (int i = start; i < size; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			lotto_number[number] = arr[i]; //로또 번호 추가
			Lotto(arr, visited, size, number + 1,i+1); //개수 하나 추가 된것과 시작 번호 + 1된 것 
			visited[i] = 0;
		}
	}
}

int main() {
	int k, S[13];
	while (1) {
		int check[13] = {0,};
		scanf("%d", &k);
		if (k == 0) break;
		for (int i = 0; i < k; i++) scanf("%d", &S[i]);
		Lotto(S,check,k,0,0);
		printf("\n");
	}
	return 0;
}
