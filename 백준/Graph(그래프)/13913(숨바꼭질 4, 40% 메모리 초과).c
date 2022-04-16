#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100001
int N, K, visit[MAX + 1] = { 0, };

typedef struct QueueType {
    int number;
    int count;
    int route[MAX];
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

void EnQueue(HeadTail* HT, int number, int count, int *arr) {
    QueueType* temp = (QueueType*)malloc(sizeof(QueueType));
    if (HT->head == NULL) {
        HT->head = temp;
        HT->tail = temp;
        temp->number = number; temp->count = count; temp->next = NULL;
        for (int i = 0; i < count; i++) {
            temp->route[i] = arr[i];
        }
        temp->route[count] = number;
    }
    else {
        temp->number = number; temp->count = count; temp->route[count] = number; temp->next = NULL;
        for (int i = 0; i < count; i++) {
            temp->route[i] = arr[i];
        }
        HT->tail->next = temp;
        HT->tail = temp;
    }
    return;
}

QueueType * DeQueue(HeadTail* HT) {
    QueueType *temp = (QueueType *)malloc(sizeof(QueueType));
    temp = HT->head;
    HT->head = HT->head->next;
    return temp;
}

void bfs(HeadTail* HT) {
    while (HT->head != NULL) {
        QueueType *temp = (QueueType*)malloc(sizeof(QueueType));
        temp = DeQueue(HT);
        if (temp->number == K) {
            printf("%d\n", temp->count);
            for (int i = 0; i <= temp->count; i++) printf("%d ", temp->route[i]);
            free(temp);
            exit(0);
        }
        if ((temp->number * 2 <= MAX) && (visit[temp->number * 2] == 0)) {
            EnQueue(HT, temp->number * 2, temp->count + 1, temp->route);
            visit[temp->number * 2] = 1;
        }
        if ((temp->number - 1 >= 0) && (visit[temp->number - 1] == 0)) {
            EnQueue(HT, temp->number - 1, temp->count + 1, temp->route);
            visit[temp->number - 1] = 1;
        }
        if ((temp->number + 1 <= MAX) && (visit[temp->number + 1] == 0)) {
            EnQueue(HT, temp->number + 1, temp->count + 1, temp->route);
            visit[temp->number + 1] = 1;
        }
        free(temp);
    }
}

int main() {
    int ar[1];
    scanf("%d %d", &N, &K);
    HeadTail* H = (HeadTail*)malloc(sizeof(HeadTail));
    QueueInit(H);
    ar[0] = N;
    EnQueue(H, N, 0, ar);
    visit[N] = 1;
    bfs(H);
    free(H);
    return 0;
}
