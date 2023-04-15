#include "quick-sort.h"

void swap(int* array, int index_x, int index_y){ // Troca as keys dos índices do array
    int aux = array[index_x];
    array[index_x] = array[index_y];
    array[index_y] = aux;
}
int MedianOfThree(int a, int b, int c){
    int median;
    if(a <= b && b <= c || c <= b && b <= a)
        median = b;
    else if(b <= c && c <= a || a <= c && c <= b)
        median = c;
    else if(c <= a && a <=b || b <= a && a <= c)
        median = a;
    return median;
}
int OptimizedPartition(int* array, int begin, int end){
     int i, j, pivot_key = MedianOfThree(array[begin], array[(end+begin)/2],array[end]);
    i = begin - 1;
    for(j=begin; j<end; j++){
        if(array[j] < pivot_key)
            swap(array, ++i, j); // Agrupa no subarranjo [0:i] os elementos menores que o pivo
    }
    swap(array, ++i, j); // Troca array[i] com o índice do pivo
    return i; // Retorna o índice novo do pivô
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


int* DefaultQuickSort(int* array, int begin, int end){
    int *array_max_min = malloc(2* sizeof *array_max_min); // {max_depth, min_depth}
    int *array_left; // {max_depth, min_depth} da parte esquerda
    int *array_right; // {max_depth, min_depth} da parte direita

    /*
    max serve para tirar o max() entre a direita e a esquerda (left_max, right_max)
    Desse jeito o final da recursão retorna a maior profundidade
    min serve para tirar o min() entre a direita e a esquerda (left_max, right_max)
    Desse jeito o final da recursão retorna a menor profundidade Minimum Depth
    */
    array_max_min[0] = array_max_min[1] = 0; // Inicia as recursões de max e mim com zero

    if(begin < end){
    int pivot_index = Partition(array, begin, end); // Ordena o array em que [begin:i-1] é menor que array[i] e array[i+1:end] é maior que array[i]
    
    array_left = DefaultQuickSort(array, begin, pivot_index - 1);
    array_right = DefaultQuickSort(array, pivot_index + 1, end);
    array_max_min[0] = array_left[0] > array_right[0] ? array_left[0] + 1 : array_right[0] + 1;
    array_max_min[1] = array_left[1] < array_right[1] ? array_left[1] + 1 : array_right[1] + 1;
    free(array_left);
    free(array_right);
    return array_max_min;

    }
    else
        return array_max_min;
}