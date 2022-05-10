#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100000
#define INF 987654321
/*
N개의 도시(정점), M개의 버스(간선), 다익스트라 알고리즘
도시 연결 구조체 : 연결된 도시 번호 , 비용 -> 동적 배열로 만들어서 Head, Tail 존재하게
Head, Tail 가르키는 구조체 : HeadTail
*/
int N, M;
int start, end;
int* minCost;
bool* visit;

/* Linked List */
typedef struct City {
    int cityNumber;
    int cityCost;
    struct City* next;
}City;

typedef struct HeadTail {
    City* Head;
    City* Tail;
}HeadTail;

void initHeadTail(HeadTail* H) {
    H->Head = NULL;
    H->Tail = NULL;
}

void connect(HeadTail* H, int num, int cost) {
    City* temp = (City*)malloc(sizeof(City));
    if (H->Head == NULL) {
        H->Head = temp; H->Tail = temp;
        temp->cityNumber = num; temp->cityCost = cost; temp->next = NULL;
    }
    else {
        temp->cityNumber = num; temp->cityCost = cost; temp->next = NULL;
        H->Tail->next = temp;
        H->Tail = temp;
    }
}

/* Priority Queue */
void nodeChange(City* a, City* b)
{
    City temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct PriorityQueue {
    City heap[MAX];
    int count;
}PriorityQueue;

void push(PriorityQueue* pq, int num, int cost) {
    if (pq->count >= MAX) return;
    pq->heap[pq->count].cityNumber = num;
    pq->heap[pq->count].cityCost = cost;

    int now = pq->count;
    int parent = (pq->count - 1) / 2;

    while (now > 0 && pq->heap[now].cityCost > pq->heap[parent].cityCost)
    {
        nodeChange(&pq->heap[now], &pq->heap[parent]);
        now = parent;
        parent = (parent - 1) / 2;
    }
    pq->count++;
}

City* pop(PriorityQueue* pq) {
    if (pq->count <= 0) return;
    City* res = &pq->heap[0];

    pq->count--;
    pq->heap[0] = pq->heap[pq->count];
    int now = 0; int leftChild = 1; int rightChild = 2;
    int target = now;
    while (leftChild < pq->count) {
        if (pq->heap[target].cityCost < pq->heap[leftChild].cityCost) target = leftChild;
        if (pq->heap[target].cityCost < pq->heap[rightChild].cityCost && rightChild < pq->count) target = rightChild;

        if (target == now) break;
        else {
            nodeChange(&pq->heap[now], &pq->heap[target]);
            now = target;

            leftChild = now * 2 + 1;
            rightChild = now * 2 + 2;
        }
    }
    return res;
}

/* Dijkstra */
void dijkstra(HeadTail* H, PriorityQueue *PQ) {
    while (PQ->count != 0) {
        City* temp = pop(PQ);
        visit[temp->cityNumber] = 1;
        int preCost = temp->cityCost;
        for (temp = H[temp->cityNumber].Head; temp != NULL; temp = temp->next) {
            if (visit[temp->cityNumber] == 0 && preCost + temp->cityCost < minCost[temp->cityNumber]) { //방문 안 하고 비용이 적으면 
                push(PQ, temp->cityNumber, preCost + temp->cityCost);
                minCost[temp->cityNumber] = preCost + temp->cityCost;
            }
        }
    }
}

/* Main */
int main(void) {
    scanf("%d", &N); //도시
    scanf("%d", &M); //버스

    PriorityQueue* root = (PriorityQueue *)malloc(sizeof(PriorityQueue)); // Queue
    root->count = 0;     // Queue Count 0 

    //도시 개수만큼 머리 꼬리 가르키는 구조체, 방문 배열 생성
    HeadTail* HT = (HeadTail*)malloc(sizeof(HeadTail) * N);
    bool* visit = (bool*)calloc(N, sizeof(bool)); 
    int* minCost = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        initHeadTail(&HT[i]);
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        connect(&HT[a - 1], b, c);
        connect(&HT[b - 1], a, c);
    }
    scanf("%d %d", &start, &end);

    push(root, start - 1, 0);
    dijkstra(HT, root);

    printf("%d", minCost[end-1]);

    free(HT);
    free(visit);
    return;
}
