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
void Swap(int *array, int index_x, int index_y){
    int aux = array[index_x];
    array[index_x] = array[index_y];
    array[index_y] = aux;
}
void SwapString(char** array_strings, int index_x, int index_y){
    int n_x = strlen(array_strings[index_x]);
    int n_y = strlen(array_strings[index_y]);
    char* aux = malloc(n_x * sizeof *aux);
    char* aux2 = malloc(n_y * sizeof *aux2);
    strcpy(aux, array_strings[index_x]);
    strcpy(aux2, array_strings[index_y]);
    array_strings[index_x] = aux2;
    array_strings[index_y] = aux;
}
int FirstPriority(int *array, int x, int y, int n){
    int i;
    for(i=0; i< n; i++){
        if(array[i] == x)
            return x;
        if(array[i] == y)
            return y;
    }
    return -1;
}
int StringPriority(char *key, int x, int y, int n){
     int i;
    for(i=0; i< n; i++){
        if(key[i] == x)
            return x;
        if(key[i] == y)
            return y;
    }
    return -1;

}
void BuildMaxHeap(int* array, int n){
    int decrease_fathers = n/2;
    while(decrease_fathers >= 0){
        printf("pai:%d  filhos:", decrease_fathers);
        MaxHeapfy(array, n, decrease_fathers);
        decrease_fathers--;
    }
}
void MaxHeapfy(int *array, int n ,int father_index){
    int left_son =  1 + father_index*2; // filho esquerda do índice pai
    int right_son = 1 + father_index*2 + 1; // filho direita do índice pai
    int max = father_index; // indice do maior valor do heap, inicialmente é o próprio pai
    if(left_son <=n && array[left_son] > array[max])
        max = left_son;
    if(right_son <= n && array[right_son] > array[max])
        max = right_son;
    if(max <= n && max != father_index){
        Swap(array, max, father_index);
        MaxHeapfy(array, n, max);
        }
}

void BuildMaxHeapPriority(int* array, int n, int *array_key, int n_key){
    int decrease_fathers = n/2;
    while(decrease_fathers >= 0){
        //printf("pai:%d  filhos:", decrease_fathers);
        MaxHeapfy2(array, n, decrease_fathers, array_key, n_key);
        decrease_fathers--;
    }
}


void MaxHeapfy2(int *array, int n ,int father_index, int* array_key, int n_key){
    int left_son =  1 + father_index*2; // filho esquerda do índice pai
    int right_son = 1 + father_index*2 + 1; // filho direita do índice pai
    int max = father_index; // indice do maior valor do heap, inicialmente é o próprio pai
    if(left_son <=n && FirstPriority(array_key, array[left_son], array[max], n_key) != array[max])
        max = left_son;
    if(right_son <= n && FirstPriority(array_key, array[right_son], array[max], n_key) != array[max])
        max = right_son;
    if(max <= n && max != father_index){
        Swap(array, max, father_index);
        MaxHeapfy2(array, n, max, array_key, n_key);
        }
}
void BuildMaxHeapString(char** array_of_strings, int n, char *array_key, int n_key){
    int decrease_fathers = n/2;
    while(decrease_fathers >= 0){
        //printf("pai:%d  filhos:", decrease_fathers);
        MaxHeapfyString(array_of_strings, n, decrease_fathers, array_key, n_key);
        decrease_fathers--;
    }
}

void MaxHeapfyString(char **array_of_strings, int n ,int father_index, char* array_key, int n_key){
    int left_son =  1 + father_index*2; // filho esquerda do índice pai
    int right_son = 1 + father_index*2 + 1; // filho direita do índice pai
    int max = father_index; // indice do maior valor do heap, inicialmente é o próprio pai
    int string_max_size = strlen(array_of_strings[father_index]);
    if(left_son <=n){
        int i;
        int string_left_size = strlen(array_of_strings[left_son]);
        for(i=0; i<string_left_size && i < string_max_size; i++){
            char aux = StringPriority(array_key, array_of_strings[left_son][i], array_of_strings[max][i], n_key);
            if(array_of_strings[left_son][i] != array_of_strings[max][i]){
                if(aux == array_of_strings[left_son][i]){
                    max = left_son;
                    string_max_size = string_left_size;
                    break;
                }
                else if(aux == array_of_strings[max][i]){
                    break;
                }
            }
        }
        if(i == string_left_size)
            max = left_son;
        }
    if(right_son <= n){
        int i;
        int string_right_size = strlen(array_of_strings[right_son]);
        for(i=0; i<string_right_size && i < string_max_size; i++){
            char aux = StringPriority(array_key, array_of_strings[right_son][i], array_of_strings[max][i], n_key);
            if(array_of_strings[right_son][i] != array_of_strings[max][i]){
                if(aux == array_of_strings[right_son][i]){
                    max = right_son;
                    string_max_size = string_right_size;
                    break;
                }
                else if(aux == array_of_strings[max][i]){
                    break;
                }
            }
        }
        if(i == string_right_size)
            max = right_son;

    }
    if(max <= n && max != father_index){
        SwapString(array_of_strings, max, father_index);
        MaxHeapfyString(array_of_strings, n, max, array_key, n_key);
        }
}

char* HeapExtractMax(char** array_of_strings, int* last, char* array_key, int n_key){
    if(*last<0)
        return NULL;
    char* max = malloc(strlen(array_of_strings[0]) * sizeof *max);
    strcpy(max, array_of_strings[0]);
    SwapString(array_of_strings, 0, *last);
    (*last)--;
    MaxHeapfyString(array_of_strings, *last, 0, array_key, n_key);
    return max;
}