#include "quick-sort.h"

void swap(int* array, int index_x, int index_y){
    int aux = array[index_x];
    array[index_x] = array[index_y];
    array[index_y] = aux;
}
int Partition(int* array, int begin, int end){
    int chave = array[end];
    int j, i = begin -1;
    for(j = begin; j < end; j++){
        if(array[j] <= chave){
            i++;
            swap(array, i, j);
        }   
    }
    i++;
    swap(array, i, end);
    return i;
}
int DefaultQuickSort(int* array, int begin, int end){
    if(begin != end){
        int index_pivo = Partition(array, begin, end);
        DefaultQuickSort(array, begin, index_pivo-1);
        DefaultQuickSort(array, index_pivo+1, end);
    }
    return 0;
}