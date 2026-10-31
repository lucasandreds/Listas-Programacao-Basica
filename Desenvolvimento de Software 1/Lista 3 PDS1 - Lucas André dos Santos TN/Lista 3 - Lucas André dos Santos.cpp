#include <iostream>

using namespace std;

int max(int a,int b,int c);
int min(int a,int b,int c);
bool par(int x);
bool dentro(int x,int y,int z);
bool fora(int x,int y,int z);
bool bissexto(int ano);
bool divisivel(int x, int y);

int main(){
    int numero1, numero2, numero3;

    cout << "Digite o primeiro número:";
    cin >> numero1;
    cout << "Digite o segundo número:";
    cin >> numero2;
    cout << "Digite o terceiro número:";
    cin >> numero3;
    bool resultado;

    //Lista 3 - Exercício 1 - (a) - Chamando a função
    cout << "O maior valor entre os 3 números é " << max(numero1,numero2,numero3) << endl;
    //Lista 3 - Exercício 1 - (b) - Chamando a função
    cout << "O menor valor entre os 3 números é " << min(numero1,numero2,numero3) << endl;
    

    cout << endl << "Digite um número inteiro:";
    cin >> numero1;

    //Lista 3 - Exercício 2 - (a) - Chamando a função
    resultado = par(numero1);
    if(resultado == 0)cout << "O valor " << numero1 << " é par: " << "Falso" << endl;
    else cout << "O valor " << numero1 << " é par: " << "Verdadeiro" << endl;

    cout << endl << "Digite um número:";
    cin >> numero1;
    cout << "Digite o menor valor do intervalo:";
    cin >> numero2;
    cout << "Digite o maior valor do intervalo:";
    cin >> numero3;

     //Lista 3 - Exercício 2 - (b) - Chamando a função
    resultado = dentro(numero1,numero2,numero3);
    if(resultado == 0)cout << "O valor "<< numero1 << " está dentro do intervalo " << numero2 << " e " << numero3 << ":" << "Falso" << endl;
    else cout << "O valor "<< numero1 << " está dentro do intervalo " << numero2 << " e " << numero3 << ":" << "Verdadeiro" << endl;
    
    //Lista 3 - Exercício 2 - (c) - Chamando a função
    resultado = fora(numero1,numero2,numero3);
    if(resultado == 0)cout << "O valor "<< numero1 << " está fora do intervalo " << numero2 << " e " << numero3 << ":" << "Falso" << endl;
    else  cout << "O valor "<< numero1 << " está fora do intervalo " << numero2 << " e " << numero3 << ":" << "Verdadeiro" << endl;

    cout << endl << "Digite um ano:";
    cin >> numero1;

    //Lista 3 - Exercício 3 - Chamando a função
    resultado = bissexto(numero1);
    if(resultado == 0)cout << "O ano "<< numero1 <<" é bissexto: " << "Falso" << endl;
    else cout << "O ano "<< numero1 <<" é bissexto: " << "Verdadeiro" << endl;

    cout << endl << "Digite o dividendo:";
    cin >> numero1;
    cout << "Digite o divisor:";
    cin >> numero2;

    //Lista 3 - Exercício 4 - Chamando a função
    resultado = divisivel(numero1,numero2);
    if(resultado == 0)cout << "O valor " << numero1 << " é divisivel por " << numero2 << ":" << "Falso" << endl;
    else cout << "O valor " << numero1 << " é divisivel por " << numero2 << ":" << "Verdadeiro" << endl;
}

//Lista 3 - Exercício 1 - (a)
int max(int a,int b,int c){
    if((a > b) && (a > c))return a;
    else if(b > c)return b;
    return c;
}

//Lista 3 - Exercício 1 - (b)
int min(int a,int b,int c){
    if((a < b) && (a < c))return a;
    else if(b < c)return b;
    return c;
}

//Lista 3 - Exercício 2 - (a)
bool par(int x){
    if((x%2) == 0)return true;
    return false;
}

//Lista 3 - Exercício 2 - (b)
bool dentro(int x,int y,int z){
    if((x >= y) && (x <=z))return true;
    return false;
}

//Lista 3 - Exercício 2 - (c)
bool fora(int x,int y,int z){
    if((x < y) || (x > z))return true;
    return false;
}

//Lista 3 - Exercício 3
bool bissexto(int ano){
    if(((ano%400) == 0) || (((ano%4) == 0) && ((ano%100) != 0))) return true;
    return false;
}

//Lista 3 - Exercício 4
bool divisivel(int x, int y){
    if((x%y) == 0) return true;
    return false;
}