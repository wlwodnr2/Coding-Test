#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
int N, K, visit[MAX+1] = { 0, };

typedef struct QueueType {
    int number;
    int count;
    struct QueueType* next;
}QueueType;

typedef struct HeadTail {
    struct QueueType* head;
    struct QueueType* tail;
}HeadTail;

void QueueInit(HeadTail* HT) {
    HT->head = NULL;
    HT->tail = NULL;
}

void EnQueue(HeadTail* HT, int number, int count) {
    QueueType* temp = (QueueType*)malloc(sizeof(QueueType));
    if (HT->head == NULL) {
        HT->head = temp;
        HT->tail = temp;
        temp->number = number; temp->count = count; temp->next = NULL;
    }
    else {
        temp->number = number; temp->count = count; temp->next = NULL;
        HT->tail->next = temp;
        HT->tail = temp;
    }
    return;
}

QueueType DeQueue(HeadTail* HT) {
    QueueType temp;
    temp.number = HT->head->number;
    temp.count = HT->head->count;
    HT->head = HT->head->next;
    return temp;
}

void bfs(HeadTail* HT) {
    while (HT->head != NULL) {
        QueueType temp = DeQueue(HT);
        if (temp.number == K) {
            printf("%d", temp.count);
            exit(0);
        }
        if ((temp.number - 1 >=0 )&& (visit[temp.number - 1] == 0)) {
            EnQueue(HT, temp.number - 1, temp.count + 1);
            visit[temp.number - 1] = 1;
        }
        if ((temp.number + 1 <= MAX) && (visit[temp.number + 1] == 0)) {
            EnQueue(HT, temp.number + 1, temp.count + 1);
            visit[temp.number + 1] = 1;
        }
        if ((temp.number*2 <= MAX) && (visit[temp.number * 2] == 0)) {
            EnQueue(HT, temp.number*2, temp.count + 1);
            visit[temp.number * 2] = 1;
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);
    HeadTail* H = (HeadTail*)malloc(sizeof(HeadTail));
    QueueInit(H);
    EnQueue(H, N, 0);
    visit[N] = 1;
    bfs(H);
    return 0;
}
