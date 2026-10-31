#include <stdio.h>

int main(){
    float valorLido, a,b,c,d;
    FILE *arquivoLeitura = fopen("numerosReais.txt","r + t");
    if(arquivoLeitura !=NULL){
        FILE *arquivoEscrita = fopen("funcaoValoresUsuario.txt","w + t");
        if(arquivoEscrita !=NULL){

            printf("Digite o primeiro coeficiente da equação:");
            scanf("%f",&a);
            printf("Digite o segundo coeficiente da equação:");
            scanf("%f",&b);
            printf("Digite o terceiro coeficiente da equação:");
            scanf("%f",&c);
            printf("Digite o quarto coeficiente da equação:");
            scanf("%f",&d);

            while(!feof(arquivoLeitura)){
                fscanf(arquivoLeitura,"%f",&valorLido);
                fflush(stdin);
                fprintf(arquivoEscrita,"x = %.2f: %.2fx³ + %.2fx² + %.2fx + %.2f = %.2f \n",valorLido,a,b,c,d,((a * (valorLido * valorLido * valorLido)) + (b * (valorLido * valorLido)) + (c * valorLido) + d));
            }
            fclose(arquivoEscrita);
        }else printf("Erro ao tentar abrir o arquivo de escrita\n");
        fclose(arquivoLeitura);
    }else printf("Erro ao tentar abrir o arquivo de leitura\n");

    return 0;
}