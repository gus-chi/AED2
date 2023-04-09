#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void){
    List *list = InstantiateList(); // Instantiatelist
    Node* new_node = NULL;
    int i, n, valor;
    scanf("%d", &n);
    for( i = 0; i < n; i++){
        scanf("%d", &valor);
        new_node = InstantiateNode(valor);
        PushTail(list, new_node);
    }
    PrintList(*list);
    MergeSort(list->head);
    PrintList(*list);
    return 0;
}
