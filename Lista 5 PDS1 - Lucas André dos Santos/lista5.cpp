#include <iostream>
using namespace std;

// Questão 1-a
long int fat(int n){
    long int fat = 1;
    for (int i = n; i > 0; i--) fat *= i;
    return fat;
}

// Questão 1-b
int mdc(int a, int b){
    int resultado = 1, divisor = 2;
    while ((a != 1) || (b != 1)) {
        if (a % divisor == 0 && b % divisor == 0) {
            a = a / divisor;
            b = b / divisor;
            resultado *= divisor;
            divisor = 2;
        } else if (a % divisor == 0) {
            a = a / divisor;
            divisor = 2;
        } else if (b % divisor == 0) {
            b = b / divisor;
            divisor = 2;
        } else divisor++;
    }

    return resultado;
}
// Questão 1-c
int mdc3(int a, int b, int c, int p){
    int resultado = 1, divisor = 2;
    while ((a != 1) || (b != 1) || (c != 1)){
        if (a % divisor == 0 && b % divisor == 0 && c % divisor == 0){
            a = a / divisor;
            b = b / divisor;
            c = c / divisor;
            resultado *= divisor;
            divisor = 2;
        } else if (a % divisor == 0 && b % divisor == 0) {
            a = a / divisor;
            b = b / divisor;
            divisor = 2;
        } else if (a % divisor == 0 && c % divisor == 0){
            a = a / divisor;
            c = c / divisor;
            divisor = 2;
        } else if (b % divisor == 0 && c % divisor == 0){
            c = c / divisor;
            b = b / divisor;
            divisor = 2;
        } else if (a % divisor == 0){
            a = a / divisor;
            divisor = 2;
        }  else if (b % divisor == 0){
            b = b / divisor;
            divisor = 2;
        } else if (c % divisor == 0){
            c = c / divisor;
            divisor = 2;
        } else divisor++;
    }

    return resultado;
}
// Questão 1-d
int fib(int n){
    int antepenultimo = 1, penultimo = 1, fibonacci = 1;
    for (int i = 2; i < n; i++) {
        fibonacci = antepenultimo + penultimo;
        antepenultimo = penultimo;
        penultimo = fibonacci;
    }
    return fibonacci;
}

//Questão 1-e
bool primo(int x){
    if(x > 1){
        for (int i = x - 1; i > 1; i--)
            if (x % i == 0) return false;
        return true;
    } else return false;
}

// Questão 1-f
void decrescente(int x){
    for (int i = x - 1; i > 0; i--)cout << i << endl;
}

//Questão 1-g
int res(int a, int b){
    int resto = 0;
    for(int i = a; i > (a / b) * b; i--) resto++;
    return resto;
}

// Questão 1-h
int form(int n){
    int resultado = 0;
    for (int i = 1; i <= n; i++)resultado += i*i;
    return resultado;
}

//Questão 1-i
int mmc (int a, int b){
    int resultado = 1, divisor = 2;
    while (a != 1 || b != 1) {
        if (a % divisor == 0 && b % divisor == 0) {
            a = a / divisor;
            b = b / divisor;
            resultado *= divisor;
            divisor = 2;
        } else if (a % divisor == 0) {
            a = a / divisor;
            resultado *= divisor;
            divisor = 2;
        } else if (b % divisor == 0) {
            b = b / divisor;
            resultado *= divisor;
            divisor = 2;
        } else divisor++;
    }
    return resultado;
}

//Questão 1-j
int dividir(int a, int b){
    int divisor = 1;
    while((divisor * b) < a) divisor++;
    if(divisor*b == a) return divisor;
    return divisor-1;
}

//Questão 1-l
float raiz(float x){
    float chute = x/2;
    while(((chute * chute) >= (x + 0.001)) || ((chute * chute) <= (x - 0.001))){
        if((chute * chute) > x) chute *= 0.5;
        if((chute * chute) < x) chute *= 1.5;
    }
    return chute;
}

//Questão 1-m
int dig(int n){
    int resultado = 0;
    while(n > 0){
        resultado += res(n, 10);
        n = dividir(n, 10);
    }
    return resultado;
}

//Questão 1-n
long int exp(int k, int n){
    long int resultado = 1;
    for( int i = 1; i <= n; i++){
        resultado *= k;
    }
    return resultado;
}

//Questão 1-o
void crescente( int x){
    for (int i = 1; i <=x; i++)cout << i << endl;
}


int main(){
    int valor1, valor2, valor3;

    //Pedindo valores para teste
    cout << "Digite o primeiro valor numérico: ";
    cin >> valor1;
    cout << "Digite o segundo valor numérico: ";
    cin >> valor2;
    cout << "Digite o terceiro valor numérico: ";
    cin >> valor3;

    cout << "O valor do fatorial de " << valor1 << " é " << fat(valor1) << endl; //Questão 2-a
    cout << "O máximo divisor comum entre " << valor1 << " e " << valor2 << " é " << mdc(valor1, valor2) << endl; //Questão 2-b
    cout << "O máximo divisor comum entre " << valor1 << "," << valor2 << " e " << valor3 << " é " << mdc3(valor1, valor2, valor3, 2) << endl; //Questão 2-c
    cout << "O " << valor1 << "° da sequencia de fibonacci é " << fib(valor1) << endl; //Questão 2-d
    cout << "O número " << valor1 << " é primo: " << primo(valor1) << endl; //Questão 2-e
    cout << "Os números inteiros menores que " << valor1 <<" em ordem decrescente são :" << endl << endl; decrescente(valor1); //Questão 2-f
    cout << endl << "O resto da divisão entre " << valor1 << " e " << valor2 << " é " << res(valor1, valor2) << endl; //Questão 2-g
    cout << "Os valores do somatório de i*i, com i variando de 1 até " << valor1 << " é " << form(valor1) << endl; //Questão 2-h
    cout << "O menor múltiplo comum de " << valor1 << " e " << valor2 << " é " << mmc(valor1,valor2) << endl; //Questão 2-i
    cout << "o resultado da divisão inteira de " << valor1 << " por " << valor2 << " é " << dividir(valor1, valor2) << endl; //Questão 2-j
    cout << "A raiz do número " << valor1 << " é " << raiz((float)valor1) << endl; //Questão 2-l
    cout << "A soma dos dígitos do numero " << valor3 << " é " << dig(valor3) << endl; //Questão 2-m
    cout << "O número " << valor1 << " elevado a " << valor2 << " é " << exp(valor1,valor2) << endl; //Questão 2-n
    cout << "Os números inteiros menores que " << valor1 <<" em ordem crescente são :"  << endl << endl; crescente(valor1); cout << endl; //Questão 2-o

}

