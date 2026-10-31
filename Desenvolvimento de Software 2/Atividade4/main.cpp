#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

// Tipo abastrato de dados que representa uma número complexo. 
class Complexo {
  // Atributos.
  private:
    double real;
    double imag;

  // Métodos.
  public:
    Complexo(double real, double imag){
      this->real = real;
      this->imag = imag;
    } 
    double modulo() {
      double resultado = sqrt((pow(real,2) + pow(imag,2)));
      return resultado;
    }
    Complexo conjugado() {
      Complexo conjugado = Complexo(real,-1 * imag);
      return conjugado;
    }
    Complexo inverso() {
      Complexo inverso = conjugado().dividir(multiplicar(conjugado()));
      return inverso;
    }
    Complexo soma(Complexo y) {
      Complexo soma = Complexo(real + y.real, imag + y.imag);
      return soma;
    }
    Complexo subtrair(Complexo y) {
      Complexo subtracao = Complexo(real - y.real,imag - y.imag);
      return subtracao;
    }
    Complexo multiplicar(Complexo y) {
      double valorReal = ((real * y.real) - (imag * y.imag));
      double valorImag = ((real * y.imag) + (y.real * imag));
      Complexo multiplicacao = Complexo(valorReal, valorImag);
      return multiplicacao;
    }
    Complexo dividir(Complexo y) {
      Complexo quociente = multiplicar(y.conjugado());
      Complexo divisor = y.multiplicar(y.conjugado());
      Complexo divisao = Complexo(quociente.real / divisor.real,quociente.imag / divisor.real );
      return divisao;
    }

    double getReal(){
      return real;
    }

    double getImag(){
      return imag;
    }
};

pair<Complexo, Complexo> raizes(double a, double b, double c) {
  double delta,realPrimeira,imagPrimeira,realSegunda,imagSegunda;
  delta = (pow(b,2) - (4*a*c));

  if(delta < 0){
    realPrimeira = ((-1 * b)/ (2 * a));
    imagPrimeira = (sqrt((-1 * delta))/(2*a));

    realSegunda = ((-1 * b)/ (2 * a));
    imagSegunda = ((-1 * sqrt((-1 * delta)))/(2*a));

  }else{
    realPrimeira = (((-1 * b) + sqrt(delta))/(2*a));
    imagPrimeira = 0;

    realSegunda = (((-1 * b) - sqrt(delta))/(2*a));
    imagSegunda = 0;
  }

  Complexo primeira = Complexo(realPrimeira,imagPrimeira);
  Complexo segunda = Complexo(realSegunda,imagSegunda);

  return make_pair(primeira,segunda);
}

int main () {
  cout << "Digite os coeficientes da equação f(x) = ax^2 + bx + c:" << endl;
  double a, b, c;
  cin >> a >> b >> c;
  auto r = raizes(a, b, c);
  cout << "(" << r.first.getReal() << ", " << r.first.getImag() << ") "
       << "(" << r.second.getReal() << ", " << r.second.getImag() << ")" << endl;
       
  cout << "Modulo: " << r.first.modulo() << endl;
  cout << "(" << r.first.conjugado().getReal() << ", " << r.first.conjugado().getImag() << endl;
  cout << "(" << r.first.inverso().getReal() << ", " << r.first.inverso().getImag() << endl;
  cout << "(" << r.first.soma(r.second).getReal() << ", " << r.first.soma(r.second).getImag() << endl;
  cout << "(" << r.first.subtrair(r.second).getReal() << ", " << r.first.subtrair(r.second).getImag() << endl;
  cout << "(" << r.first.multiplicar(r.second).getReal() << ", " << r.first.multiplicar(r.second).getImag() << endl;
  cout << "(" << r.first.dividir(r.second).getReal() << ", " << r.first.dividir(r.second).getImag() << endl;

  return 0;
}