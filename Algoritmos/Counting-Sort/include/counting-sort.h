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