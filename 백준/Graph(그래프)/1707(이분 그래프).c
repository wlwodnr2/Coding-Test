#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 20001
#define RED 1
#define BLUE 2
//1 : Red, 2 : Blue
int visit[MAX] = { 0, }, K, V, E, possible = 1;

typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct LinkedList {
    struct Node* adj_list[MAX];
}LinkedList;

void graphInit(LinkedList* LL) {
    for (int i = 1; i <= V; i++) {
        LL->adj_list[i] = NULL;
    }
}

void graphInsert(LinkedList*LL, int a, int b) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = b;
    temp->next = LL->adj_list[a];
    LL->adj_list[a] = temp;
}

void DFS(LinkedList *LL, int start) {
    if (!visit[start]) {
        visit[start] = RED; //RED
    }
    
    for (Node *temp = LL->adj_list[start]; temp != NULL; temp = temp->next) {
        if (!visit[temp->data]) {
            if (visit[start] == RED) { //RED 라면
                visit[temp->data] = BLUE;
            }
            else if (visit[start] == BLUE) { //BLUE 라면
                visit[temp->data] = RED;
            }
            DFS(LL, temp->data);
        }
    }
}

bool isBipartiteGraph(LinkedList* LL) {
    for (int i = 1; i <= V; i++) {
        for (Node *temp = LL->adj_list[i]; temp!=NULL; temp = temp->next) {
            if (visit[i] == visit[temp->data]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    LinkedList L;
    scanf("%d",&K);

    for (int i = 0; i < K; i++) {
        scanf("%d %d", &V, &E);
        graphInit(&L); //그래프 초기화
        for (int j = 0; j < E; j++) {
            int num1, num2;
            scanf("%d %d", &num1, &num2);
            graphInsert(&L, num1, num2);
            graphInsert(&L, num2, num1);
        }
        for (int i = 1; i <= V; i++) {
            if(!visit[i]) DFS(&L, i);
        }
        possible = isBipartiteGraph(&L);
        for (int i = 1; i <= V; i++) visit[i] = 0;
        if (possible) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
