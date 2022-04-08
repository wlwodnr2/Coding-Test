#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//DFS는 재귀, BFS는 Queue
int arr[1000][1000], queue[1000],front = 0, rear = 0;

void BFS(int visit[], int size, int start) {
    queue[rear++] = start; //queue에 추가
    visit[start] = 1;

    while (front != rear) {
        for (int i = 0; i < size; i++) {
            if (!visit[i] && arr[start][i]) {
                queue[rear++] = i;
                visit[i] = 1; //방문
            }
        }
        printf("%d ", queue[front++]+1);
        start = queue[front];
    }
}

void DFS(int visit[], int size, int start) {
    visit[start] = 1;
    printf("%d ", start + 1);
    for (int i = 0; i < size; i++) {
        if (!visit[i] && arr[start][i]) {
            DFS(visit, size, i);
        }
    }
    return;
}

int main() {
    int N, M, V, check[1001] = {0,};
    scanf("%d %d %d", &N, &M, &V);

    for (int i = 0; i < M; i++) {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        arr[num1-1][num2-1] = 1;
        arr[num2-1][num1-1] = 1;
    }

    DFS(check, N, V - 1);
    for (int i = 0; i < N; i++) check[i] = 0;
    printf("\n");
    BFS(check, N, V - 1);
}
