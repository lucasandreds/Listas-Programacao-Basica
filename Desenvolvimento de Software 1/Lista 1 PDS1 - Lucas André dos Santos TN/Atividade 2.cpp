#include <iostream>
#include <math.h>

using namespace std;

int main(){

float a,b,c,d;

cout << "Digite o primeiro número real: ";
cin >> a;
cout << "Digite o segundo número real: ";
cin >> b;
cout << "Digite o terceiro número real: ";
cin >> c;
cout << "Digite o quarto número real: ";
cin >> d;
cout << endl ;

cout << " 2 - a: O resultado é: " << (a+b) << endl;
cout << " 2 - b: O resultado é: " << (a/c) << endl;
cout << " 2 - c: O resultado é: " << pow(a,2) << endl;
cout << " 2 - d: O resultado é: " << (b*c) << endl;
cout << " 2 - e: O resultado é: " << (a*b-c)<< endl;
cout << " 2 - f: O resultado é: " <<(a+b*c) << endl;
cout << " 2 - g: O resultado é: " << (a+b)* c << endl;
cout << " 2 - h: O resultado é: " << sin(a) << endl;
cout << " 2 - i: O resultado é: " << sqrt(b)<< endl;
cout << " 2 - j: O resultado é: " << (a+b+c) << endl;
cout << " 2 - k: O resultado é: " << (a*b*c) << endl;
cout << " 2 - l: O resultado é: " << ((a+b+c)/d) << endl;
cout << " 2 - m: O resultado é: " << (a+b)*(a-d) << endl;
cout << " 2 - n: O resultado é: " << (b/c) + (a *d) << endl;
cout << " 2 - o: O resultado é: " << (sin(b) + cos(c)) << endl;
cout << " 2 - p: O resultado é: " << (log(a) - log(c)) << endl;
cout << " 2 - q: O resultado é: " << (log(a) + (log(b) * log(d) - cos(log(c)))) << endl;
cout << " 2 - r: O resultado é: " << ((b + a)/c -(d+a))<< endl;
cout << " 2 - s: O resultado é: " << ((cos(d) + sin(c)) * (cos(b) - sin(a))) << endl;

}
