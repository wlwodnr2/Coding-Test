#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N;
int* parent;
int** map;

void dfs(int start) {
    for (int i = 0; i < N; i++) {
        if (parent[i] == -1 && map[start][i] == 1) { //부모가 아직 정해지지 않았고 연결된 경우
            parent[i] = start + 1; //부모 정해주기 
            dfs(i);
        }
    }
}

int main() {
    scanf("%d", &N);
    map = (int**)malloc(sizeof(int*) * N);
    parent = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        map[i] = (int*)malloc(sizeof(int) * N);
    }
    for (int i = 0; i < N; i++) {
        parent[i] = -1;
        for (int j = 0; j < N; j++) {
            map[i][j] = 0;
        }
    }
    for (int i = 0; i < N-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a-1][b-1] = 1;
        map[b-1][a-1] = 1;
    }
    dfs(0);
    for (int i = 1; i < N; i++) printf("%d\n", parent[i]);
    for (int i = 0; i < N; i++) {
        free(map[i]);
    }
    free(map);
    free(parent);
    return 0;
}
