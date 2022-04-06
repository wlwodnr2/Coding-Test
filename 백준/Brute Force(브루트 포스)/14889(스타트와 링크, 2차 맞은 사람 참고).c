#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int abs(int x) {
    return x >= 0 ? x : -x;
}

int N, S[20][20], start_team[20], link_team[20],start_count = 0, link_count = 0, min = 1000000000;

void balanceChoice(int number, int start, int link) {
    if (number == N) {
        int Ssum = 0, Lsum = 0;
        for (int i = 0; i < start_count; i++) {
            for (int j = i + 1; j < start_count; j++) {
                Ssum += S[start_team[i]][start_team[j]] + S[start_team[j]][start_team[i]];
            }
        }
        for (int i = 0; i < link_count; i++) {
            for (int j = i + 1; j < link_count; j++) {
                Lsum += S[link_team[i]][link_team[j]] + S[link_team[j]][link_team[i]];
            }
        }
        min = abs(Ssum - Lsum) > min ? min : abs(Ssum - Lsum);
    }

    if (start > 0) {
        start_team[start_count++] = number;
        balanceChoice(number + 1, start - 1, link);
        start_count--;
    }
    if (link > 0) {
        link_team[link_count++] = number;
        balanceChoice(number + 1, start, link - 1);
        link_count--;
    }
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &S[i][j]);
        }
    }

    for (int i = 2; i <= N/2; i++) balanceChoice(0, i, N-i);

    printf("%d\n", min);
    return 0;
}
