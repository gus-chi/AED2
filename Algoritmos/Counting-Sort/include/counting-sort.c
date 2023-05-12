#include "counting-sort.h"

int FindMax(int *array, int n){
    int i, max;
    for(i=0; i<n;i++)
        max = i == 0 ? array[i] : array[i] > max ? array[i] : max;
    return max;
}
int *InstantiateFreqArray(int k){
    int *new_frew_array = calloc(k+1, sizeof *new_frew_array);
    return new_frew_array;
}
void FillFreqArray(int *array, int n, int *freq_array){
    int i;
    for(i=0; i<n; i++)
        freq_array[array[i]]++;
}
int *InstantiatePositionArray(int *freq_array, int k){
    int *new_position_array = malloc((k+1) * sizeof *new_position_array);
    int i;
    new_position_array[0] = freq_array[0];
    for(i=1; i<k+1; i++)
        new_position_array[i] = new_position_array[i-1] + freq_array[i];
    return new_position_array;
}
int *CountingSort(int* unsorted_array, int n){
    int *sorted_array = malloc(n* sizeof *sorted_array);
    int k = FindMax(unsorted_array, n); // Valor máximo do unsorted array e também o tamanho do freq_array
    int *freq_array = InstantiateFreqArray(k);
    int *pos_array = NULL;
    FillFreqArray(unsorted_array, n, freq_array);
    pos_array = InstantiatePositionArray(freq_array, k);
    free(freq_array);
    int i;
    for(i=n-1; i>=0; i--)
        sorted_array[--pos_array[unsorted_array[i]]] = unsorted_array[i]; 
    free(pos_array);
    return sorted_array;
}
int *InstantiatePositionArrayPriority(int *freq_array, int k, int *key, int n_key){
    int *new_position_array = calloc((k+1), sizeof *new_position_array);
    int i;
    new_position_array[key[0]] = freq_array[key[0]];
    for(i=1; i<k-1; i++)
        new_position_array[key[i]] = new_position_array[key[i-1]] + freq_array[key[i]]; 
    return new_position_array;
}
int *CountingSortPriority(int* unsorted_array, int n, int* key, int n_key){
    int *sorted_array = malloc(n * sizeof *unsorted_array);
    int k = FindMax(unsorted_array, n);
    int *freq_array = InstantiateFreqArray(k);
    int *pos_array = NULL;
    FillFreqArray(unsorted_array, n, freq_array);
    pos_array = InstantiatePositionArrayPriority(freq_array, k, key, n_key);
    free(freq_array);
    int i;
    for(i=n-1; i>=0; i--)
        sorted_array[--pos_array[unsorted_array[i]]] = unsorted_array[i];
    free(pos_array);
    return sorted_array;
}
void FillFreqArrayString(char** string_array, int n, int d, int *freq_array){
    int i;
    for(i=0; i< n; i++){
        int index_right = string_array[i][d] == 32 ? 0 : string_array[i][d] - 96;
        freq_array[index_right]++;
    }
}
int *InstantiatePositionArrayString(int *freq_array, int k, char *key){
    int *new_position_array = calloc((k+1), sizeof *new_position_array);
    int i;
    int index_right = key[0] == 32 ? 0 : key[0] - 96;
    int index_right_previous;
    new_position_array[index_right] = freq_array[index_right];
    for(i=1; i<=k; i++){
        index_right_previous = index_right;
        index_right = key[i] == 32 ? 0 : key[i] - 96;
        new_position_array[index_right] = new_position_array[index_right_previous] + freq_array[index_right];
    }
    return new_position_array;
}
char **CountingSortString(char** unsorted_string_array, int n, int column, char *key, char**sorted_array){
    int k = 26;
    int *freq_array = InstantiateFreqArray(k);
    int *false_pos_array = NULL;
    int *pos_array = NULL;
    FillFreqArrayString(unsorted_string_array, n, column, freq_array);
    //false_pos_array = InstantiatePositionArray(freq_array, k);
    int *new_array = NULL;
    int i;
    //for(i=0; i<=k; i++)
    //    printf("%d ", false_pos_array[i]);
    pos_array = InstantiatePositionArrayString(freq_array, k, key);
    new_array = CountingSort(pos_array, k+1);
    for(i=0; i<=k; i++)
       printf("%d ", new_array[i]);
    for(i=n-1; i>=0; i--){
        int right_index = unsorted_string_array[i][column] == 32 ? 0 : unsorted_string_array[i][column] - 96;
        strcpy(sorted_array[--pos_array[right_index]], unsorted_string_array[i]);
    }
    free(pos_array);
}
char** RadixSort(char** string_array, int n, int d, char *key, char**sorted_array){
    int i, j;
    for(i=d-1; i>= 0; i--){
        CountingSortString(string_array, n, i, key, sorted_array);
        for(j=0; j<n; j++)
            strcpy(string_array[j], sorted_array[j]);
        printf("\n");
    }
}