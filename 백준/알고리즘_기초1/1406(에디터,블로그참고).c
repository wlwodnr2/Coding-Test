#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct LinkedList {
//	struct LinkedList* next;
//	struct LinkedList* before;
//	char word;
//}LinkedList;
//
//int main(void) {
//	int L;
//	char data, command, Pword;
//
//	LinkedList* head = (LinkedList*)malloc(sizeof(LinkedList));
//	head->word = NULL;
//	head->before = head->next = NULL;
//	LinkedList* cur = head;
//
//	
//	while ((data = getchar()) != '\n') {
//		LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
//		newNode->word = data;
//		newNode->before = cur;
//		newNode->next = NULL;
//		cur->next = newNode;
//		cur = newNode;
//	}
//	scanf("%d", &L);
//
//	for (int i = 0; i < L; i++) {
//		scanf(" %c", &command);
//		switch (command) {
//			case 'P':
//				scanf(" %c", &Pword);
//				LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
//				newNode->word = Pword;
//				newNode->next = NULL;
//				newNode->before = cur;
//				if (cur->next != NULL) {
//					newNode->next = cur->next;
//					cur->next->before = newNode;
//				}
//				cur->next = newNode;
//				cur = newNode; 
//				break;
//			case 'L':
//				if (cur->before != NULL) cur = cur->before; //맨 앞이 아니라면 
//				break;
//			case 'D':
//				if (cur->next != NULL) cur = cur->next; //맨 끝이 아니라면 
//				break;
//			case 'B':
//				if (cur->before == NULL) continue; //맨 앞이면 삭제 못 함 
//				LinkedList* delNode = (LinkedList*)malloc(sizeof(LinkedList));
//				delNode = cur; 
//				cur = delNode->before;
//				if (delNode->next != NULL) {
//					cur->next = delNode->next;
//					delNode->next->before = cur;
//					delNode->before = NULL;
//				}
//				else {
//					cur->next = NULL;
//				}
//				free(delNode);
//				break;
//		}
//  	}
//	head = head->next;
//	while (head) {
//		printf("%c", head->word);
//		head = head->next;
//	}
//}
#include <stdio.h>
#define R_MAX 300000

char L[600000 + 10];
char R[R_MAX + 10];

int main() {
	int left = 0, right = R_MAX, N = 0, op = 0;
	char add;
	scanf("%s", L);
	while (L[left++]); left--;
	scanf("%d", &N);
	while (N--) {
		scanf("\n%c", &op);
		if (op == 'P') {
			scanf(" %c", &add);
			L[left++] = add;
		}
		else if (op == 'L' && left != 0) {
			R[right--] = L[--left];
			L[left] = '\0';
		}
		else if (op == 'B' && left != 0) {
			L[--left] = '\0';
		}
		else if (op == 'D' && right != R_MAX) {
			L[left++] = R[++right];
			R[right] = '\0';
		}
		printf("%s %s\n", L, &R[right+1]);
	}
	printf("%s%s", L, &R[right + 1]);
}
