#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100000

int V, front = 0,rear = 0, max = 0, max_index;
/* 노드와 간선 정보가 들어 있음 */
typedef struct Node {
    int number;
    int length;
    struct Node* next;
}Node;

typedef struct HeadTail {
    Node* head;
    Node* tail;
}HeadTail;

void nodeInit(HeadTail* HT) {
    HT->head = NULL;
    HT->tail = NULL;
}

/* 연결리스트 구현 */
void connectNode(HeadTail* HT, int num, int len) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (HT->head == NULL) {
        HT->head = temp;
        HT->tail = temp;
        temp->number = num; temp->length = len; temp->next = NULL;
    }
    else {
        temp->number = num; temp->length = len; temp->next = NULL;
        HT->tail->next = temp;
        HT->tail = temp;
    }
    return;
}

/* Node를 넣기 위한 Queue 구조체 */
typedef struct QueueType {
    int data[MAX][2];
}QueueType;

void QueuePush(QueueType *Q, int num, int len) {
    Q->data[rear][0] = num;
    Q->data[rear][1] = len;
    rear = (rear + 1) % MAX;
    return;
 }

int* QueuePop(QueueType* Q) {
    int* temp = Q->data[front];
    front = (front + 1) % MAX;
    return temp;
}

/* BFS */
void bfs(QueueType* QT, HeadTail *HT, bool* visit) {
    while (front != rear) {
        Node* temp = (Node*)malloc(sizeof(Node));
        int* QueueData = QueuePop(QT);
        visit[QueueData[0]] = 1;

        for (temp = HT[QueueData[0]].head; temp != NULL; temp = temp->next) {
            if (visit[temp->number] == 0) {
                QueuePush(QT, temp->number, temp->length + QueueData[1]);
            }
        }
        if (max < QueueData[1]) {
            max = QueueData[1];
            max_index = QueueData[0];
        }
        free(temp);
    }
}

int main() {
    scanf("%d", &V);

    /* struct 생성 */
    HeadTail* HT = (HeadTail*)malloc(sizeof(HeadTail) * V);
    QueueType* QT = (QueueType*)malloc(sizeof(QueueType));
    bool* visited = (bool*)malloc(sizeof(bool) * V);

    /* HeadTail = NULL로 Init */
    for (int i = 0; i < V; i++) {
        nodeInit(&HT[i]);
    }

    /* 입력 for문 */
    for (int i = 0; i < V; i++) { 
        int startNum, endNum, len;
        scanf("%d", &startNum);
        while(1) {
            scanf("%d", &endNum);
            if (endNum == -1) break;
            scanf("%d", &len);
            connectNode(&HT[startNum - 1], endNum - 1, len); //연결리스트로 노드 연결
        }
    }
    for (int i = 0; i < V; i++) visited[i] = 0;
    QueuePush(QT, 0, 0);
    bfs(QT, HT, visited);
    front = 0, rear = 0;
    
    for (int i = 0; i < V; i++) visited[i] = 0;
    QueuePush(QT, max_index, 0);
    bfs(QT, HT, visited);
    printf("%d", max);

    free(HT);
    free(QT);
    return 0;
}
