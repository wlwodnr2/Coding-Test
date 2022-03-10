#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int DFS_Check[1001] = {0,};
int BFS_Check[1001] = {0,};
int connect[1001][1001] = {0,};
int queue[1001] = { 0, };

void DFS(int N, int start) {
	DFS_Check[start] = 1; //지나간 점
	printf("%d ", start);
	for (int i = 1; i <= N; i++) {
		if (DFS_Check[i] == 0 && connect[start][i] == 1) { //지나가지 않았고, 시작 점과 연결되어 있다면 
			DFS(N, i); // i가 다시 시작점으로
		}
	}
	return;
}

void BFS(int N, int start) {
    int front = 0, rear = 1;
    BFS_Check[start] = 1; //시작 노드를 큐에서 뺏다고 가정하면서 거쳤다 1
    queue[front] = start; //queue에 시작 하나 추가
    printf("%d ", start);
    while (front < rear) {
        for (int i = 1; i <= N; i++) {
            if (connect[start][i] == 1 && BFS_Check[i] == 0) {
                queue[rear] = i; //queue에 연결 된 노드들 추가
                BFS_Check[i] = 1; //queue에 추가 되었으니 1로 바꿔주고
                rear += 1;
                printf("%d ", i);
            }
        }
        front += 1;
        start = queue[front]; //시작이 queue 다음 값으로.
    }
    return;
}

int main() {
	int N, M, V, x,y;
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &x, &y); //선 연결 
		connect[x][y] = 1;
		connect[y][x] = 1;
	}
	DFS(N, V);
    printf("\n");
    BFS(N, V);
    return 0;
}
