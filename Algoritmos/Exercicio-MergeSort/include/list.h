#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct List List;

struct Node{
    int value;
    struct Node* next;
};
struct List{
    struct Node* head;
};

Node* InstantiateNode(int);
void PrintNode(Node);

List* InstantiateList(void);
void PushTail(List*, Node*); //Adiciona elemento no final da lista
void PrintList(List);
void DivideList(Node*, Node**, Node**);
Node* Merge(Node*, Node*);
Node* MergeSort(Node*, int*);
void DestroyList(Node**);