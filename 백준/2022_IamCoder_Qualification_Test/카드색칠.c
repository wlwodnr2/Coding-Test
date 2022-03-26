#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000001
int main() {
	int N, arr[MAX] = {0,};
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < N; i++) {
		int rgb[4] = { 0, };
		if (arr[i] == 0) {
			if (i == 0) {
				rgb[arr[i + 1]] = 1;
			}
			else if (i == N - 1) {
				rgb[arr[i - 1]] = 1;
			}
			else {
				rgb[arr[i + 1]] = 1;
				rgb[arr[i - 1]] = 1;
			}
			for (int j = 1; j <= 3; j++) {
				if (rgb[j] == 0) {
					arr[i] = j;
					break;
				}
			}
		}
		else if ((i != N - 1) && (arr[i] == arr[i + 1])) {
			printf("-1");
			return 0;
		}
	}
	for (int i = 0; i < N; i++) printf("%d ", arr[i]);
	return 0;
}
