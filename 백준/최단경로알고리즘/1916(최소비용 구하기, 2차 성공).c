#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
#define INF 987654321
/*
N개의 도시(정점), M개의 버스(간선), 다익스트라 알고리즘
weight : 간선들 값 
*/
int N, M;
int start, end;
int* dist;
int** weight;

typedef struct City {
    int node;
    int cost;
}City;

/* Priority Queue */
// Queue 위치 변경 
void nodeChange(City* a, City* b)
{
    City temp = *a;
    *a = *b;
    *b = temp;
}

// 우선순위 Queue 구조체
typedef struct PriorityQueue {
    City heap[MAX];
    int count;
}PriorityQueue;

// Queue Push
void push(PriorityQueue* pq, int num, int cost) {
    if (pq->count >= MAX) return;
    pq->heap[pq->count].node = num;  //노드 번호
    pq->heap[pq->count].cost = cost; //비용

    int now = pq->count;        //now = 맨 끝 노드
    int parent = (pq->count - 1) / 2; // 맨 끝 노드의 부모노드 

    //위로 올라가는 heap 형
    while (now > 0 && pq->heap[now].cost < pq->heap[parent].cost) //now(자식) > 0(최고 부모노드) , 자식의 비용이 부모 비용보다 작을 때 , 최소힙으로 만들기
    {
        nodeChange(&pq->heap[now], &pq->heap[parent]);
        now = parent;
        parent = (parent - 1) / 2;
    }
    pq->count++;
}

City pop(PriorityQueue* pq) {
    if (pq->count <= 0) return; //없으면 
    City res = pq->heap[0];   //res = 최고 부모노드 (제일 작을거니깐...?)

    pq->count--;                        //하나 빼니깐 빼기
    pq->heap[0] = pq->heap[pq->count];  //맨 앞에 맨 끝 넣기
    int now = 0; int leftChild = 1; int rightChild = 2;

    while (leftChild < pq->count) {
        int target = now;
        //target(부모노드)가 자식 노드보다 크면 교환
        if (pq->heap[now].cost > pq->heap[leftChild].cost && leftChild < pq->count) target = leftChild;
        if (pq->heap[now].cost > pq->heap[rightChild].cost && rightChild < pq->count) target = rightChild;

        if (now == target) break; //now(부모노드)가 가장 작다는거니깐
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
void dijkstra(PriorityQueue* PQ, int *dist) {
    while (PQ->count != 0) {
        City temp = pop(PQ);    //City 구조체 pop
        int node = temp.node; int cost = temp.cost;         //cost가 dist[node] 와 같다

        if (dist[node] < cost && dist[node] != 0) continue; //0이 아니고, cost보다 작으면 이미 지나친 

        for (int i = 0; i < N; i++) {                       //i가 다음 노드를 알려주는 역할 
            //자기 자신이 아니고, INF가 아니라면 -> 연결되어 있는 노드다.
            if (dist[i] > cost + weight[node][i]) {
                dist[i] = cost + weight[node][i];
                push(PQ, i, dist[i]);
            }
        }
    }
}

/* Main */
int main(void) {
    scanf("%d", &N); //도시
    scanf("%d", &M); //버스
 
    // 간선 값
    weight = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) weight[i] = (int*)malloc(sizeof(int) * N);
    // 최단거리 배열
    int* dist = (int*)malloc(sizeof(int) * N);
    // PQ 구조체 하나 선언
    PriorityQueue* PQ = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    PQ->count = 0;

    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        for (int j = 0; j < N; j++) {
            weight[i][j] = INF;
            if (i == j) weight[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(weight[a - 1][b - 1] > c) weight[a - 1][b - 1] = c;
    }
    scanf("%d %d", &start, &end);

    push(PQ, start - 1, 0); //Queue에 추가, 시작점과 cost = 0
    dijkstra(PQ, dist);
    printf("%d", dist[end - 1]);
    free(dist);
    free(weight[0]);
    free(weight);
    return;
}
