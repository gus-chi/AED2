#include "list.h"

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
void MergeSort(Node* head){
    if(head->next == NULL)
        return;
    Node *left_head, *right_head;
    left_head = right_head = NULL;
    DivideList(head, &left_head, &right_head);
    MergeSort(left_head);
    MergeSort(right_head);
    head = Merge(left_head, right_head);
}