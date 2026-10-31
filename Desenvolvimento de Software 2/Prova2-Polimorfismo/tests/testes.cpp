#include "doctest.h"

#include "forma.h"
#include "forma2d.h"
#include "quadrado.h"
#include "triangulo.h"
#include "forma3d.h"
#include "cubo.h"
#include "esfera.h"
#include "circulo.h"

#include <string>
#include <math.h>


TEST_CASE("01 - Testando construção de classes derivadas com seus respectivos atributos") {
    //construtores devem setar o nome das formas. Exemplo, ao criar um quadrado, o campo quadrado
    //deve receber o valor "quadrado"
    
    CHECK_NOTHROW(Triangulo("azul", 10, 12, 5)); //construtor com cor, aresta_1, aresta_2 e aresta_3
    CHECK_NOTHROW(Quadrado("verde", 4)); //construtor com cor e tamanho da aresta
    CHECK_NOTHROW(Cubo("verde", 4)); //construtor com cor e tamanho da aresta
    CHECK_NOTHROW(Esfera("verde", 4)); //construtor com cor e raio
    CHECK_NOTHROW(Circulo("verde", 4)); //construtor com cor e raio

}

TEST_CASE("02 - Acessando métodos das classes base") {
    Triangulo t("azul", 6, 7, 8);
    CHECK((abs(t.get_area()-20.3331625676))<0.0001);
    CHECK(t.get_perimetro() == 21);
    
    Quadrado q("verde", 4);
    CHECK(q.get_area() == 16);
    CHECK(q.get_perimetro() == 16);
    
    Cubo c("roxo", 4);
    CHECK(c.get_volume() == 64);
    
    Esfera e("amarelo", 3);
    CHECK(abs(e.get_volume()-113.097)<0.01);
    
    Circulo cr("rosa", 2);
    CHECK(abs(cr.get_area()-12.5664)<0.001);
    CHECK(abs(cr.get_perimetro()-12.5664)<0.001);
}

TEST_CASE("03 - Instanciando objetos com classe base") {
    Triangulo triangulo("azul", 7, 5, 4);
    Quadrado quadrado("vermelho", 7);
    Esfera esfera("roxo", 3);
    Cubo cubo("rosa", 2);
    Circulo circulo("amarelo", 2);
    
    std::string nome1 = "triangulo";
    std::string nome2 = "quadrado";
    std::string nome3 = "esfera";
    std::string nome4 = "cubo";
    std::string nome5 = "circulo";
    
    Forma *poligono1 = &quadrado;
    Forma *poligono2 = &triangulo;
    Forma *poligono3 = &esfera;
    Forma *poligono4 = &cubo;
    Forma *poligono5 = &circulo;
    
    //checando nomes
    CHECK(nome2.compare(poligono1->get_nome())==0);
    CHECK(nome1.compare(poligono2->get_nome())==0);
    CHECK(nome3.compare(poligono3->get_nome())==0);
    CHECK(nome4.compare(poligono4->get_nome())==0);
    CHECK(nome5.compare(poligono5->get_nome())==0);
    
}

TEST_CASE("04 - Instanciando objetos com classe base e testando manter as cores") {
    Triangulo triangulo("azul", 7, 5, 4);
    Quadrado quadrado("vermelho", 7);
    Esfera esfera("roxo", 3);
    Cubo cubo("rosa", 2);
    Circulo circulo("amarelo", 2);
    
    Forma *poligono1 = &quadrado;
    Forma *poligono2 = &triangulo;
    Forma *poligono3 = &esfera;
    Forma *poligono4 = &cubo;
    Forma *poligono5 = &circulo;
    
    CHECK(poligono1->get_cor().compare("vermelho")==0);
    CHECK(poligono2->get_cor().compare("azul")==0);
    CHECK(poligono3->get_cor().compare("roxo")==0);
    CHECK(poligono4->get_cor().compare("rosa")==0);
    CHECK(poligono5->get_cor().compare("amarelo")==0);
}


TEST_CASE("05 - Acessando métodos das classes filhas") {
    Triangulo triangulo("azul", 7, 5, 4);
    Quadrado quadrado("vermelho", 7);
    Esfera esfera("roxo", 3);
    Cubo cubo("rosa", 2);
    Circulo circulo("amarelo", 2);
    
    Forma2D *poligono1 = &quadrado;
    Forma2D *poligono2 = &triangulo;
    Forma3D *poligono3 = &esfera;
    Forma3D *poligono4 = &cubo;
    Forma2D *poligono5 = &circulo;
    
    //checando nomes
    CHECK(poligono1->get_area()==49);
    CHECK((abs(poligono2->get_area()-9.79796))<0.001);
    CHECK(abs(poligono3->get_volume()-113.097)<0.01);
    CHECK(poligono4->get_volume()==8);
    CHECK(abs(poligono5->get_area()-12.5664)<0.001);
}


