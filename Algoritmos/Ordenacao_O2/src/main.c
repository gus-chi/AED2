#include <stdio.h>
#include <stdlib.h>

int *InstantiateArray(int);
void InitArray(int*, int); // Inicializa o array com inteiros
void PrintArray(int*, int); // Função de teste para ver se o Bubble Sort estava ordenando o array certinho
void BubbleSort(int*, int); // Ordena o array
int CompareArrays(int*, int*, int); /*
Possui 2 arrays como parâmetro onde o primeiro tem que ser maior que o segundo, 
caso encontre um elemento do primeiro que seja menor que o segundo retorna -1
caso contrário retorna 1
*/ 

int main(void){
    int n;
    int *microorganism_array, *shot_power;
    scanf("%d", &n);
    microorganism_array = InstantiateArray(n); // Array Quantidade de Microorganismos
    InitArray(microorganism_array, n);
    shot_power = InstantiateArray(n); // Array Potencia da Dose
    InitArray(shot_power, n);
    BubbleSort(microorganism_array, n);
    BubbleSort(shot_power, n);
    int resultado = CompareArrays(shot_power, microorganism_array, n);
    if(resultado == 1)
        printf("sim");
    else
        printf("nao");
    free(microorganism_array);
    free(shot_power);
    return 0;
}

int *InstantiateArray(int n){
    int *array = malloc(n*sizeof *array);
    return array;
}
void InitArray(int *array, int n){
    int cont = 0;
    for(cont=0; cont < n; cont++)
        scanf("%d", &array[cont]);
}
void PrintArray(int *array, int n){
    int cont=0;
    for(;cont<n; cont++)
        printf("%d ", array[cont]);
    printf("\n");
}
void BubbleSort(int *array, int n){
    // Loop para diminuir o final
    int i;
    for(i=0; i < n; n--){
        int aux; // Variável auxiliar para o swap
        int j;
        for(j=1; j< n; j++){
            if(array[j-1] > array[j]){
                aux=array[j];
                array[j] = array[j-1]; // Troca a posição com o numero considerado maior
                array[j-1] = aux;
            }
        }

    }
}
int CompareArrays(int* bigger, int* smaller, int n){
    int cont = 0;
    for(;cont < n; cont++)
        if(bigger[cont] <= smaller[cont])
            return -1;
    return 1;
}