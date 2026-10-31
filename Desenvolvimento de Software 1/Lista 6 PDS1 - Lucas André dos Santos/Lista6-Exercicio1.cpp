#include <stdio.h>

bool primo(int x){
    if(x > 1){
        for (int i = x - 1; i > 1; i--)
            if (x % i == 0) return false;
        return true;
    } else return false;
}

int main(){
    FILE *arquivo = fopen("primeirosNumerosPrimos.txt","w");
    if(arquivo!=NULL){
        int n;
        int numeroprimos = 0;
        int i = 2;

        printf("Digite um número inteiro:");
        scanf("%d",&n);

        while(numeroprimos < n){
            if(primo(i)){
                numeroprimos++;
                fprintf(arquivo, "%d\n", i);
            }
                i++;
        }
        fclose(arquivo);
    }else{
        printf("Erro ao tentar abrir o arquivo\n");
    }

    return 0;
}