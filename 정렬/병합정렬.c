#include <stdio.h>

int number = 8;
int data[8]; // 정렬 배열은 무조건 전역 변수로 선언 해주어야 한다.

void merge(int a[], int m, int middle, int n) {// 배열 , 시작, 중간, 끝
    int i = m;
    int j = middle + 1;
    int k = m; //i랑 동일 선상에 있다고 보면 됨
    //작은 순서대로 배열에 삽입
    while (i <= middle && j <= n) {
        if (a[i] <= a[j]) {
            data[k] = a[i];
            i++;
        }
        else {
            data[k] = a[j];
            j++;
        }
        k++;
     }
    //남은 데이터도 삽입
    if (i > middle) {
        for (int t = j; t <= n; t++) {
            data[k] = a[t];
            k++;
        }
    }
    else {
        for (int t = i; t <= middle; t++) {
            data[k] = a[t];
            k++;
        }
    }
    //정렬된 배열을 삽입
    for (int t = m; t <= n; t++) {
        a[t] = data[t];
    }
}
void mergeSort(int a[], int m, int n) {
    if (m < n) {
        int middle = (m + n) / 2;
        mergeSort(a, m, middle);
        mergeSort(a, middle + 1, n);
        merge(a, m, middle, n);
    }
}
int main(void) {
    int array[8] = { 7,6,5,8,3,5,9,1 };
    mergeSort(array, 0, number - 1);

    for (int i = 0; i < number; i++) {
        printf("%d ", data[i]);
    }
    return 0;
}
