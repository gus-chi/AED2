#include <stdio.h>
#include <stdlib.h>

int* InstantiateArray(int);
void PrintArray(int*, int);
void SelectionSort(int*, int);

int main(void){
    int *array, cont, n;
    scanf("%d", &n);
    array = InstantiateArray(n);
    PrintArray(array, n);
    SelectionSort(array, n);
    PrintArray(array, n);
    return 0;
}

int *InstantiateArray(int n){
    int cont, *new_array = malloc(n*sizeof *new_array);
    for(cont=0; cont<n; cont++){
        scanf("%d", &new_array[cont]);
    }
    return new_array;
}
void PrintArray(int* array, int n){
    int cont;
    for(cont=0; cont< n; cont++)
        printf("%d", array[cont]);
    printf("\n");
}
void SelectionSort(int* array, int n){
    int i, j;
    for(i=0; i<n; i++){
        int aux;
        int index_smaller = i;
        for(j=i+1; j<n-1; j++){
            if(array[j] < array[index_smaller])
                index_smaller = array[j];
        }
        aux = array[index_smaller];
        array[index_smaller] = array[i];
        array[i] = aux;


    }
}
