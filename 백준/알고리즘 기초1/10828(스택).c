/*
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int stack[10000];
int stack_size = 0;

void push(int push_data) {
    stack[stack_size] = push_data;
    stack_size += 1;
}

int empty() {
    if (stack_size == 0) {
        return 1;
    }
    return 0;
}

int pop() {
    if (empty()) {
        return -1;
    }
    stack_size -= 1;
    return stack[stack_size];
}

int top() {
    if (empty()) {
        return -1;
    }
    return stack[stack_size - 1];
}

int main() {

    int N = 0, push_data = 0;
    char command[5] = { 0, };

    scanf("%d", &N);

    for (int i = 0;i < N;i++) {

        scanf("%s", command);

        if (!strcmp(command, "push")) {
            scanf("%d", &push_data);
            push(push_data);
        }
        else if (!strcmp(command, "pop")) {
            printf("%d\n", pop());
        }
        else if (!strcmp(command, "empty")) {
            printf("%d\n", empty());
        }
        else if (!strcmp(command, "size")) {
            printf("%d\n", stack_size);
        }
        else if (!strcmp(command, "top")) {
            printf("%d\n", top());
        }
    }

    return 0;
}
