#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, DFS_arr[25][25] = { 0, }, DFS_check[25][25] = { 0, }, count = 0, heap[300];
int dx[] = { -1, 1, 0 , 0 };
int dy[] = { 0, 0 ,-1 ,1 };

// x-1 y
// x+1 y
// x y-1
// x y+1 
void DFS(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N || DFS_arr[nx][ny] == 0) continue; //범위 안 넘고 0 아니라면 
		if (DFS_check[nx][ny]) continue; //이미 거쳐간거면 
		DFS_check[nx][ny] = 1;
		count++;
		DFS(nx, ny);
	}
}

int main(void)
{
	int block_cnt = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &DFS_arr[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (DFS_check[i][j] || DFS_arr[i][j] == 0)continue; //0이면 출력도 안 됨.
			DFS_check[i][j] = 1;
			count = 1;
			DFS(i, j);
			heap[block_cnt] = count;
			block_cnt++;
		}
	}

	for (int i = 1; i < block_cnt; i++) {
		int son = i;
		do { //일단 부모들이 자식들보다 크게 정렬 
			int parent = (son - 1) / 2; // 부모 = (자식 -1)/2
			if (heap[parent] < heap[son]) {
				int temp = heap[parent];
				heap[parent] = heap[son];
				heap[son] = temp;
			}
			son = parent; // 자식이 부모로 이동해서 
		} while (son != 0);
	}

	for (int i = block_cnt - 1; i >= 0; i--) {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int parent = 0;
		int son = 1;
		do {
			son = 2 * parent + 1; //root의 자식
			//자식 중에 더 큰 값을 찾ㄱ기
			if (heap[son] < heap[son + 1] && son < i - 1) {
				son++;
			}
			//루트보다 자식이 더 크다면 교환
			if (heap[parent] < heap[son] && son < i) {
				int temp = heap[parent];
				heap[parent] = heap[son];
				heap[son] = temp;
			}
			parent = son;
		} while (son < i);
	}

	printf("%d\n", block_cnt);
	for (int i = 0; i < block_cnt; i++) {
		printf("%d\n", heap[i]);
	}
	return 0;
}
