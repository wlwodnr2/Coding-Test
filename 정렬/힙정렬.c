//훨씬 간단 버전

#include <stdio.h>

void heap(int *data, int num) {
    for (int i = 1; i < num; i++) {
        int son = i;
        do {
            int parent = (son - 1) / 2;
            if (data[parent] < data[son]) {
                int temp = data[parent];
                data[parent] = data[son];
                data[son] = temp;
            }
            son = parent;
        } while (son != 0);
    }
}

int main(void) {
    int N = 9, arr[] = {1, 11, 13 , 5, 7, 8, 2, 3, 15};

    heap(arr, N);
    for (int i = N - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heap(arr, i);
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
