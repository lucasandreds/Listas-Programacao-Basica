
#include <stdio.h>
#include <math.h>

float mediaValores(float *valores, int n){ // Exercicio 2
    float soma = 0;
    for (int i = 0; i < n; i++){
        soma += valores[i];
    }
    return (soma / n);
}

float varianciaValores(float *valores, int n){ // Exercicio 3
    float media = mediaValores(valores, n);
    float soma = 0;
    for (int i = 0; i < n; i++){
        soma += pow((valores[i] - media), 2);
    }
    return (soma / n);
}

float maiorValor(float *valores, int n){ // Exercicio 4
    float maior = valores[0];
    for (int i = 1; i < n; i++){
        if (valores[i] > maior){
            maior = valores[i];
        }
    }
    return maior;
}

float menorValor(float *valores, int n){ // Exercicio 5
    float menor = valores[0];
    for (int i = 1; i < n; i++){
        if (valores[i] < menor){
            menor = valores[i];
        }
    }
    return menor;
}

float produtoEscalar(float *valoresV, float *valoresU, int n){ // Exercicio 6
    float produto = 0;
    for(int i = 0; i < n; i++){
        produto += valoresV[i] * valoresU[i];
    }

    return produto;

}

int main()
{
    float v[1000];
    float u[1000];

    int i = 0;
    FILE *arquivoLeitura = fopen("numeros.txt", "r + t");
    if (arquivoLeitura != NULL){
        fscanf(arquivoLeitura, "%f", &v[i]);
        while (!feof(arquivoLeitura)){
            i++;
            fscanf(arquivoLeitura, "%f", &v[i]); // Exercicio 1
        }
        i++;
        fclose(arquivoLeitura);
    } else printf("Erro ao tentar abrir o arquivo de leitura\n");

    printf("Media:%.2f\n", mediaValores(v, i));         // Exercicio 2
    printf("Variancia:%.2f\n", varianciaValores(v, i)); // Exercicio 3
    printf("Maior valor:%.2f\n", maiorValor(v, i));     // Exercicio 4
    printf("Menor valor:%.2f\n", menorValor(v, i));     // Exercicio 5

    for(int j = 0; j < i; j++){
        u[j] = v[j]/2; //Definindo o segundo vetor para o calculo do produto vetorial
    }

    printf("Produto escalar dos vetores: %.2f\n", produtoEscalar(v,u,i));     // Exercicio 6

    return 0;
}