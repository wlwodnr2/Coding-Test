#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define MAX 51
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1 , 1 };
int N, M, start_x, start_y;
bool visit[MAX][MAX] = { 0, };
char map[MAX][MAX];

void bfs(int x, int y, int number) {
    visit[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if ((nx >= 0) && (ny >= 0) && (nx < N) && (ny < M) && (map[x][y] == map[nx][ny]) && !visit[nx][ny]) bfs(nx, ny, number + 1);
        if (nx == start_x && ny == start_y && number >= 4) {
            printf("Yes");
            exit(0);
        }
    }
    visit[x][y] = 0;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf(" %s", map[i]);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visit[i][j]) {         //방문 안 했으면 bfs 탐색
                start_x = i; start_y = j;
                bfs(i, j, 1);
                visit[i][j] = 1;
            }
        }
    }
    printf("No");
    return 0;
}
