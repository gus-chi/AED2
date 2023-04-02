#include <stdio.h>
#define TAM_ARRAY 5

void InitArray(int *conjunto){
  int cont;
  for(cont=0; cont< TAM_ARRAY; cont++)
    scanf("%d", &conjunto[cont]);
}
void PrintArray(int *conjunto){
  int cont;
  for(cont=0; cont < TAM_ARRAY; cont++)
    printf("%2d ", conjunto[cont]);
  printf("\n");

}
void SelectionSort(int *conjunto){
  int chave;
  int achar_menor;
  int menor;
  int pos_menor;
  for(chave=0; chave< TAM_ARRAY; chave++){ // chave é o intervalo inicial = 0 intervalo final TAM_ARRAY -1 [0:TAM_ARRAY-1]
    for(achar_menor=chave; achar_menor < TAM_ARRAY; achar_menor++){ // Achar menor percorre o intervalo [chave:TAM_ARRAY-1] para achar o menor valor
        if(achar_menor==chave)
          menor=conjunto[chave];
        else
          if(conjunto[achar_menor] < menor){
            menor = conjunto[achar_menor];
            pos_menor = achar_menor;
          }
    }
    conjunto[pos_menor] = conjunto[chave];
    conjunto[chave] = menor;
  }
}
int main(void){
  int conjunto_num[TAM_ARRAY];
  InitArray(conjunto_num);
  PrintArray(conjunto_num);
  SelectionSort(conjunto_num);
  PrintArray(conjunto_num);

  return 0;
}
