#include <iostream>
#include <math.h>

using namespace std;

int main(){

float a,b,c;

cout << "Digite o primeiro número real: ";
cin >> a;
cout << "Digite o segundo número real: ";
cin >> b;
cout << "Digite o terceiro número real: ";
cin >> c;
cout << endl ;

cout << " 3 - a: O resultado é: " << ((a+b+c)/3.0) << endl;
cout << " 3 - b: O resultado é: " << (((a*3)+(b*4)+(c*5))/(3+4+5)) << endl;
cout << " 3 - c: O resultado é: " << (2.0 * M_PI * a) << endl;
cout << " 3 - d: O resultado é: " << (M_PI * (pow(a,2))) << endl;
cout << " 3 - e: O resultado é: " << ((b*c)/2.0) << endl;
cout << " 3 - f: O resultado é: " << (sqrt(pow(b,2) + pow(c,2))) << endl;
cout << " 3 - g: O resultado é: Raiz 1 = " << ((-b+sqrt((pow(b,2) - 4 * a * c)))/(2*a)) << "    Raiz 2 = " << ((-b-sqrt((pow(b,2) - 4 * a * c)))/(2*a)) << endl;
}
