#include "merge-sort.h"

void Merge(int* array, int begin, int end){
    int half = (end+begin)/2;
    int left_size = half - begin + 1;
    int right_size = end - half;
    int *left = malloc(left_size * sizeof *left);
    int *right = malloc(right_size * sizeof *right);
    // colocando os valores do subarray verdadeiro no left
    int index_left, index_right, k=0;
    for(index_left = 0; index_left < left_size; index_left++)
        left[index_left] = array[begin+index_left];
    //
    for(index_right = 0; index_right < right_size; index_right++)
        right[index_right] = array[half+1+index_right];
    index_left = index_right = 0;
    while(index_left < left_size && index_right < right_size){
        if(left[index_left] < right[index_right]){
            array[k] = left[index_left];
            index_left++;
            k++;
        }
        else if(right[index_right] < left[index_left]){
            array[k] = right[index_right];
            index_right++;
            k++;
        }
    }
    while(index_left < left_size){
        array[k] = left[index_left];
        k++, index_left++;
    }
    while(index_right < right_size){
        array[k] = right[index_right];
        k++, index_right++;
    }
}
void MergeSort(int* array, int begin, int end){
    if(begin == end) // Chegou no subarray com 1 elemento
        return;
    int half = (end+begin)/2;
    MergeSort(array, begin, half);
    MergeSort(array, half+1, end);
    Merge(array, begin, end);    
}