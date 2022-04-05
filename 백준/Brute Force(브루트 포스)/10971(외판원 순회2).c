#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int min = 987654321;

//1번 출발인경우
//2번 출발인경우
//3번 출발인경우
//4번 출발인경우

void cityCost(int arr[11][11], int visited[], int first, int start, int size, int number, int sum) {
	if (number == size) {
		if (arr[start][first] != 0) {
			sum += arr[start][first]; //자기 자신으로 되돌아오기
			min = min > sum ? sum : min;
		}
		return;
	}
	visited[start] = 1;
	for (int i = 1; i <= size; i++) {
		if (visited[i] == 0 && arr[start][i] != 0) { //아직 방문하지 않고, 갈 수 있는 도시여야 한다. 
			visited[i] = 1;
			sum += arr[start][i];  //[시작][끝]
			if (sum < min) {
				cityCost(arr, visited, first, i, size, number + 1, sum);
			}
			sum -= arr[start][i];
			visited[i] = 0;
		}
	}
	return; //완성된 길이 아니면 return
}

int main() {
	int N, W[11][11] = {0,}, check[11] = {0,};
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &W[i][j]);
		}
	}
	for (int i = 1; i <= N; i++) { 
		cityCost(W, check, i, i, N, 1,0);
		check[i] = 0;
	}
	printf("%d", min);
	return 0;
}
