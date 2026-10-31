#ifndef PDS2_PROVA2_FORMA
#define PDS2_PROVA2_FORMA

#include <string>

class Forma{
private:
    std::string _nome;
    std::string _cor;
public:
    Forma(std::string nome,std::string cor);
    std::string get_cor();
    std::string get_nome();
};

#endif