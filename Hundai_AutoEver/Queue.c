#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data; //데이터
	struct Node* next; //다음 가르키는 노드
}Node;

typedef struct Queue {
	Node* front; //앞 
	Node* rear; //뒤
	int count; //Queue 데이터 개수
}Queue;

void initQueue(Queue* queue) {
	queue->front = queue->rear = NULL;
	queue->count = 0;
}

int IsEmpty(Queue* queue) {
	return queue->count == 0; //queue->count == 0이면 1반환, 아니면 0반환
}
void addQueue(Queue* queue, int data) { //Node 추가
	Node* newNode = (Node*)malloc(sizeof(Node)); // newNode 생성
	newNode->data = data;
	newNode->next = NULL;

	if (IsEmpty(queue)){ //비어있으면
		queue->front = newNode;
	}
	else { //비어있지 않으면
		queue->rear->next = newNode;
	}
	queue->rear = newNode;
	queue->count++;
}

int delQueue(Queue* queue) { //Node 삭제
	int data;
	Node* ptr;
	if (IsEmpty(queue)){ //비어있으면 지울게 없지
		printf("Empty\n");
		return 0;
	}

	ptr = queue->front;    //맨 앞의 노드 ptr 설정 
	data = ptr->data;    // return 할 데이터  
	queue->front = ptr->next;    //맨 앞은 ptr의 다음 노드로 설정
	free(ptr);    // ptr 해제 
	queue->count--;    //큐의 노드 개수를 1 감소

	return data;
}

int main(void)
{
	int i;
	Queue queue;

	initQueue(&queue);//큐 초기화

	for (i = 1; i <= 10; i++)
	{
		addQueue(&queue, i);
	}
	while (!IsEmpty(&queue))    // 큐가 빌 때까지 
	{
		printf("%d ", delQueue(&queue));    //큐에서 꺼내온 값 출력
	}
	printf("\n");
	return 0;
}
