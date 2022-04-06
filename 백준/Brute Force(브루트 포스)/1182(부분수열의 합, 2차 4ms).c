#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, S, arr[21], count = 0;

void dfs(int number, int sum) {
    sum += arr[number]; //우선 해당 숫자를 더한다

    if (number == N) return;
    if (sum == S) count++;

    dfs(number + 1, sum);               //해당 숫자를 더할 경우
    dfs(number + 1, sum - arr[number]); //해당 숫자를 더하지 않을 경우
}

int main() {
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    dfs(0, 0);
    printf("%d", count);
    return 0;
}
