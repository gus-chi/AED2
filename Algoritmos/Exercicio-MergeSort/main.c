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


int main(void){
    List *list = InstantiateList(); // Instantiatelist
    Node* new_node = NULL;
    int i, n, valor, cont_recursives; // ponteiro que é incrementado a cada vez que ocorre uma recursividade da função MergeSort
    cont_recursives = 0;
    scanf("%d", &n);
    for( i = 0; i < n; i++){
        scanf("%d", &valor);
        new_node = InstantiateNode(valor);
        PushTail(list, new_node);
    }
    //PrintList(*list); 
    list->head = MergeSort(list->head, &cont_recursives);
    PrintList(*list);
    printf("\n%d", cont_recursives);
    DestroyList(&list->head);
    return 0;
}

Node* InstantiateNode(int value){
    Node *new_node = malloc(sizeof *new_node);
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}
void PrintNode(Node node){
    printf("%d ", node.value);
}
void PushTail(List *lista, Node *tail){ // Adiciona Elemento no fim da fila
    Node** aux = &lista->head;
    while(*aux != NULL)
        aux = &(*aux)->next;
    *aux = tail;
}
List* InstantiateList(void){
    List *new_list = malloc(sizeof *new_list);
    new_list->head = NULL;
    return new_list;
}
void PrintList(List list){ // Função para printar lista
    Node* aux = list.head;
    while(aux != NULL){
        PrintNode(*aux);
        aux = aux->next;
    }
}
void DivideList(Node* head, Node** left, Node** right){
    Node* slow = head;
    Node* fast = slow->next;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}
Node* Merge(Node* left, Node* right){
    Node* new_head = NULL;
    Node** sorting_node = NULL;   // Realiza as trocas de apontamento
    Node* tracker_left = left; // Para percorrer a lista da esquerda
    Node* tracker_right = right; // Para percorrer a lista da direita
    if(tracker_left->value <= tracker_right->value){
        new_head = tracker_left;
        tracker_left = tracker_left->next;   
    }
    else{
        new_head = tracker_right;
        tracker_right = tracker_right->next;
    }
    sorting_node = &(new_head->next);
    while(tracker_left != NULL && tracker_right != NULL){
        if(tracker_left->value <= tracker_right->value){
            (*sorting_node) = tracker_left;
            sorting_node = &(tracker_left->next);
            tracker_left = tracker_left->next;
        }
        else{
            (*sorting_node) = tracker_right;
            sorting_node = &(tracker_right->next);
            tracker_right = tracker_right->next;
        }
    }
    if(tracker_left != NULL)
        (*sorting_node) = tracker_left;
    else if(tracker_right !=NULL)
        (*sorting_node)= tracker_right;

    return new_head; // retorna um provável novo endereço de no que a head da lista irá apontar
}
Node* MergeSort(Node* head, int* recursives){
    int left_recursives, right_recursives;
    left_recursives = right_recursives = 0;
    if(head->next == NULL){
        return head;
        }
    Node *left_head, *right_head;
    left_head = right_head = NULL;
    DivideList(head, &left_head, &right_head);
    *recursives += 1;
    left_head = MergeSort(left_head, &left_recursives);
    right_head = MergeSort(right_head, &right_recursives);
    if(left_recursives >= right_recursives)
        (*recursives) += left_recursives;
    else
        (*recursives) += right_recursives;

    head = Merge(left_head, right_head);
    return head;
}
void DestroyList(Node** destroyer){
    Node* aux = (*destroyer)->next;
    while(*destroyer != NULL){
        free(*destroyer);
        *destroyer = aux;
        if(aux)
            aux = aux->next;
    }
}