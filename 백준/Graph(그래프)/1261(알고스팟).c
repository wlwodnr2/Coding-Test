#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 101
#define INF 987654321

int N, M, brokenBrick[MAX][MAX] = { 0, }, Miro[MAX][MAX], front, rear;
int Queue[MAX*MAX][2];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
 
typedef struct Coordinate {
    int x; int y;
}Coordinate;

void EnQueue(int x, int y) {
    Queue[rear][0] = x;
    Queue[rear][1] = y;
    rear = (rear + 1) % (MAX*MAX);
}

Coordinate DeQueue() {
    Coordinate C;
    C.x = Queue[front][0];
    C.y = Queue[front][1];
    front = (front + 1) % (MAX*MAX);
    return C;
}

void bfs() {
    EnQueue(1, 1);
    brokenBrick[1][1] = 0;

    while (front != rear) {
        Coordinate C = DeQueue();

        for (int i = 0; i < 4; i++) {
            int nx = C.x + dx[i];
            int ny = C.y + dy[i];
            if (nx < 1 || ny < 1 || nx > M || ny > N) continue;
            if (Miro[nx][ny] == 1) { //벽인경우
                if (brokenBrick[nx][ny] > brokenBrick[C.x][C.y] + 1) {
                    brokenBrick[nx][ny] = brokenBrick[C.x][C.y] + 1;
                    EnQueue(nx, ny);
                }
            }
            else if (Miro[nx][ny] == 0) { //빈공간인경우
                if (brokenBrick[nx][ny] > brokenBrick[C.x][C.y]) {
                    brokenBrick[nx][ny] = brokenBrick[C.x][C.y];
                    EnQueue(nx, ny);
                }
            }
        }
    }
    return;
}

int main() {
    scanf("%d %d", &N, &M);
    front = 0; rear = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%1d", &Miro[i][j]);
            brokenBrick[i][j] = INF;
        }
    }
    bfs();
    printf("%d", brokenBrick[M][N]);
    return 0;
}
