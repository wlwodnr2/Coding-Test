#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedList {
	struct LinkedList* next;
	struct LinkedList* before;
	char word;
}LinkedList;

int main(void) {
	int L, cursor;
	char data, command, Pword;
	//LinkedList* head = NULL;
	//LinkedList* tail = NULL;
	//LinkedList* cur = NULL;
	//LinkedList* newNode = NULL;

	LinkedList* head = (LinkedList*)malloc(sizeof(LinkedList));
	head->word = '!';
	head->before = head->next = NULL;
	LinkedList* cur = head;

	
	while ((data = getchar()) != '\n') {
		LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
		newNode->word = data;
		newNode->before = cur;
		newNode->next = NULL;
		cur->next = newNode;
		cur = newNode;
	}
	scanf("%d", &L);

	for (int i = 0; i < L; i++) {
		scanf(" %c", &command);
		switch (command) {
			case 'P':
				scanf(" %c", &Pword);
				LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
				newNode->word = Pword;
				newNode->next = NULL;
				newNode->before = cur;
				if (cur->next) {
					newNode->next = cur->next;
					cur->next->before = newNode;
				}
				else {
					newNode->next = NULL;
				}
				cur->next = newNode;
				cur = cur->next;
				break;
			case 'L':
				if (cur->before) cur = cur->before;
				break;
			case 'D':
				if (cur->next) cur = cur->next;
				break;
			case 'B':
				if (cur->before == NULL) continue;
				LinkedList* del = (LinkedList*)malloc(sizeof(LinkedList));
				del = cur;
				cur = del->before;
				if (del->next) {
					cur->next = del->next;
					del->next->before = cur;
					del->before = NULL;
				}
				else { cur->next = NULL; }
				free(del);
				break;
		}
  	}
	head = head->next;
	while (head) {
		printf("%c", head->word);
		head = head->next;
	}
}
