#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int M, N, map[MAX][MAX], visit[MAX][MAX] = { 0, }, count = 0;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

typedef struct QueueType {
    int queue[MAX * MAX][3];
    int front, rear;
}QueueType;

typedef struct Coordinate {
    int x, y, day_count;
}Coordinate;

void QueueInit(QueueType* Q) {
    Q->front = 0;
    Q->rear = 0;
}

void EnQueue(QueueType* Q, int x, int y, int count) {
    if (Q->front == Q->rear) {
        Q->queue[Q->front][0] = x;
        Q->queue[Q->front][1] = y;
        Q->queue[Q->front][2] = count;
        Q->rear = (Q->rear + 1) % (MAX * MAX);
        return;
    }
    Q->queue[Q->rear][0] = x;
    Q->queue[Q->rear][1] = y;
    Q->queue[Q->rear][2] = count;
    Q->rear = (Q->rear + 1) % (MAX * MAX);
}

Coordinate DeQueue(QueueType* Q) {
    Coordinate C;
    C.x = Q->queue[Q->front][0];
    C.y = Q->queue[Q->front][1];
    C.day_count = Q->queue[Q->front][2];
    Q->front = (Q->front + 1) % (MAX * MAX);
    return C;
}

void bfs(QueueType* Q) {
    while (Q->front != Q->rear) {
        Coordinate Cd = DeQueue(Q);
        visit[Cd.x][Cd.y] = 1;
        for (int i = 0; i < 4; i++) {
            if ((Cd.x + dx[i] < 0) || (Cd.y + dy[i] < 0) || (Cd.x + dx[i] >= M) || (Cd.y + dy[i] >= N)) continue;
            if (visit[Cd.x + dx[i]][Cd.y + dy[i]] || map[Cd.x + dx[i]][Cd.y + dy[i]] == -1 || map[Cd.x + dx[i]][Cd.y + dy[i]] == 1) continue; //이미 방문했거나, 토마토가 없거나, 이미 익었거나
            EnQueue(Q, Cd.x + dx[i], Cd.y + dy[i], Cd.day_count + 1);
            visit[Cd.x + dx[i]][Cd.y + dy[i]] = 1;
            count = Cd.day_count + 1;
        }
    }
}

int main() {
    QueueType* QT = (QueueType*)malloc(sizeof(QueueType));
    QueueInit(QT);
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) EnQueue(QT, i, j, count);
        }
    }
    bfs(QT);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j] && !map[i][j]) count = -1; //방문하지 않았는데 값이 0인 경우
        }
    }
    printf("%d", count);
    return 0;
}
