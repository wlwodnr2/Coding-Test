#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 10001

int front = -1, rear = 0;
int N, A, B, L, max = 0;
int map[MAX][MAX] = {0,};

typedef struct Tree{
    int nodeNumber;
    int length;
}Tree;

void push(Tree* Q, int num, int len) {
    if (front == -1) {
        Q[++front].nodeNumber = num;
        Q[front].length = len;
        rear++;
        return;
    }
    Q[rear].nodeNumber = num;
    Q[rear].length = len;
    rear = (rear + 1) % MAX;
    return;
}

Tree pop(Tree* Q) {
    Tree temp;
    temp.nodeNumber = Q[front].nodeNumber;
    temp.length = Q[front].length;
    front = (front + 1) % MAX;
    return temp;
}

void bfs(Tree* Q, int vist[]) {
    while (front != rear) {
        Tree temp = pop(Q);
        vist[temp.nodeNumber] = 1; //방문처리
        for (int i = 1; i <= N; i++) {
            if (vist[i] == 0 && map[temp.nodeNumber][i] != 0) { //방문 안 하고, 연결되어있는 노드
                push(Q, i, temp.length + map[temp.nodeNumber][i]); //push
            }
        }
        max = max > temp.length ? max : temp.length;
    }
}

int main() {
    Tree Queue[MAX];
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        scanf("%d %d %d", &A, &B, &L);
        map[A][B] = L;
        map[B][A] = L;
    }

    for (int i = 1; i <= N; i++) {
        int visit[MAX] = { 0, };
        push(Queue, i, 0);
        bfs(Queue, visit);
        front = -1; rear = 0;
    }
    printf("%d", max);
    return;
}
