//Running Time : 4H 정도 된 듯.. 어렵다 어려워..

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//차의 방향에 따라
//(1), (5), (9) : Right 방향 - 나머지 1
//(2), (6), (10) : Up 방향 - 나머지 2
//(3), (7), (11) : Left 방향 - 나머지 3
//(4), (8), (12) : Down 방향 - 나머지 0
int N, CrossRoad[101][101][4] = { 0, }, check[101][101] = { 0, }, queue[10001][4] = { 0, }, count = 0;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }; //하우상좌
int signal[12][4] = { {1,1,1,0}, {0,1,1,1}, {1,0,1,1}, {1,1,0,1},
					  {0,1,1,0}, {0,0,1,1}, {1,0,0,1}, {1,1,0,0}, 
					  {1,1,0,0}, {0,1,1,0}, {0,0,1,1}, {1,0,1,0}}; //{하,우,상,좌}

void countingCross(int X, int Y, int direct, int Timer) {
    int front = 0, rear = 1;

    check[X][Y] = 1; //지나갔고
    queue[front][0] = X; //queue에 추가
    queue[front][1] = Y;
	queue[front][2] = direct;
	queue[front][3] = 0;
    
	while (front < rear) {
		for (int k = 0; k < 4; k++) {
			int possible = 0;
			if (queue[front][3] == Timer) break; //Time Over
			int nx = queue[front][0] + dx[k], ny = queue[front][1] + dy[k]; //갈 수 있는 방향 체크 
			if (nx<1 || ny<1 || nx>N || ny>N || check[nx][ny] == 1) continue; //갈 수 없거나 이미 지나간 곳이면 continue 
			for (int i = 0; i < 4; i++) {
				if (CrossRoad[queue[front][0]][queue[front][1]][i]%4 != queue[front][2]) continue; //방향 같은 것이 있는가 ? Up, Down, Right, Left 확인
				if (signal[CrossRoad[queue[front][0]][queue[front][1]][i] - 1][k] == 0) continue; //방향이 같다면 가려는 방향의 신호등이 켜져 있는가 확인, k는 하우상좌 중에 
				possible = 1; //만약 가려는 방향이 신호등에 포함 된다면 
			}
			if (possible == 1) {
				queue[rear][0] = nx;
				queue[rear][1] = ny;
				queue[rear][2] = k % 4; //방향
				queue[rear][3] = queue[front][3] + 1; //시간
				check[nx][ny] = 1; //지나감 체크 
				rear += 1;
			}
		}

		front += 1;
		//Queue Front 이동
		X = queue[front][0]; 
		Y = queue[front][1];
		direct = queue[front][2];
    }
	printf("%d", front);
	return;
}

int main(void)
{
	int T;

	scanf("%d %d", &N, &T);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < 4; k++) {
				scanf("%d", &CrossRoad[i][j][k]); //신호등 입력
			}
		}
	}

	countingCross(1,1,2,T); //시작 1,1 T = 3;

	return 0;
}

/*
예제 )
4 4
2 6 12 9
7 1 11 6
6 3 5 11
6 3 5 11
1 1 12 9
3 11 8 2
1 7 11 9
1 7 11 9
4 6 2 3
2 4 2 4
6 9 2 6
6 9 2 6
4 6 2 3
2 4 2 4
6 9 2 6
6 9 2 6

답 : 11
*/
