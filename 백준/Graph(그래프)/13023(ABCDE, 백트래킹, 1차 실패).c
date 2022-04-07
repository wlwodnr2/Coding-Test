//시간 초과. 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M, friend[2000][2000] = { 0, }, possible = 0;

void ABCDE(int visited[], int start, int number) {
    if (number == 4) {
        possible = 1;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && friend[start][i]) { //방문하지 않았고, 시작과 친구인 경우
            visited[i] = 1;
            ABCDE(visited, i, number + 1);
            visited[i] = 0;
       }
    }
    return;
}

int main() {
    int check[2000] = { 0, };
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int f1, f2;
        scanf("%d %d", &f1, &f2);
        friend[f1][f2] = 1;
        friend[f2][f1] = 1;
    }

    for (int i = 0; i < N; i++) {
        check[i] = 1;
        ABCDE(check, i, 0);
        check[i] = 0;
    }

    printf("%d", possible);

    return 0;
}
