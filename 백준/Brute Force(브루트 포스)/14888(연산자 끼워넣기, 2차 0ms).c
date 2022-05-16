#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, PMMD[4]; //Plus -> 0 Minus -> 1 Multi -> 2 Division -> 3
int* number;
int max = -1000000001 , min = 1000000001;

void BFS(int plus, int minus, int multi, int divi, int count, int sum) {
    if (count == N - 1) {
        max = max > sum ? max : sum;
        min = min > sum ? sum : min;
        return;
    }

    if (plus > 0) BFS(plus - 1, minus, multi, divi, count + 1, sum + number[count + 1]);
    if (minus > 0) BFS(plus, minus - 1, multi, divi, count + 1, sum - number[count + 1]);
    if (multi > 0) BFS(plus, minus, multi - 1, divi, count + 1, sum * number[count + 1]);
    if (divi > 0) BFS(plus, minus, multi, divi - 1, count + 1, sum / number[count + 1]);

}

int main(void) {

    scanf("%d", &N);

    number = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) scanf("%d", &number[i]);
    for (int i = 0; i < 4; i++) scanf("%d", &PMMD[i]);

    BFS(PMMD[0], PMMD[1], PMMD[2], PMMD[3], 0, number[0]);

    printf("%d\n", max);
    printf("%d", min);
    free(number);
    return 0;
}
