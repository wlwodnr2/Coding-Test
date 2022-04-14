#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int S;

typedef struct QueueType {
    int number, clipboard, count;
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

void EnQueue(HeadTail* HT, int num, int clip, int cnt) {
    QueueType* temp = (QueueType*)malloc(sizeof(QueueType));
    if (HT->head == NULL) {
        HT->head = temp;
        HT->tail = temp;
        temp->number = num; temp->count = cnt;  temp->clipboard = clip; temp->next = NULL;
    }
    else {
        HT->tail->next = temp;
        temp->number = num; temp->count = cnt; temp->clipboard = clip; temp->next = NULL;
        HT->tail = HT->tail->next;
    }
}

QueueType *DeQueue(HeadTail* HT) {
    QueueType* temp = HT->head;
    HT->head = HT->head->next;
    return temp;
}

void bfs(HeadTail* HT) {
    while (HT->head != NULL) {
        QueueType *temp = DeQueue(HT);
        if (temp->number == S) {
            printf("%d", temp->count);
            exit(0);
        }
        if (temp->clipboard != 0) { //clip board 0아니라면 이모티콘 clip board 개수만큼 추가
            EnQueue(HT, temp->number + temp->clipboard, temp->clipboard, temp->count + 1);
        }
        if (temp->number > 1) { //화면에 이모티콘 하나 삭제
            EnQueue(HT, temp->number - 1, temp->clipboard, temp->count + 1);
        }
        //clip board 갱신
        EnQueue(HT, temp->number, temp->number, temp->count + 1);
        free(temp);
    }
}

int main() {
    scanf("%d", &S);
    HeadTail* H = (HeadTail*)malloc(sizeof(HeadTail));
    QueueInit(H);
    EnQueue(H, 1, 0, 0);
    bfs(H);
    free(H);
    return 0;
}
