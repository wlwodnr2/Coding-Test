#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//position은 현재 위치.

void addFunc(int *arr, int *visited, int num, int *pos) {
    if (!visited[num - 1]) {
        (*pos)++;
        arr[*pos] = num;
        visited[num - 1] = 1;
    }
    return;
}

void removeFunc(int* arr, int* visited, int num, int* pos) {
    if (visited[num - 1]) {
        for (int i = 0; i < *pos+1; i++) {
            if (arr[i] == num) {
                if (*pos == 0) arr[*pos] = 0;
                else {
                    int temp = arr[*pos];
                    arr[*pos] = 0;
                    arr[i] = temp;
                }
                break;
            }
        }
        visited[num - 1] = 0;
        (*pos)--;
    }
    return;
}

int main(){
    int M, S[21], check[21] = { 0, }, gph_Pos = -1, number;
    char command[7];
    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        scanf("%s ", &command);
        if (!strcmp(command, "add")) {
            scanf("%d", &number);
            addFunc(S, check, number, &gph_Pos);
        }
        else if (!strcmp(command, "remove")) {
            scanf("%d", &number);
            removeFunc(S, check, number, &gph_Pos);
        }
        else if (!strcmp(command, "check")) {
            scanf("%d", &number);
            if (check[number - 1]) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        }
        else if (!strcmp(command, "toggle")) {
            scanf("%d", &number);
            if (check[number - 1]) {
                removeFunc(S, check, number, &gph_Pos);
            }
            else {
                addFunc(S, check, number, &gph_Pos);
            }
        }
        else if (!strcmp(command, "all")) {
            for (int i = 0; i < 21; i++) {
                S[i] = i + 1;
                check[i] = 1;
            }
            gph_Pos = 20;
        }
        else if (!strcmp(command, "empty")) {
            for (int i = 0; i < 21; i++) {
                S[i] = 0;  //0으로 초기화
                check[i] = 0;
            }
            gph_Pos = -1;                           
        }
    }
    return 0;
}