TEST_CASE("06 - Acessando métodos das classes base do Triangulo") {
    Triangulo t("azul", 9, 6, 5);
    CHECK((abs(t.get_area()-14.1421))<0.0001);
    CHECK(t.get_perimetro() == 20);

    Triangulo t2("rosa", 11, 8, 9);
    CHECK((abs(t2.get_area()-35.4965))<0.0001);
    CHECK(t2.get_perimetro() == 28);

    Triangulo t3("vermelho", 4, 6, 3);
    CHECK((abs(t3.get_area()-5.3327))<0.0001);
    CHECK(t3.get_perimetro() == 13);
    
}

TEST_CASE("07 - Acessando métodos das classes base do Quadrado") {
    Quadrado q("verde", 10);
    CHECK(q.get_area() == 100);
    CHECK(q.get_perimetro() == 40);

    Quadrado q2("roxo", 7);
    CHECK(q2.get_area() == 49);
    CHECK(q2.get_perimetro() == 28);

    Quadrado q3("preto", 15);
    CHECK(q3.get_area() == 225);
    CHECK(q3.get_perimetro() == 60);

}

TEST_CASE("08 - Acessando métodos das classes base do Cubo") {
    Cubo c("roxo", 10);
    CHECK(c.get_volume() == 1000);

    Cubo c2("laranja", 8);
    CHECK(c2.get_volume() == 512);

    Cubo c3("cinza", 5);
    CHECK(c3.get_volume() == 125);
}

TEST_CASE("09 - Acessando métodos das classes base da Esfera") {
    Esfera e("amarelo", 7);
    CHECK(abs(e.get_volume()-1436.7538)<0.01);

    Esfera e2("vermelho", 4);
    CHECK(abs(e2.get_volume()-268.0823)<0.01);

    Esfera e3("branco", 12);
    CHECK(abs(e3.get_volume()-7238.2234)<0.01);
}

TEST_CASE("10 - Acessando métodos das classes base do Círculo") {
    Circulo cr("rosa", 5);
    CHECK(abs(cr.get_area()-78.54)<0.001);
    CHECK(abs(cr.get_perimetro()-31.416)<0.001);

    Circulo cr2("verde", 8);
    CHECK(abs(cr2.get_area()-201.062)<0.001);
    CHECK(abs(cr2.get_perimetro()-50.265)<0.001);

    Circulo cr3("azul", 13);
    CHECK(abs(cr3.get_area()-530.929)<0.001);
    CHECK(abs(cr3.get_perimetro()-81.681)<0.001);
}

TEST_CASE("11 - Acessando métodos do triangulo") {
    Triangulo triangulo1("azul", 3, 6, 5);
    Triangulo triangulo2("vermelho", 20, 18, 16);
    Triangulo triangulo3("rosa", 9, 4, 6);
    
    Forma2D *poligono1 = &triangulo1;
    Forma2D *poligono2 = &triangulo2;
    Forma2D *poligono3 = &triangulo3;
    
    //checando nomes
    CHECK((abs(poligono1->get_area()-7.4833))<0.001);
    CHECK((abs(poligono2->get_area()-136.7882))<0.001);
    CHECK((abs(poligono3->get_area()-9.5623))<0.001);
}

TEST_CASE("12 - Acessando métodos do quadrado") {
    Quadrado quadrado1("vermelho", 8);
    Quadrado quadrado2("preto", 2);
    Quadrado quadrado3("branco", 9);
    
    Forma2D *poligono1 = &quadrado1;
    Forma2D *poligono2 = &quadrado2;
    Forma2D *poligono3 = &quadrado3;
    
    //checando nomes
    CHECK(poligono1->get_area()==64);
    CHECK(poligono2->get_area()==4);
    CHECK(poligono3->get_area()==81);

}

TEST_CASE("13 - Acessando métodos da esfera") {
    Esfera esfera1("roxo", 9);
    Esfera esfera2("laranja", 11);
    Esfera esfera3("verde", 5);
    
    Forma3D *poligono1 = &esfera1;
    Forma3D *poligono2 = &esfera2;
    Forma3D *poligono3 = &esfera3;
    
    //checando nomes
    CHECK(abs(poligono1->get_volume()-3053.63)<0.01);
    CHECK(abs(poligono2->get_volume()-5575.28)<0.01);
    CHECK(abs(poligono3->get_volume()-523.6)<0.01);
}

TEST_CASE("14 - Acessando métodos do cubo") {
    Cubo cubo1("rosa", 3);
    Cubo cubo2("amarelo", 7);
    Cubo cubo3("vermelho", 13);
    
    Forma3D *poligono1 = &cubo1;
    Forma3D *poligono2 = &cubo2;
    Forma3D *poligono3 = &cubo3;
    
    CHECK(poligono1->get_volume()==27);
    CHECK(poligono2->get_volume()==343);
    CHECK(poligono3->get_volume()==2197);
}

TEST_CASE("15 - Acessando métodos do circulo") {
    Circulo circulo1("amarelo", 4);
    Circulo circulo2("preto", 7);
    Circulo circulo3("cinza", 11);
    
    Forma2D *poligono1 = &circulo1;
    Forma2D *poligono2 = &circulo2;
    Forma2D *poligono3 = &circulo3;
    
    CHECK(abs(poligono1->get_area()-50.265)<0.001);
    CHECK(abs(poligono2->get_area()-153.938)<0.001);
    CHECK(abs(poligono3->get_area()-380.133)<0.001);
}

