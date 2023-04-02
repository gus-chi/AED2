#include <stdio.h>
#include <stdlib.h>
#include "merge-sort.h"

int* InitArray(int n){
    int cont;
    int *array = malloc(n*sizeof *array);        
    for(cont=0; cont<n; cont++){
        scanf("%d", &array[cont]);
    }
    return array;
}
void PrintArray(int *array, int n){
    int cont = 0;
    for(cont=0; cont < n; cont++)
        printf("%d ", array[cont]);
    printf("\n");
}
int main(void){
    int n;    
    int *array = NULL;
    scanf("%d", &n);
    array =  InitArray(n);
    PrintArray(array, n);
    MergeSort(array, 0, n-1);
    PrintArray(array, n);
    return 0;
}
