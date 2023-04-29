#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(int*, int, int); // array e indices que terão seus valores trocados
void SwapString(char**, int, int); // array_de_palavras, indice da string x, indice da string y

int FirstPriority(int*, int, int, int); // array_key, valor1, valor2, tamanho_array_key
int StringPriority(char*, int, int, int); // array_key, char1, char2, tamanho_array_key

void BuildMaxHeap(int*, int); // BuildMaxHeapInteiros 
void MaxHeapfy(int*, int, int); // array, tamanho do array e indice do pai que será verificado no max heapfy

void BuildMaxHeapPriority(int*, int, int*, int); // {array, tamanho_array, array_key, array_key_tamanho};
void MaxHeapfy2(int*, int, int, int*, int); // {array, tamanho_array, indice_pai, array_key, tamanho_array_key}

void BuildMaxHeapString(char**, int, char*, int); // {sequence_of_words, n, array_key, array_key_tamanho}
void MaxHeapfyString(char**, int, int, char*, int); // {array, tamanho_array, indice_pai, array_key, tamanho_array_key}
char* HeapExtractMax(char**, int*, char*, int);