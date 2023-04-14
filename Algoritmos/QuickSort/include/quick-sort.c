#include "quick-sort.h"

void swap(int* array, int index_x, int index_y){
    int aux = array[index_x];
    array[index_x] = array[index_y];
    array[index_y] = aux;
}
int Partition(int* array, int begin, int end){
    int i, j, pivot_key = array[end];
    i = begin - 1;
    for(j=begin; j<end; j++){
        if(array[j] < pivot_key)
            swap(array, ++i, j); // Agrupa no subarranjo [0:i] os elementos menores que o pivo
    }
    swap(array, ++i, j); // Troca array[i] com o índice do pivo
    return i; // Retorna o índice novo do pivô
}
int DefaultQuickSort(int* array, int begin, int end, int* min_height){
    int height = 0;
    int left_height = 0;
    int right_height = 0;

    if(begin < end){
    int pivot_index = Partition(array, begin, end); // Ordena o array em que [begin:i-1] é menor que array[i] e array[i+1:end] é maior que array[i]
    
    left_height = DefaultQuickSort(array, begin, pivot_index - 1, min_height); // 
    right_height = DefaultQuickSort(array, pivot_index + 1, end, min_height);
    
    height = left_height > right_height ? left_height : right_height;
    return height + 1;
    }
    else{
        return height;
    }
}