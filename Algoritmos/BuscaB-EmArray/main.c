#include <stdio.h>
#include <stdlib.h>

int DivideArraySize(int);
int *InitArray(int);
int BinarySearch(int *, int, int, int);

int main(void){
    int n, value, cont_recursion, *array;
    scanf("%d", &n);
    array = InitArray(n);
    scanf("%d", &value);
    int result = BinarySearch(array, value, 0, n-1);
    if(result != -1)
        printf("%d", result);
    else
        printf("%d nao foi encontrado", value);
    
    free(array);
    return 0;
}

int DivideArraySize(int n){ // retorna o tamanho de entrada dividido por 2
    n /= 2;
    return n;
}
int *InitArray(int n){ // retorna um novo array de tamanho n , já com os elementos preenchidos;
    int value, cont = 0, * array;
    array = malloc(n* sizeof *array);
    for(cont=0; cont<n; cont++){
        scanf("%d", &value);
        array[cont] = value;
    }
    return array;
}
int BinarySearch(int *array, int target, int ini, int end){ // return the number of recursions executed to find the value
    static int cont_recursion = 0;
    if(ini > end){
        cont_recursion = -1;
        return cont_recursion;
        }
    
    int meio = DivideArraySize(end-ini) + ini;
    if(target > array[meio]){
        ini = meio+1;
        cont_recursion++;
        BinarySearch(array, target, ini, end);
    }
    else if(target < array[meio]){
        end = meio - 1;
        cont_recursion++;
        BinarySearch(array, target, ini, end);
    }
    return cont_recursion;
}