#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counting-sort.h"

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