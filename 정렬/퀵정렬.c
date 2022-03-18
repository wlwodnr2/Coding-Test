#include <stdio.h>

void quickSort(int* data, int start, int end) {
    if (start >= end) { //원소가 한 개인 경우
        return;
    }
    int key = start; //피버 값은 첫 번째 값
    int i = start + 1; //왼쪽 출발 지점
    int j = end; //오른쪽 출발 지점
    int temp;

    while (i<=j) {//엇갈릴 때 까지
        while (data[i] <= data[key]) {//키 값보다 큰 값을 만날 때 까지
            i++;
        }
        while (data[j] >= data[key] && j>start) {//키 값보다 작은 값을 만날 때 까지
            j--;
        }
        if (i > j) { //현재 엇갈린 상태면
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        }
        else {
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }
    }
    quickSort(data, start, j-1); //재귀함수로 !
    quickSort(data, j + 1, end);
}

int main(void) {
    int number = 10;
    int data[10] = {1,10,5,8,7,6,4,3,2,9 };

    quickSort(data, 0, number - 1);

    for (int i = 0; i < 10; i++) {
        printf("%d ", data[i]);
    }
    return 0;
}
