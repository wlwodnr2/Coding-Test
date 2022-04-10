#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 300

int L, T;
int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};
 
typedef struct QueueType {
    int queue[MAX*MAX][3]; //x, y, count
    int front, rear; //front rear
}QueueType;

typedef struct Position {
    int x, y, count;
}Position;

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

Position DeQueue(QueueType* Q) {
    Position ps;
    ps.x = Q->queue[Q->front][0];
    ps.y = Q->queue[Q->front][1];
    ps.count = Q->queue[Q->front][2];
    Q->front = (Q->front + 1) % (MAX * MAX);
    return ps;
}

void bfs(QueueType* Q, int visit[MAX][MAX], int start_x, int start_y, int end_x, int end_y, int count) {
    EnQueue(Q, start_x, start_y, count);
    visit[start_x][start_y] = 1;
    while (1) {
        Position P = DeQueue(Q);
        start_x = P.x; start_y = P.y; count = P.count;
        if ((start_x == end_x) && (start_y == end_y)) {
            printf("%d\n", count);
            return;
        }
        for (int i = 0; i < 8; i++) {
            if ((start_x + dx[i] < 0) || (start_y + dy[i] < 0) || (start_x + dx[i] >= L) || (start_y + dy[i] >= L)) continue; //범위 넘어가면 continue
            if (visit[start_x + dx[i]][start_y + dy[i]]) continue; //이미 방문했으면 continue
            EnQueue(Q, start_x + dx[i], start_y + dy[i], count + 1);
            visit[start_x + dx[i]][start_y + dy[i]] = 1;
        }
    }
}

int main() {
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int knight_x, knight_y, dest_x, dest_y, cnt = 0, check[MAX][MAX] = {0,};
        QueueType* QT = (QueueType *)malloc(sizeof(QueueType));

        scanf("%d", &L);
        scanf("%d %d", &knight_x, &knight_y);
        scanf("%d %d", &dest_x, &dest_y);

        QueueInit(QT);
        bfs(QT, check, knight_x, knight_y, dest_x, dest_y, cnt);
    }
    return 0;
}
