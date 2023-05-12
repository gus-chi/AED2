#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Funções Counting Sort Inteiros sem chave
int FindMax(int*, int);
int *InstantiateFreqArray(int);
void FillFreqArray(int*, int, int*);
int *InstantiatePositionArray(int*, int);
int *CountingSort(int*, int); 

// Funções Counting Sort Inteiros com chave

int * InstantiatePositionArrayPriority(int*, int, int*, int);
int *CountingSortPriority(int*, int, int*, int);

void FillFreqArrayString(char**, int, int, int*);
int *InstantiatePositionArrayString(int*, int, char*);
char **CountingSortString(char**, int, int, char*, char**);
char **RadixSort(char**, int,  int, char*, char**);

void ToLower(char*, int);
void CompleteWithSpaces(char*, int);
int main(void){
    // Declarando variáveis e recebendo inputs

    int word_quantity;
    scanf("%d", &word_quantity);
    char *keys = malloc(28 * sizeof *keys);
    keys[0] = ' ';
    char *key = malloc(27 * sizeof *key);
    scanf("%s", key);
    strcat(keys, key);
    free(key); 
    int i, max;
    char **string_array = malloc(word_quantity * sizeof *string_array);
    char **sorted_array = malloc(word_quantity * sizeof *sorted_array);

    for(i=0; i< word_quantity; i++){
         string_array[i] = malloc(21 * sizeof *string_array[i]);
         sorted_array[i] = malloc(21 * sizeof *sorted_array[i]);

         scanf("%s", string_array[i]);
         int string_size = strlen(string_array[i]);      
        // Atribuindo o tamanho da maior palavra para a variável max
        // Inicialmente max inicia com o tamanho da primeira palavra do array de strings(quando i == 0)
        // Caso i != 0 compara max com a iésima palavra

        max = i == 0 ? string_size : string_size > max ? string_size : max;
        // Atribui no array de strings na posicao i a new_palavra recebida no scanf acima e converte as letras
        // Com a função ToLower
        ToLower(string_array[i], string_size);
        printf("%s.\n", string_array[i]);    
        //char *new_palavra = malloc(21 * sizeof *new_palavra); //int new_palavra_size = strlen(new_palavra); //string_array[i] = malloc((new_palavra_size+1) * sizeof *string_array[i]); //strcpy(string_array[i], new_palavra); //free(new_palavra);
    }
    printf("%d\n", max);
    for(i=0; i< word_quantity; i++)
        CompleteWithSpaces(string_array[i], max);
    RadixSort(string_array, word_quantity, max, keys, sorted_array);
    for(i=0; i<word_quantity; i++)
        printf("%s\n", sorted_array[i]);
    free(string_array);
    free(sorted_array);
    return 0;
}
void ToLower(char* string, int n){
    int i;
    for(i=0; i< n; i++){
        if(string[i] >= 64 && string[i] <= 90)
            string[i] += 32;
    }
}
void CompleteWithSpaces(char* string, int max){
    while(strlen(string) < max)
        strcat(string, " ");
}
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
    //int *false_pos_array = NULL;
    int *pos_array = NULL;
    FillFreqArrayString(unsorted_string_array, n, column, freq_array);
    //false_pos_array = InstantiatePositionArray(freq_array, k);
    int i;
    int *new_array;
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
    free(new_array);
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