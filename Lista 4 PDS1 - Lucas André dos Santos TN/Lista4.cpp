#include <iostream>
using namespace std;

//Questão 1-a
int fat(int n){
    if(n == 0)return 1;
    return (n * (fat(n-1)));
}

//Questão 1-b
int mdc(int a, int b, int p){
    if(a<=1 && b<=1) return 1;
    if(a%p == 0 && b%p == 0)return p * mdc(a/p, b/p,2);
    else if(a%p == 0)return 1*mdc(a/p, b,2);
    else if(b%p == 0)return 1*mdc(a, b/p,2);
    return 1*mdc(a,b,p+1);
}

//Questão 1-c
int mdc3(int a, int b, int c, int p){
    if(a<=1 && b<=1 && c <=1) return 1;
    if(a%p == 0 && b%p == 0 && c%p == 0) return p * mdc3(a/p, b/p, c/p, 2);
    else if(a%p == 0 && b%p == 0) return 1*mdc3(a/p, b/p,c,2);
    else if(a%p == 0 && c%p == 0) return 1*mdc3(a/p, b,c/p,2);
    else if(b%p == 0 && c%p == 0) return 1*mdc3(a, b/p,c/p,2);
    else if(a%p == 0)return 1*mdc3(a/p, b,c,2);
    else if(b%p == 0)return 1*mdc3(a, b/p,c,2);
    else if(c%p == 0)return 1*mdc3(a, b,c/p,2);
    return 1*mdc(a,b,p+1);
}

//Questão 1-d
int fib(int n){
    if(n < 2) return n;
    return (fib(n-1) + fib(n-2));
}

//Questão 1-e
bool primo(int x, int n){
    if (x <= 1)return false;
    if( n == 1) return true;
    if(x % n == 0) return false;
    return primo(x,n-1);
}

//Questão 1-f
int decrescente(int x){
    if(x <=2 ) return 1;
    cout << x-1 << endl;
    return decrescente(x - 1);
}

//Questão 1-g
int res(int a, int b){
    if(a == ((a/b)*b)) return 0;
    return 1 + res(a-1,b);
}

//Questão 1-h
int form(int n, int i){
    if(i>=n)return 0;
    return (i*i) + form(n, i+1);
}

//Questão 1-i
int mmc (int a, int b, int p){
    if(a==1 && b==1) return 1;
    if(a%p == 0 && b%p == 0)return p * mmc(a/p, b/p,2);
    else if(a%p == 0)return p *mmc(a/p, b,2);
    else if(b%p == 0)return p*mmc(a, b/p,2);
    return 1*mmc(a,b,p+1);
}

//Questão 1-j
int dividir(int a, int b, int n){
    if(n*b == a) return n;
    if(n*b > a) return n-1;
    return dividir(a,b,n+1);
}

//Questão 1-l
float raiz(float x, float chute){
    if(((chute * chute) < (x + 0.001)) && ((chute * chute) > (x - 0.001))) return chute;

    if((chute * chute) > x) return (raiz(x,chute*0.5));
    if((chute * chute) < x) return (raiz(x,chute*1.5));
    return 1;
}

//Questão 1-m
int dig(int n){
    if(n < 10) return n;
    return n%10 + dig(n/10);
}

//Questão 1-n
int exp(int k, int n){
    if(n<=0) return 1;
    return k * exp(k,n-1);
}

//Questão 1-o
int crescente( int x, int n){
    if(n > x-1) return x;
    cout << n << endl;
    return crescente(x, n + 1);   
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
    cout << "O máximo divisor comum entre " << valor1 << " e " << valor2 << " é " << mdc(valor1, valor2, 2) << endl; //Questão 2-b
    cout << "O máximo divisor comum entre " << valor1 << "," << valor2 << " e " << valor3 << " é " << mdc3(valor1, valor2, valor3, 2) << endl; //Questão 2-c
    cout << "O " << valor1 << "° da sequencia de fibonacci é " << fib(valor1) << endl; //Questão 2-d
    cout << "O número " << valor1 << " é primo: " << primo(valor1,valor1/2) << endl; //Questão 2-e
    cout << "Os números inteiros menores que " << valor1 <<" em ordem decrescente são :" << endl << endl << decrescente(valor1) << endl << endl; //Questão 2-f
    cout << "O resto da divisão entre " << valor1 << " e " << valor2 << " é " << res(valor1, valor2) << endl; //Questão 2-g
    cout << "Os valores do somatório de i*i, com i variando de 1 até " << valor1 << " é " << form(valor1,1) << endl; //Questão 2-h
    cout << "O menor múltiplo comum de " << valor1 << " e " << valor2 << " é " << mmc(valor1,valor2,2) << endl; //Questão 2-i
    cout << "o resultado da divisão inteira de " << valor1 << " por " << valor2 << " é " << dividir(valor1, valor2, 1) << endl; //Questão 2-j
    cout << "A raiz do número " << valor1 << " é " << raiz((float)valor1,((float)valor1/2)) << endl; //Questão 2-l
    cout << "A soma dos dígitos do numero " << valor3 << " é " << dig(valor3) << endl; //Questão 2-m
    cout << "O número " << valor1 << " elevado a " << valor2 << " é " << exp(valor1,valor2) << endl; //Questão 2-n
    cout << "Os números inteiros menores que " << valor1 <<" em ordem crescente são :"  << endl << endl << crescente(valor1,1) << endl << endl; //Questão 2-o

}
