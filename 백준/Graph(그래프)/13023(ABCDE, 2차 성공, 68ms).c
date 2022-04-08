#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M, friend[2000][2000] = { 0, }, possible = 0;

void ABCDE(int visited[], int cnt[], int start, int number) {
    if (number == 4) {
        possible = 1;
        return;
    }
    visited[start] = 1;
    for (int i = 0; i < cnt[start]; i++) {
        if (!visited[friend[start][i]]) {
            visited[friend[start][i]] = 1;
            ABCDE(visited, cnt, friend[start][i], number + 1);
            visited[friend[start][i]] = 0;
        }
        if (possible) return;
    }
    visited[start] = 0;
    return;
}

int main() {
    int check[2000] = { 0, }, count[2000] = {0,};
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int f1, f2;
        scanf("%d %d", &f1, &f2);
        friend[f1][count[f1]++] = f2;
        friend[f2][count[f2]++] = f1;
    }
    for (int i = 0; i < N; i++) {
        ABCDE(check, count, i, 0);
        if (possible) break;
    }
    
    printf("%d", possible);

    return 0;
}
