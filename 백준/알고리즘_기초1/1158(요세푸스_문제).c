#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct circleList {
	struct circleList* next;
	int number;
}circleList;
int main(void) {
	int N, K, count;
	circleList* cur = (circleList*)malloc(sizeof(circleList));
	circleList* head = (circleList*)malloc(sizeof(circleList));
	head->next = NULL;
	head->number = NULL;
	cur->next = NULL;
	cur->number = NULL;

	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		circleList* newNode = (circleList*)malloc(sizeof(circleList));
		newNode->next = NULL;
		newNode->number = i;

		if (i == 1) {
			head = newNode;
			cur = head;
		}
		else if (i == N) {
			cur->next = newNode;
			newNode->next = head;
		}
		else {
			cur->next = newNode;
			cur = newNode;
		}
	}
	cur = head;
	count = N;
	while (count > 0) {
		circleList* delNode = (circleList*)malloc(sizeof(circleList));
		circleList* predelNode = (circleList*)malloc(sizeof(circleList));
		predelNode = cur;
		for (int i = 0; i < K - 2; i++) {
			predelNode = predelNode->next;
		}
		for (int i = 0; i < K-1; i++) {
			cur = cur->next;
		}
		delNode = cur;
		if (count == N) {
			printf("<%d", cur->number);
		}
		else {
			printf(", %d", cur->number);
		}
		cur = cur->next;
		predelNode->next = cur;
		delNode = NULL;
		free(delNode);
		count--;
	}
	printf(">");
	return 0;
}
