#include <stdio.h>
#include <math.h>

int verificaQuantidadeCasasBinario(int valor);

int progressaoAritmetica(float n, float al, float r){
    if(n == 0) return al;
    return progressaoAritmetica(n - 1, al + r, r);
}

int main (){
    /*
    float n, al, r;
    printf("Digite o número de termos da progressão aritmética:");
    scanf("%f",&n);
    printf("\nDigite o primeiro termo da progressão:");
    scanf("%f", &al);
    printf("\nDigite a razão da progressão:");
    scanf("%f", &r);
    

   al = progressaoAritmetica(n-1, al, r);

   printf("%f", al);
   */

  int valor1, valor2, quantidadeCasasBinarioValor1 = 0, quantidadeCasasBinarioValor2 = 0;
  int numerobinario1, numerobinario2;

  printf("Digite o primeiro valor numerico: ");
  scanf("%d",&valor1);
  printf("\nDigite o primeiro valor numerico: ");
  scanf("%d",&valor2);

  quantidadeCasasBinarioValor1 = verificaQuantidadeCasasBinario(valor1);
  

}

int verificaQuantidadeCasasBinario(int valor){
    if(valor == 1) return 1;
    return 1 + verificaQuantidadeCasasBinario(valor/2);
}


10*10*10 * 10 * 10 
100000
/*

5
101

1 2 4 8 16 32 64

100000

32/2 - 16
16/2 - 8
8/2 - 4
4/2 - 2
2/2 - 1

numero de divisoes + 1

51/2
25/2
12/2
6/2
3/2

6 

110011


63/2
31/2
15/2
7/2
3/2

64/2
32/2
16/2
8/2
4/2
2/2
1000000

*/
