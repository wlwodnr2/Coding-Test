//가장 작은 것을 앞으로 
#include <stdio.h>

int main(void) {
    int i, j, min, index, temp;
    int array[10] = { 1,10,5,8,7,6,4,3,2,9 };
    for (i = 0; i < 10; i++) {
        min = 999;
        for (j = i; j < 10; j++) {
            if (min > array[j]){
                min = array[j];
                index = j;

                }
        }
        temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }
    for (i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
//-> 55번의 비교 연산이 필요하다. [N * (N+1)] / 2
// 대략 선택 정렬은 연산이 O(N*N) N^2 만큼 필요하다 ~
