#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana/100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais <<
    std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo:
  bool resultado = true;
  std::regex regularSplit("\\s+");
  std::regex_token_iterator<std::string::const_iterator> split(str.begin(), str.end(),regularSplit, -1);;
  std::regex regularExpr("\\d+");
  std::sregex_token_iterator end;
  while(split != end){
    std::string numero = *split;
    if(numero.compare("")){
      if(resultado){
        resultado = std::regex_match(numero, regularExpr);
      }
    }
    split++;
  }

  return resultado;
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  int soma = 0;

  std::regex regularSplit("\\s+");
  std::regex_token_iterator<std::string::const_iterator> split(str.begin(), str.end(),regularSplit, -1);
  std::sregex_token_iterator end;
  while(split != end){
    std::string numero_str = *split;
    if(numero_str.compare("")){
      std::stringstream ss; 
      int numero;
      ss << *split;
      ss >> numero;
      soma += numero;
    }
    split++;
  }

  std::cout << soma << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
  std::regex regularExpr("\\s*[A-Za-z0-9]+\\s*\\d+\\s*[A-Za-z0-9]+\\s*\\d+");
  return std::regex_match(str, regularExpr);
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
  std::stringstream ss(str);
  std::string time1, time2;
  int gols1, gols2;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> time1 >> gols1 >> time2 >> gols2;

  if(gols1 > gols2){
    std::cout << "Vencedor: " << time1 <<  std::endl;
  }else if (gols2 > gols1){
    std::cout << "Vencedor: " << time2 <<  std::endl;
  }else{
    std::cout << "Empate" <<  std::endl;
  }
}

void ContadorDePalavras::processaLinha(const std::string &str) {
  int contador = 0;
  std::regex regularSplit("\\s+");
  std::regex_token_iterator<std::string::const_iterator> split(str.begin(), str.end(),regularSplit, -1);
  std::sregex_token_iterator end;
  while(split != end){
    std::string numero = *split;
    if(numero.compare("")){
      contador++;
    }
    split++;
  }
  std::cout << contador << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
  bool resultado = true;
  std::regex regularSplit("\\s+");
  std::regex_token_iterator<std::string::const_iterator> split(str.begin(), str.end(),regularSplit, -1);;
  std::regex regularExpr("[A-Za-z]+");
  std::sregex_token_iterator end;
  while(split != end){
    std::string numero = *split;
    if(numero.compare("")){
      if(resultado){
        resultado = std::regex_match(numero, regularExpr);
      }
    }
    split++;
  }

  return resultado;
}

void InversorDeFrases::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  std::vector<std::string> palavras;
  std::regex regularSplit("\\s+");
  std::regex_token_iterator<std::string::const_iterator> split(str.begin(), str.end(),regularSplit, -1);
  std::sregex_token_iterator end;
  while(split != end){
    std::string numero_str = *split;
    if(numero_str.compare("")){
      std::stringstream ss; 
      ss << *split;
      std::string palavra;
      ss >> palavra;
      palavras.push_back(palavra);
    }
    split++;
  }

  std::string invertido = ""; 
  for(int i = palavras.size() - 1; i>= 0 ; i--){
    std::cout << palavras.at(i) << " ";
  }
  std::cout << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
  std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";
  // TODO: Implemente este metodo
  // Note que você pode usar uma expressao regular como:
  // "\\s*\\d\\d?/\\d\\d?/\\d{4}" para saber se a linha eh valida:
  std::regex regularExpr(dateFormat);
  return std::regex_match(str, regularExpr);
}

void EscritorDeDatas::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  // Lembre-se que as iniciais dos meses sao:
  // "Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out",
  // "Nov", e "Dez".
  std::vector<std::string> meses = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out", "Nov", "Dez"};
  
  std::stringstream ss(str);
  unsigned int dia, mes, ano;
  char barra1,barra2;
  ss >> dia >> barra1 >> mes >> barra2 >> ano;
  std::cout << meses.at(mes-1) << std::endl;
}