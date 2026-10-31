#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

float calcularMedia(float numero1, float numero2, float numero3);
float calcularMediaPonderada(float numero1, float numero2, float numero3);
float calcularPerimetro(float raio);
float calcularAreaCirculo(float raio);
float calcularAreaTriangulo(float base, float altura);
float calcularAreaCaixa(float a, float b, float c);
float calcularVolumeCaixa(float a, float b, float c);
float calcularAreaCilindro(float raio, float altura);
float calcularVolumeCilindro(float raio, float altura);
float calcularHiportenusa(float cateto1, float cateto2);
float calcularRaizPositiva(float numero1, float numero2, float numero3);

int main(){
	
	float a,b,c,r,h;
	
	cout << "Digite o primeiro número para calcular a média normal e a ponderada:";
	cin >> a;
	cout <<  "Digite o segundo número para calcular a média normal e a ponderada:";
	cin >> b;
	cout << "Digite o terceiro número para calcular a média normal e a ponderada:";
	cin >> c;
	
	//Exercicio 2-a
	cout << endl << "A média entre " << a << "," << b << " e " << c << " é:" << calcularMedia(a,b,c) << endl << setprecision(3);
	
	//Exercicio 2-b
	cout << "A média ponderada entre " << a << "," << b << " e " << c << " é:" << calcularMediaPonderada(a,b,c) << endl << setprecision(3);
	
	cout << endl << "Digite o valor do raio de um círculo:";
	cin >> r;
	
	//Exercicio 2-c
	cout << endl << "O perímetro de um circulo de raio " << r << " é:" << calcularPerimetro(r) << endl << setprecision(3);
	
	//Exercicio 2-d
	cout << "A área de um circulo de raio " << r << " é:" << calcularAreaCirculo(r) << endl << setprecision(3);
	
	cout << endl << "Digite o valor da base de um triangulo:";
	cin >> b;
	cout << "Digite o valor da altura de um triangulo:";
	cin >> c;
	
	//Exercicio 2-e
	cout << endl << "A área de um triângulo de base " << b << " e altura " << c << " é:" << calcularAreaTriangulo(b,c) << endl << setprecision(3);
	
	cout << endl << "Digite a primeira dimensão de uma caixa:";
	cin >> a;
	cout <<  "Digite a segunda dimensão de uma caixa:";
	cin >> b;
	cout << "Digite a terceira dimensão de uma caixa:";
	cin >> c;
	
	//Exercicio 2-f
	cout << endl << "A área da caixa de dimensões " << a << "," << b << " e " << c << " é:" << calcularAreaCaixa(a,b,c) << endl << setprecision(3);
	
	//Exercicio 2-g
	cout << "O volume da caixa de dimensões " << a << "," << b << " e " << c << " é:" << calcularVolumeCaixa(a,b,c) << endl << setprecision(3);
	
	cout << endl << "Digite o raio de um cilindro:";
	cin >> r;
	cout << "Digite a altura de um cilindro:";
	cin >> h;
	
	//Exercicio 2-h
	cout << endl << "A área do cilindro de raio " << r << " e altura " << h << " é:" << calcularAreaCilindro(r,h) << endl << setprecision(3);
	
	//Exercicio 2-i
	cout << "O volume do cilindro de raio " << r << " e altura " << h << " é:" << calcularVolumeCilindro(r,h) << endl << setprecision(3);
	
	cout << endl << "Digite o cateto 1 do triangulo:";
	cin >> b;
	cout << "Digite o cateto 2 do triangulo:";
	cin >> c;
	
	//Exercicio 2-j
	cout << endl << "A hiportenusa de um triângulo retângulo com lados " << b << " e " << c << " é:" << calcularHiportenusa(b,c) << endl << setprecision(3);
	
	cout << endl << "Digite o primeiro valor da equação de segundo grau:";
	cin >> a;
	cout <<  "Digite o segundo valor da equação de segundo grau:";
	cin >> b;
	cout << "Digite o terceiro valor da equação de segundo grau: ";
	cin >> c;
	
	//Exercicio 2-k
	cout << endl << "A raiz positiva da equação do segundo grau definida por " << a << "x2 + " << b << "x + " << c << " é:" << calcularRaizPositiva(a,b,c) << endl << setprecision(3);
	
	return 0;
}

//Exercicio 1-a
float calcularMedia(float numero1, float numero2, float numero3){
	return ((numero1 + numero2 + numero3)/3);
}

//Exercicio 1-b
float calcularMediaPonderada(float numero1, float numero2, float numero3){
	return (((numero1 * 3)  + (numero2 * 4) + (numero3 * 5))/(3+4+5));
}

//Exercicio 1-c
float calcularPerimetro(float raio){
	return (2.0 * M_PI * raio);
}

//Exercicio 1-d
float calcularAreaCirculo(float raio){
	return (M_PI * (pow(raio,2)));
}

//Exercicio 1-e
float calcularAreaTriangulo(float base, float altura){
	return ((base*altura)/2.0);
}

//Exercicio 1-f
float calcularAreaCaixa(float a, float b, float c){
	return (2.0 * ((a * b) + (a * c) + (b * c)));
}

//Exercicio 1-g
float calcularVolumeCaixa(float a, float b, float c){
	return (a * b * c);
}

//Exercicio 1-h
float calcularAreaCilindro(float raio, float altura){
	return ((2.0 * (M_PI * pow(raio,2)) + 2.0 * (M_PI * raio * altura)));
}

//Exercicio 1-i
float calcularVolumeCilindro(float raio, float altura){
	return (M_PI * pow(raio,2) * altura);
}

//Exercicio 1-j
float calcularHiportenusa(float cateto1, float cateto2){
	return (sqrt(pow(cateto1,2) + pow(cateto2,2)));
}

//Exercicio 1-k
float calcularRaizPositiva(float numero1, float numero2, float numero3){
	return ((-numero2+sqrt((pow(numero2,2) - 4 * numero1 * numero3)))/(2*numero1));
}





