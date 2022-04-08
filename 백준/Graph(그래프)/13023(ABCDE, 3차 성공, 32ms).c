//동적 할당의 중요성. 메모리 차이가 엄청나다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, M, possible = 0;

typedef struct friend{
    int y;
    struct friend* next;
}friend;

typedef struct relationship{
    struct friend* arr[2000];
}relationship;

relationship rts;

void insert(int a, int b)
{
    friend* temp = (friend*)malloc(sizeof(friend));
    temp->y = b;
    temp->next = rts.arr[a];
    rts.arr[a] = temp;
}

void ABCDE(int visited[], int start, int number) {
    if (number == 4) {
        printf("1");
        exit(0);
    }
    visited[start] = 1;
    for (friend *temp = rts.arr[start]; temp != NULL; temp = temp->next)
    {
        if (!visited[temp->y])
        {
            visited[temp->y] = 1;
            ABCDE(visited, temp->y, number + 1);
            visited[temp->y] = 0;
        }
    }
    visited[start] = 0;
    return;
}

int main() {
    int check[2000] = { 0, };
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) rts.arr[i] = NULL;

    for (int i = 0; i < M; i++) {
        int f1, f2;
        scanf("%d %d", &f1, &f2);
        insert(f1, f2);
        insert(f2, f1);

    }
    for (int i = 0; i < N; i++) {
        ABCDE(check, i, 0);
    }
    
    printf("0");

    return 0;
}
