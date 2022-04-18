#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

int N, front = 0, rear = 0;
int* parent;

typedef struct Node {
    struct Node* next;
    int data;
}Node;

typedef struct HeadTail {
    Node* head;
    Node* tail;
}HeadTail;

typedef struct Queue {
    int queue[MAX];
}Queue;

void init_Node(HeadTail* H) {
    H->head = NULL;
    H->tail = NULL;
}

void insert_Node(HeadTail* H, int number) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (H->head == NULL) {
        H->head = temp;
        H->tail = temp;
        temp->data = number; temp->next = NULL;
    }
    else {
        temp->data = number; temp->next = NULL;
        H->tail->next = temp;
        H->tail = temp;
    }
}

void EnQueue(Queue* Q, int number) {
    Q->queue[rear] = number;
    rear = (rear + 1) % MAX;
    return;
}

int DeQueue(Queue* Q) {
    int data = Q->queue[front];
    front = (front + 1) % MAX;
    return data;
}

void bfs(HeadTail* H, Queue* Q) {
    while (front != rear) {
        Node* temp = (Node*)malloc(sizeof(Node));
        int start = DeQueue(Q);
        for (temp = H[start].head; temp != NULL; temp = temp->next) {
            if (parent[temp->data] == -1) { // 부모가 안 정해진 경우
                EnQueue(Q, temp->data);
                parent[temp->data] = start + 1;
            }
        }
        free(temp);
    }
}

int main() {
    scanf("%d", &N);

    HeadTail* HT = (HeadTail*)malloc(sizeof(HeadTail) * N);
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    parent = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        init_Node(&HT[i]);
        parent[i] = -1;
    }

    for (int i = 0; i < N-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        insert_Node(&HT[a-1], b-1);
        insert_Node(&HT[b-1], a-1);
    }

    EnQueue(Q, 0);
    parent[0] = 0;
    bfs(HT, Q);
    for (int i = 1; i < N; i++) printf("%d\n", parent[i]);
    free(HT);
    free(Q);
    return 0;
}
