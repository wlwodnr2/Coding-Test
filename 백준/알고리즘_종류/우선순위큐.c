#define MAX_SIZE 100

void nodeChange(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

typedef struct PriorityQueue{
	int heap[MAX_SIZE];
	int count;
}PriorityQueue;

void push(PriorityQueue *pq, int data){
	if(pq->count >= MAX_SIZE) return;
	pq->heap[pq->count] = data;

	int now = pq->count;
	int parent = (pq->count - 1)/2;

	while(now > 0 && pq->heap[now] > pq->heap[parent])
	{
			nodeChange(&pq->heap[now], pq->heap[parent]);
			now = parent;
			parent = (parent - 1)/2;
	}
	pq->count++;
}

int pop(PriorityQueue *pq){
	if(pq->count <= 0) return;
	int res = pq->heap[0];
	
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];
	int now = 0; leftChild = 1; rightChild = 2;
	int target = now;
	while(leftChild < pq->count){
		if(pq->heap[target] < pq->heap[leftChild]) target = leftChild;
		if(pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count) target = rightChild;

		if (target == now) break;
    else {
	    nodeChange(&root->heap[now], &root->heap[target]);
	    now = target;

	    leftChild = now * 2 + 1;
	    rightChild = now * 2 + 2;
		}
	}
	return res;
}
