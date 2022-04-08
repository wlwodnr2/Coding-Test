#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define MAX 1001

int count = 0, N,M;
bool DFS_Arr[MAX][MAX], visit[MAX] = { 0, };

void DFS(int start) {
    visit[start] = 1;
    for (int i = 1; i <= N; i++) {
        if (!visit[i] && DFS_Arr[start][i]) DFS(i);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        DFS_Arr[num1][num2] = 1;
        DFS_Arr[num2][num1] = 1;
    }
    for (int i = 1; i <= N; i++) {
        if (visit[i] == 0) {
            DFS(i);
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
