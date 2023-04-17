#include <stdio.h>
#include <stdlib.h>
#include "quick-sort.h"

void PrintArray(int*, int);
int main(void){
    int *array, *array_copy,*array_max_min, n, i, value, min_height = 0;
    scanf("%d", &n);
    array = malloc(n * sizeof *array);
    array_copy = malloc(n * sizeof *array_copy);

    for(i=0; i < n; i++){
        scanf("%d", &value);
        array_copy[i] = array[i] = value; 
        }
    array_max_min = DefaultQuickSort(array, 0, n-1); // Retorna a altura/tamanho máxima(o) da recursão
    //PrintArray(array, n);
    //printf("max: %d min: %d\n", array_max_min[0], array_max_min[1]);
    printf("%d", array_max_min[0] - array_max_min[1]);
    printf("\n");
    free(array_max_min);
    free(array);
    array_max_min = OptimizedQuickSort(array_copy, 0, n-1); 
    //PrintArray(array_copy, n);
    //printf("max: %d min: %d\n", array_max_min[0], array_max_min[1]);
    printf("%d", array_max_min[0] - array_max_min[1]);
    free(array_max_min);
    free(array_copy);
    //printf("%d", max_height);
    //PrintArray(array, n);

    return 0;
}
void PrintArray(int* array, int size){
    int i;
    for(i=0; i<size; i++)
        printf("%d ", array[i]);
}