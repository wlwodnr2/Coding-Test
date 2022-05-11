#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10001

int N, front = 0, rear = 0, max = 0, max_index;

/* 1번 노드에서 가장 먼 노드, 해당 노드에서 또 가장 먼 노드 = 지름 */
typedef struct Node {
    struct Node* next;
    int data;
    int length;
}Node;

typedef struct HeadTail {
    Node* head;
    Node* tail;
}HeadTail;

typedef struct Queue {
    int queue[MAX][2];
}Queue;

void init_Node(HeadTail* H) {
    H->head = NULL;
    H->tail = NULL;
}

void insert_Node(HeadTail* H, int number, int len) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (H->head == NULL) {
        H->head = temp;
        H->tail = temp;
        temp->data = number; temp->length = len; temp->next = NULL;
    }
    else {
        temp->data = number; temp->length = len; temp->next = NULL;
        H->tail->next = temp;
        H->tail = temp;
    }
}

void EnQueue(Queue* Q, int number, int len) {
    Q->queue[rear][0] = number;
    Q->queue[rear][1] = len;
    rear = (rear + 1) % MAX;
    return;
}

int* DeQueue(Queue* Q) {
    int* data = Q->queue[front];
    front = (front + 1) % MAX;
    return data;
}

void bfs(HeadTail* H, Queue* Q, bool visit[]) {
    while (front != rear) {
        Node* temp = (Node*)malloc(sizeof(Node));
        int* start = DeQueue(Q);
        visit[start[0]] = 1;
        for (temp = H[start[0]].head; temp != NULL; temp = temp->next) {
            if (visit[temp->data] == 0) {
                EnQueue(Q, temp->data, start[1] + temp->length);
            }
        }
        if (max < start[1]) {
            max = start[1];
            max_index = start[0];
        }
        free(temp);
    }
}

int main() {
    scanf("%d", &N);

    HeadTail* HT = (HeadTail*)malloc(sizeof(HeadTail) * N);
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    bool* visit = (bool*)malloc(sizeof(bool) * N);

    for (int i = 0; i < N; i++) {
        init_Node(&HT[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b, ln;
        scanf("%d %d %d", &a, &b, &ln);
        insert_Node(&HT[a - 1], b - 1, ln);
        insert_Node(&HT[b - 1], a - 1, ln);
    }

    for (int i = 0; i < N; i++) visit[i] = 0;
    EnQueue(Q, 0, 0);
    bfs(HT, Q, visit);
    front = 0, rear = 0;

    for (int i = 0; i < N; i++) visit[i] = 0;
    EnQueue(Q, max_index, 0);
    bfs(HT, Q, visit);

    printf("%d", max);
    free(HT); free(Q);
    return 0;
}
