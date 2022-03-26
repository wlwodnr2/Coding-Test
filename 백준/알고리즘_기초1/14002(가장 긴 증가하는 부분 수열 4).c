#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N,arr[1001], count[1001] = {0,}, max = 1, max_value[1001] = { 0, }, index = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	count[0] = 1;
	max_value[1] = arr[0];
	for (int i = 1; i < N; i++) {
		count[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] > arr[j] && (count[i] < (count[j] + 1))) {
				count[i] = count[j] + 1;
			}
		}
		max = (max > count[i]) ? max : count[i];
		if (max == count[i]) {
			max_value[max] = arr[i]; 
			index = i; //제일 큰 값 인덱스 저장 
		}
	}
	printf("%d\n", max);
	int max_value_index = max - 1;
	for (int i = index-1; i >= 0; i--) { //제일 큰 값 인덱스 - 1부터
		if (max_value_index == count[i] && (max_value[max_value_index + 1] > arr[i])) { //max값이 같고 다음 값보다 작은 경우 
			max_value[max_value_index--] = arr[i];
		}
	}

	for (int i = 1; i <= max; i++) printf("%d ", max_value[i]);
	
	return 0;
}
