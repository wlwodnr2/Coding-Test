#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	int N, number, queue[10001], front=0, back=1;
	char command[6];
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%s", &command[0]);
        int size = back - front - 1;
        if (!strcmp(command, "push")) {
            scanf(" %d", &number);
            queue[back-1] = number;
            back++;
        }
        else if (!strcmp(command, "pop")) {
            if (size == 0) {
                printf("-1\n");
                continue;
            }
            printf("%d\n", queue[front]);
            front++;
        }
        else if (!strcmp(command, "size")) {
            printf("%d\n", size);
        }
        else if (!strcmp(command, "empty")) {
            if (size == 0) printf("1\n");
            else printf("0\n");
        }
        else if (!strcmp(command, "front")) {
            if (size == 0) printf("-1\n");
            else printf("%d\n", queue[front]);
        }
        else if (!strcmp(command, "back")) {
            if (size == 0) printf("-1\n");
            else printf("%d\n", queue[back-2]);
        }
	}
}
