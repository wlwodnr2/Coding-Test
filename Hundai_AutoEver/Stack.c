#include "stdio.h"
#include "stdlib.h"
#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

int IsEmpty() {
	if (top < 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int IsFull() {
	if (top >= MAX_STACK_SIZE) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(int value) {
	if (IsFull() == 1) {
		printf("Stack is Full\n");
	}
	else {
		stack[++top] = value;
	}
}

int pop() {
	if (IsEmpty() == 1) {
		printf("Stack is Empty\n");
	}
	else {
		return stack[top--];
	}
}

int main() {

	push(5);
	push(4);
	push(3);
	push(2);
	push(1);

	printf("%d\n",pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	pop();

	return 0;
}
