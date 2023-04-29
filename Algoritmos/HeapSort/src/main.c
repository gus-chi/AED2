#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap-sort.h"
// 1. HeapSort Funciona para Inteiros
// 2. HeapSort Para Ordenar String em ordem alfabetica conforme ASCII
// 3. HeapSort Para Ordenar String na ordem da chave
// Dica Funçao para comparações int , string, chave

// 1. HeapSort Para Inteiros

// int n; // fin - ini
//     int n_key;
//     scanf("%d", &n);
//     scanf("%d", &n_key);
//     int *array = malloc(n*sizeof *array);
//     int *array_key = malloc(n_key*sizeof *array_key); 
//     int i;
//     for(i=0; i<n_key; i++)
//         scanf("%d", &array_key[i]);
//     for(i=0; i<n; i++)
//         scanf("%d", &array[i]);
//     BuildMaxHeapPriority(array, n-1, array_key, n_key);
//     for(i=0; i<n; i++)
//         printf("%d ", array[i]);

int main(void){
    int qtt_of_words, key_size;
    int i;
    char ** sequence_of_words = NULL;
    char ** aux_words = NULL;
    char *sequence_key = NULL;
    
    scanf("%d", &qtt_of_words);
    scanf("%d",&key_size);
    sequence_key = malloc(key_size+1 * sizeof sequence_key); // Malloca o tamanho da key mais o \0
    sequence_of_words = malloc(qtt_of_words * sizeof *sequence_of_words); // Malloca um vetor de strings (ponteiro de strings)
    aux_words = malloc(qtt_of_words* sizeof *aux_words);
    
    for(i=0; i< key_size; i++){
        scanf(" %c", &sequence_key[i]);
        //printf("%c", sequence_key[i]);
    }
    char *palavra_invalida = malloc(256 * sizeof *palavra_invalida);
    int cont = 0;
    for(i=0; i<qtt_of_words; i++){
        int j;
        char *new_palavra = malloc(256 * sizeof *new_palavra); // Malloca
        scanf(" %s", new_palavra);
        for(j=0; j< strlen(new_palavra); j++){
            if(StringPriority(sequence_key, new_palavra[j], new_palavra[j], key_size) == -1){
                cont=1;
                strcpy(palavra_invalida, new_palavra);
                break;
            }        
        }
        // Malloca na posição i do vetor de strings o tamanho exato de caracteres da palavra mais 1 para o \0
        sequence_of_words[i] = malloc((strlen(new_palavra) + 1) * sizeof *new_palavra);
        strcpy(sequence_of_words[i], new_palavra);
        free(new_palavra);
    }
    if(cont == 1){
        printf("A palavra %s eh invalida", palavra_invalida);
        return 0;
    }
    
    // for(i=0; i<qtt_of_words; i++)
        // printf("%s", sequence_of_words[i]);
    printf("\n");
    BuildMaxHeapString(sequence_of_words, qtt_of_words -1, sequence_key, key_size);
    // for(i=0; i<qtt_of_words; i++)
    //     printf("%s ", sequence_of_words[i]);
    printf("\n");
    int copia_of_qtt_of_words = qtt_of_words - 1;
    for(i=qtt_of_words-1; i>=0; i--){
        printf("%s ", HeapExtractMax(sequence_of_words, &copia_of_qtt_of_words, sequence_key, key_size));
    }
    // for(i=0; i<qtt_of_words; i++)
        // printf("%s ", aux_words[i]);
    return 0;
}
