#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, S, arr[21], check[21] = { 0, }, count = 0;

void backTracking(int size, int number, int start, int sum) {
    if (number == size) {
        if (sum == S) count++;
        return;
    }
    for (int i = start; i < N; i++) {
        if (!check[i]) {
            check[i] = 1;
            sum += arr[i];
            backTracking(size, number + 1, i, sum);
            sum -= arr[i];
            check[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    for (int i = 1; i <= N; i++) backTracking(i, 0, 0, 0);
    printf("%d", count);
    return 0;
}
