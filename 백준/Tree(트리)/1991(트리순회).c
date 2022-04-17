#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char element;
    struct Node* left;
    struct Node* right;
}Node;

Node* newNode(char data) {
    Node* newTree = (Node*)malloc(sizeof(Node));
    newTree->element = data;
    newTree->left = NULL;
    newTree->right = NULL;
    return newTree;
}

Node* searchNode(Node* root, char data) {
    if (root != NULL) {                                 //주어진 노드가 비어있지 않을 때.
        if (root->element == data) {                    //주어진 노드의 값과 찾으려는 값이 같은 경우
            return root;                                //해당 노드를 탐색 했으니 반환
        }
        else {                                          //만약 해당 노드의 값이 같지 않다면
            Node* tmp = searchNode(root->left, data);   //왼쪽 노드 탐색
            if (tmp != NULL) return tmp;                //비어있지 않으면 찾았기 때문에 반환

            return searchNode(root->right, data);       //왼쪽에 없으면 오른쪽이니깐 탐색, 트리 구조이기 때문에 무조건 왼쪽 아니면 오른쪽에 존재해야된다. ㅋ
        }
    }
    return NULL;                                        //주어진 노드가 비어있으면 -> 주어진 노드가 생성되어 있지 않으면 
}

void insertNode(Node* root, char parent, char Lchild, char Rchild) {
    root->element = parent;
    if (Lchild != '.') root->left = newNode(Lchild);
    if (Rchild != '.') root->right = newNode(Rchild);
}
/*전위 표기법 : (부모 노드) - (왼쪽 노드) - (오른쪽 노드) 순서. 부모 노드일때 출력하면 됨*/
void print_pre(Node* root){
    if (root != NULL) printf("%c", root->element);      
    if (root->left != NULL) print_pre(root->left);      
    if (root->right != NULL) print_pre(root->right);    
}
/*중위 표기법 : (왼쪽 노드) - (부모 노드) - (오른쪽 노드) 순서. 부모 노드일때 출력하면 됨*/
void print_in(Node* root) {
    if (root->left != NULL) print_in(root->left);       
    if (root != NULL) printf("%c", root->element);      
    if (root->right != NULL) print_in(root->right);     
}
/*후위 표기법 : (왼쪽 노드) - (오른쪽 노드) - (부모 노드) 순서. 부모 노드일때 출력하면 됨*/
void print_post(Node* root) {
    if (root->left != NULL) print_post(root->left);
    if (root->right != NULL) print_post(root->right);
    if (root != NULL) printf("%c", root->element);
}

int main() {
    Node* root = newNode(NULL);                         //꼭대기 가르키는 root Node 
    Node* tmp;                                          //임시 값 받는 Node 
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char P, Lc, Rc;
        scanf(" %c %c %c", &P, &Lc, &Rc);
        tmp = searchNode(root, P);                      //root로 주어진 값의 노드가 존재하는지 탐색
        if (tmp != NULL) insertNode(tmp, P, Lc, Rc);    //노드가 이미 존재하기 때문에 해당 노드를 root로 두고 insertNode
        else insertNode(root, P, Lc, Rc);               //노드가 존재하지 않는 경우, H 노드가 Root 
    }
    print_pre(root);
    printf("\n");
    print_in(root);
    printf("\n");
    print_post(root);
    free(root);
    return 0;
}
