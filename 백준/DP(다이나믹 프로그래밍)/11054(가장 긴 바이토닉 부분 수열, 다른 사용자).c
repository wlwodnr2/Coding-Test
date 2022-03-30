#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int box[1001];
int Lbox[1001];
int Rbox[1001];

int main() {
    int N;
    scanf("%d", &N);
    int i, j, maxnum;
    for (i = 0; i < N; i++) scanf("%d", &box[i]);

    for (i = 0; i < N; i++) {
        maxnum = 1;
        for (j = 0; j < i; j++)
            if (Lbox[j] >= maxnum && box[j] < box[i]) maxnum = Lbox[j] + 1;
        Lbox[i] = maxnum;
    }
    for (i = N - 1; i >= 0; i--) {
        maxnum = 1;
        for (j = N - 1; j > i; j--)
            if (Rbox[j] >= maxnum && box[j] < box[i]) maxnum = Rbox[j] + 1;
        Rbox[i] = maxnum;
    }

    maxnum = 1;
    for (i = 0; i < N; i++) {
        if (Lbox[i] + Rbox[i] - 1 > maxnum) maxnum = Lbox[i] + Rbox[i] - 1;
    }
    printf("%d", maxnum);

    return 0;
}
