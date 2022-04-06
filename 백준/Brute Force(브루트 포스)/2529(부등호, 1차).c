#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
long long max = 0, min = 9999999999;

void findMinMax(char arr[], int visited[], int maxmin[], int size, int number) {
    if (number == size+1) {
        long long sum = 0, multi = 1;
        for (int i = size; i >= 0; i--) {
            sum += multi * maxmin[i];
            multi *= 10;
        }
        max = max > sum ? max : sum;
        min = min > sum ? sum : min;
        return;
    }

    for (int i = 0; i < 10; i++) { //무조건 0부터 9까지 탐색
        if (visited[i] == 0) {
            visited[i] = 1;
            if (number == 0) { //맨 앞은 부등호 상관 없음.
                maxmin[number] = i; 
                findMinMax(arr, visited, maxmin, size, number + 1);
            }
            else {
                if ((arr[number] == '<') && (maxmin[number-1] < i)) {
                    maxmin[number] = i;
                    findMinMax(arr, visited, maxmin, size, number + 1);
                }
                else if ((arr[number] == '>') && (maxmin[number-1] > i)) {
                    maxmin[number] = i;
                    findMinMax(arr, visited, maxmin, size, number + 1);
                }
            }
            visited[i] = 0;
        }
    }
}

int main() {
    int k, maxminarr[11], check[10] = {0,};
    char inequality[10];
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) scanf(" %c", &inequality[i]);

    findMinMax(inequality, check, maxminarr, k, 0);

    if (max < pow(10, k)) {
        printf("0");
    }
    printf("%lld\n", max);
    if (min < pow(10, k)) {
        printf("0");
    }
    printf("%lld", min);
    return 0;
}
