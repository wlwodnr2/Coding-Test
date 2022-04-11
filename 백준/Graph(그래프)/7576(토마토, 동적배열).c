#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, M, number = 0;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int** map;
int** visit;

typedef struct QueueType {
    int x, y, date;
    struct QueueType* next;
}QueueType;

typedef struct Queue {
    struct QueueType* head;
    struct QueueType* tail;
}Queue;

void QueueInit(Queue *Q) {
    Q->head = NULL;
    Q->tail = NULL;
}

void EnQueue(Queue *Q, int x, int y, int number) {
    QueueType* temp = (QueueType*)malloc(sizeof(QueueType)); //공간 생성
    if (Q->head == NULL) { //빈 공간이면
        Q->head = temp; Q->tail = temp;
        temp->x = x; temp->y = y; temp->date = number; temp->next = NULL;
        return;
    }
    Q->tail->next = temp;
    temp->x = x; temp->y = y; temp->date = number;
    Q->tail = temp;
    return;
}

QueueType* DeQueue(Queue* Q) {
    QueueType* temp = (QueueType*)malloc(sizeof(QueueType));
    if (Q->head == Q->tail) {
        temp = Q->head;
        Q->head = NULL;
        Q->tail = NULL;
        return temp;
    }
    temp = Q->head;
    Q->head = Q->head->next;
    return temp;
}

void bfs(Queue* Q) {
    while (Q->head != NULL) {
        QueueType* temp = DeQueue(Q);
        for (int i = 0; i < 4; i++) {
            if ((temp->x + dx[i] < 0) || (temp->y + dy[i] < 0) || (temp->x + dx[i] >= N) || (temp->y + dy[i] >= M)) continue;
            if (visit[temp->x + dx[i]][temp->y + dy[i]] || map[temp->x + dx[i]][temp->y + dy[i]] == -1) continue;
            EnQueue(Q, temp->x + dx[i], temp->y + dy[i], temp->date + 1);
            visit[temp->x + dx[i]][temp->y + dy[i]] = 1;
            number = temp->date + 1;
        }
        free(temp);
    }
}

int main() {
    scanf("%d %d", &M, &N);

    map = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        map[i] = (int*)malloc(sizeof(int) * M);
    }

    visit = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        visit[i] = (int*)malloc(sizeof(int) * M);
    }

    Queue* Qu = (Queue*)malloc(sizeof(Queue));
    QueueInit(Qu);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) {
                EnQueue(Qu, i, j, number);
                visit[i][j] = 1;
            }
            else  visit[i][j] = 0; //초기화
        }
    }
    bfs(Qu);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visit[i][j] == 0 && map[i][j] == 0) number = -1;
        }
    }
    printf("%d", number);
    free(Qu);
    free(map);
    free(visit);
    return 0;
}
