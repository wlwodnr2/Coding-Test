#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int N, M, paper[4][4], max = 0;

int paperSum(int visited[4][4]) {
    int sum = 0, multi = 1;
    for (int i = 0; i < N; i++) {
        for (int j = M-1; j >= 0; j--) {
            if (!visited[i][j]) {
                sum += paper[i][j] * multi;
                multi *= 10;
            }
            else multi = 1;
        }
        multi = 1;
    }
    multi = 1;
    for (int j = 0; j < M; j++) {
        for (int i = N-1; i >= 0; i--) {
            if (visited[i][j]) {
                sum += paper[i][j] * multi;
                multi *= 10;
            }
            else multi = 1;
        }
        multi = 1;
    }
    max = max > sum ? max : sum;
    return;
}

void ScrapOfPaper(int visited[4][4], int x, int y) {
    if (x == N) {
        paperSum(visited);
        return;
    }
    if (y == M) {
        ScrapOfPaper(visited, x + 1, 0);
        return;
    }
    visited[x][y] = 0; //가로 0
    ScrapOfPaper(visited, x, y + 1);
    visited[x][y] = 1; //세로 1
    ScrapOfPaper(visited, x, y + 1);
    return;
}

int main() {
    int check[4][4] = { 0, };
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &paper[i][j]);
        }
    }
    ScrapOfPaper(check, 0,0);
    printf("%d", max);
    return 0;
}
