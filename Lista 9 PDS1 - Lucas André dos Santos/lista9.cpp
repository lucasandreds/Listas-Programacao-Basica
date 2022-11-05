#include <stdio.h>
#include <math.h>

float mediaValores(int n, float mat[][100]){ // Exercicio 2
	float soma = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			soma += mat[i][j];
		}
	}
	return (soma / (n*n));
}

void identidade(int n, float A[][100]){ // Exercicio 3
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if(i == j){
				A[i][j] = 1;
			}else{
				A[i][j] = 0;
			}
		}
	}
	
	for( int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			printf("%.0f ",A[i][j]);
		}
		printf("\n");
	}
}

void transposta(int n, float A[][100], float T[][100]){ // Exercicio 4
	for( int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			T[i][j] = A[j][i];
		}
	}
	
	for( int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			printf("%.0f ",T[i][j]);
		}
		printf("\n");
	}
}

bool simetrica(int n, float A[][100]){ // Exercicio 5
	for( int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			if(A[i][j] != A[j][i]){
				return false;
			}
		}
	}
	return true;
}

void soma_matriz(int n, float A[][100], float B[][100], float S[][100]){ // Exercicio 6
	for( int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			S[i][j] = A[i][j] + B[i][j];
		}
	}
	
	for( int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			printf("%.0f ",S[i][j]);
		}
		printf("\n");
	}
	
}

void mult_matriz(int n, float A[][100], float B[][100], float P[][100]){ // Exercicio 7
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			P[i][j] = 0;
			for(int k=0; k<n; k++) P[i][j]+=A[i][j]*B[k][j];
		}
	}
    
    for( int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			printf("%.0f ",P[i][j]);
		}
		printf("\n");
	}
}

int main(){

	int numeroLinhas, numeroColunas;
	float matriz[100][100], mIdentidade[100][100], mTransposta[100][100], soma[100][100], produto[100][100];
	
	FILE *arquivoLeitura = fopen("numerosMatriz.txt", "r + t");
	if (arquivoLeitura != NULL){
		fscanf(arquivoLeitura, "%d",&numeroLinhas);
		fscanf(arquivoLeitura, "%d",&numeroColunas);

		for( int i = 0;i < numeroLinhas; i++){
			for(int j = 0;j < numeroColunas; j++){
				fscanf(arquivoLeitura, "%f", &matriz[i][j]); // Exercicio 1
			}
		}
		fclose(arquivoLeitura);
		
		for( int i = 0;i < numeroLinhas; i++){ //Definindo os valores iniciais da matriz identidade
			for(int j = 0;j < numeroColunas; j++){
				mIdentidade[i][j] = matriz[i][j];
			}
		}

		printf("Media dos valores da matriz: %.2f\n", mediaValores(numeroLinhas,matriz)); // Exercicio 2
		printf("\nMatriz identidade:\n\n"); // Exercicio 3
		identidade(numeroLinhas,mIdentidade);
		printf("\n");
		printf("Matriz transposta:\n\n"); // Exercicio 4
		transposta(numeroLinhas,matriz,mTransposta);
		printf("\n");
		printf("A matriz original é simetrica:%d\n", simetrica(numeroLinhas,matriz)); // Exercicio 5
		printf("\nMatriz soma da transposta com a matriz original:\n\n"); // Exercicio 6
		soma_matriz(numeroLinhas,matriz,mTransposta,soma);
		printf("\n");
		printf("Matriz produto da transposta com a matriz original:\n\n"); // Exercicio 7
		mult_matriz(numeroLinhas,matriz,mTransposta,produto);
		printf("\n");
		
	} else printf("Erro ao tentar abrir o arquivo de leitura:\n");


	return 0;
}
