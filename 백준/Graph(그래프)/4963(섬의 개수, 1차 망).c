#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int w, h, map[MAX][MAX] = { 0, };
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
typedef struct QueueType {
    int queue[MAX*MAX][2];
    int front;
    int rear;
}QueueType;

typedef struct Coordinate {
    int x;
    int y;
}Coordinate;

void QueueInit(QueueType* Q) {
    Q->front = 0;
    Q->rear = 0;
    return;
}

void EnQueue(QueueType* Q, int data_x, int data_y) {
    if (Q->front == Q->rear) {
        Q->queue[Q->front][0] = data_x;
        Q->queue[Q->front][1] = data_y;
        Q->rear = (Q->rear + 1) % (MAX*MAX);
        return;
    }
    Q->queue[Q->rear][0] = data_x;    // 해당 rear에 데이터 추가
    Q->queue[Q->rear][1] = data_y;
    Q->rear = (Q->rear + 1) % (MAX*MAX); //rear 이동
    return;
}

Coordinate DeQueue(QueueType* Q) {
    if (Q->front == Q->rear) return; //Empty
    Coordinate Cd;
    Cd.x = Q->queue[Q->front][0];
    Cd.y = Q->queue[Q->front][1];
    Q->front = (Q->front + 1) % (MAX*MAX);
    return Cd;
}

void bfs(QueueType* Q, int visit[MAX][MAX], int x, int y) {
    EnQueue(Q, x, y);
    Coordinate Cd;
    visit[x][y] = 1;
    while (Q->front != Q->rear) {
        Cd = DeQueue(Q);
        for (int i = 0; i < 8; i++) {
            if ((Cd.x + dx[i] < 0) || (Cd.x + dx[i] >= w) || (Cd.y + dy[i] < 0) || (Cd.y + dy[i] >= h)) continue;
            if (map[Cd.x + dx[i]][Cd.y + dy[i]] && !visit[Cd.x + dx[i]][Cd.y + dy[i]]) {
                EnQueue(Q, Cd.x + dx[i], Cd.y + dy[i]);
                visit[Cd.x + dx[i]][Cd.y + dy[i]] = 1;
            }
        }
    }
    return;
}

int main() {
    while (1) {
        int check[MAX][MAX] = { 0, }, count = 0;

        scanf("%d %d", &w, &h);
        if (w == 0 && h == 0) return;

        QueueType* QT = (QueueType *)malloc(sizeof(QueueType));
        QueueInit(QT);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (map[i][j] == 1 && !check[i][j]) { //방문 안 했고 육지인 경우에만 
                    bfs(QT, check, i, j);
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
