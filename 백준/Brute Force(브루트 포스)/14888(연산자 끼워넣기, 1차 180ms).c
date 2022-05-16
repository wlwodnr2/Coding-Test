#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int PMMD[4]; //Plus -> 0 Minus -> 1 Multi -> 2 Division -> 3
int N, position = 0;
int max = -1000000001 , min = 1000000001;

int calculate(int num1, int num2, int sum, int symbol, int back) {
    switch (symbol) {
    case 0:
        if (back == 0) sum = num1 + num2;
        else sum = sum - num2;
        break;
    case 1:
        if (back == 0) sum = num1 - num2;
        else sum = sum + num2;
        break;
    case 2:
        if (back == 0) sum = num1 * num2;
        else sum = sum / num2;
        break;
    case 3:
        if (back == 0) sum = num1 / num2;
        else sum = sum * num2;
        break;
    }
    return sum;
}

void BFS(int *number, int* visit, int count, int sum) {
    if (count == N - 1) {
        max = max > sum ? max : sum;
        min = min > sum ? sum : min;
        return;
    }
    for (int i = 0; i < N - 1; i++) {
        if (visit[i] != -1) {
            int symbol = visit[i];
            visit[i] = -1;

            if (count == 0) sum = calculate(number[count], number[count+1], sum, symbol, 0);
            else sum = calculate(sum, number[count + 1], sum, symbol, 0);

            BFS(number, visit, count+1, sum);

            sum = calculate(sum, number[count + 1], sum, symbol, 1);

            visit[i] = symbol;
        }
    }
}

int main(void) {

    scanf("%d", &N);

    int* number = (int*)malloc(sizeof(int) * N);
    int* visit = (int*)malloc(sizeof(int) * (N - 1));
    
    for (int i = 0; i < N; i++) scanf("%d", &number[i]);

    for (int i = 0; i < 4; i++) {
        scanf("%d", &PMMD[i]);

        for (int j = 0; j < PMMD[i]; j++) {
            visit[position++] = i;
        }
    }

    BFS(number, visit, 0, 0);
    printf("%d\n", max);
    printf("%d", min);
    return 0;
}
