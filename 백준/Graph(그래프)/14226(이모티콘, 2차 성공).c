#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_QUEUE 4500
#define MAX_INPUT 1500

int S, front, rear;
bool visit[MAX_QUEUE][MAX_QUEUE] = {0, }; //[Screen][Clipboard]

typedef struct _Node {
	int Screen;
	int ClipBoard;
	int Count;
} Node;

typedef struct Queue {
	Node queue[MAX_QUEUE];
}Queue;

void QueueInit(Queue *Q) {
	front = 0;
	rear = 0;
	return;
}
void EnQueue(Queue *Q, int screen, int clip, int cnt) {
	if (front == rear) {
		Q->queue[front].Screen = screen;
		Q->queue[front].ClipBoard = clip;
		Q->queue[front].Count = cnt;
		rear = (rear + 1) % MAX_QUEUE;
		return;
	}
	Q->queue[rear].Screen = screen;
	Q->queue[rear].ClipBoard = clip;
	Q->queue[rear].Count = cnt;
	rear = (rear + 1) % MAX_QUEUE;
	return;
}
Node DeQueue(Queue *Q) {
	Node temp = Q->queue[front];
	front = (front + 1) % MAX_QUEUE;
	return temp;
}
void bfs(Queue* Q) {
	while (front != rear) {
		Node temp = DeQueue(Q);
		if (temp.Screen == S) {
			printf("%d", temp.Count);
			exit(0);
		}
		//1번 조건
		if (!visit[temp.Screen][temp.Screen]) {
			EnQueue(Q, temp.Screen, temp.Screen, temp.Count + 1); //Screen에 있는 이모티콘 Clipboard에 복사
			visit[temp.Screen][temp.Screen] = 1;
		}
		//2번 조건
		if ((temp.ClipBoard != 0) && (temp.Screen + temp.ClipBoard < MAX_INPUT) && !visit[temp.Screen + temp.ClipBoard][temp.ClipBoard]){
			EnQueue(Q, temp.Screen + temp.ClipBoard, temp.ClipBoard, temp.Count + 1);
			visit[temp.Screen + temp.ClipBoard][temp.ClipBoard] = 1;
		}
		//3번 조건
		if ((temp.Screen > 1) && !visit[temp.Screen - 1][temp.ClipBoard]) {
			EnQueue(Q, temp.Screen - 1, temp.ClipBoard, temp.Count + 1);
			visit[temp.Screen - 1][temp.ClipBoard] = 1;
		}
	}
}

int main() {
	scanf("%d", &S);
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	QueueInit(Q);
	EnQueue(Q, 1, 0, 0);
	visit[1][0] = 1;
	bfs(Q);
	free(Q);
	return 0;
}
