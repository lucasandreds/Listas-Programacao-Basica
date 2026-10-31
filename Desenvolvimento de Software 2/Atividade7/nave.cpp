#include "nave.h"

Nave::Nave(Ponto2D posicao, double forca){
    this->energia = 100;
    this->posicao = posicao;
    this->forca = forca;
}

Nave::Nave(Ponto2D posicao){
    this->energia = 100;
    this->posicao = posicao;
    this->forca = 1;
}

Nave::Nave(){
    this->posicao = Ponto2D();
    this->energia = 100;
    this->forca = 1;
}

void Nave::mover(double dx, double dy){
    posicao.x += dx;
    posicao.y += dy;
}

double Nave::calcular_distancia(Nave nave){
    return posicao.calcular_distancia(nave.posicao);
}

int Nave::determinar_indice_nave_mais_proxima(Nave naves[], int n){
    int indice_mais_proximo = 0;
    double menor_distancia = calcular_distancia(naves[0]);

    for(int indice = 1; indice < n; indice++){
        double distancia = calcular_distancia(naves[indice]);
        
        if(menor_distancia == 0){
            menor_distancia = distancia;
            indice_mais_proximo = indice;
        }

        if(distancia != 0){
            if (distancia < menor_distancia){
                menor_distancia = distancia;
                indice_mais_proximo = indice;
            }
        }
    }

    return indice_mais_proximo;

}

void Nave::atacar(Nave naves[], int n){
    int indice_mais_proxima = determinar_indice_nave_mais_proxima(naves,n);
    double distancia = calcular_distancia(naves[indice_mais_proxima]);
    
    double dano = (forca * 100)/distancia;

    if(dano > 30){
        dano = 30;
    }

    naves[indice_mais_proxima].energia -= dano;

    if(naves[indice_mais_proxima].energia <= 50){
        std::cout << "Energia baixa!" << std::endl;
    }
}

void Nave::imprimir_status(){
    std::cout << posicao.x << " " << posicao.y << " " << energia << std::endl;
}
