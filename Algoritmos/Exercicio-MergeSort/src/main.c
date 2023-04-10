#include <stdio.h>
#include <stdlib.h>
#include "list.h"



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
