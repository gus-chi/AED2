#include <stdio.h>
#include <stdlib.h>
#include "quick-sort.h"

void PrintArray(int*, int);
int main(void){
    int *array, *array_copy, n, i, value, diference_recursions;
    scanf("%d", &n);
    array = malloc(n * sizeof *array);
    array_copy = malloc(n * sizeof *array_copy);

    for(i=0; i < n; i++){
        scanf("%d", &value);
        array_copy[i] = array[i] = value; 
        }
    PrintArray(array, n);
    printf("\n");
    diference_recursions = DefaultQuickSort(array, 0, n-1);
    PrintArray(array, n);
    printf("\n%d", diference_recursions);

    return 0;
}
void PrintArray(int* array, int size){
    int i;
    for(i=0; i<size; i++)
        printf("%d ", array[i]);
}