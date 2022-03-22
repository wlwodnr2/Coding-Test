#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	int N, X, fqueue[10000] = {0,}, bqueue[10000] = {0,}, front = 0, back = 0, bfront = 10000, bback = 10000;
	char command[11];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", &command);
		int size = (back - front) + (bback - bfront);
		if (!strcmp(command, "push_front")) {
			scanf(" %d", &X);
			if (fqueue[0] != 0) { //fqueue[0]이 0이 아니라면
				bqueue[--bfront] = X;
			}
			else if(front == 0) {
				fqueue[front] = X;
				back++;
			}
			else {
				fqueue[--front] = X;
			}
		}
		else if (!strcmp(command, "push_back")) {
			scanf(" %d", &X);
			if (bback==10000) {
				fqueue[back++] = X;
			}
			else {
				bqueue[bback++] = X;
			}
		}
		else if (!strcmp(command, "pop_front")) {
			if (size == 0) { //사이즈 = 0
				printf("-1\n");
			}
			else if (bfront != 10000) {
				printf("%d\n", bqueue[bfront]);
				bqueue[bfront++] = 0;
			}
			else {
				printf("%d\n", fqueue[front]);
				fqueue[front++] = 0;
			}
		}
		else if (!strcmp(command, "pop_back")) {
			if (size == 0) { //사이즈 = 0
				printf("-1\n");
			}
			else if (back!=0) {
				printf("%d\n", fqueue[--back]);
				fqueue[back] = 0;
			}
			else {
				printf("%d\n", bqueue[--bback]);
				bqueue[bback] = 0;
			}
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
			else if (bfront != 10000) printf("%d\n", bqueue[bfront]);
			else printf("%d\n", fqueue[front]);
		}
		else if (!strcmp(command, "back")) {
			if (size == 0) printf("-1\n");
			else if (bback != 10000) printf("%d\n", bqueue[bback-1]);
			else printf("%d\n", fqueue[back-1]);
		}
	}

	return 0;
}
