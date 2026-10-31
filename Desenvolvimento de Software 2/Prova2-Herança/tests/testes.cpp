#include "doctest.h"

#include "destinationpackages.h"
#include "overnightpackage.h"
#include "package.h"
#include "twodaypackage.h"

#include <string>


TEST_CASE("01 - Testando o construtor sem parâmetros") {
    CHECK_NOTHROW(DestinationPackages());
}


TEST_CASE("02 - Testando a inserção de pacotes e o custo total por usuário") {
    Package *p1 = new Package(2,5, "Josias", "Alfeneiros");
    Package *p2 = new Package(5,5, "Carlos", "Alfeneiros");
    Package *p3 = new Package(4,5, "Maria", "Alfeneiros");
    Package *p4 = new Package(2,5, "Maria", "Alfeneiros");
    Package *p5 = new Package(1,5, "Josias", "Alfeneiros");
    
    DestinationPackages pacotes;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));
    CHECK_NOTHROW(pacotes.add_package(p3));
    CHECK_NOTHROW(pacotes.add_package(p4));
    CHECK_NOTHROW(pacotes.add_package(p5));
    
    CHECK(pacotes.custo_total("Josias") == 15);
    CHECK(pacotes.custo_total("Maria") == 30);
    CHECK(pacotes.custo_total("Carlos") == 25);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}

TEST_CASE("03 - Testando o cálculo de custo total de pacotes") {
    Package *p1 = new Package(2,5, "Josias", "Alfeneiros");
    Package *p2 = new Package(5,5, "Carlos", "Alfeneiros");
    Package *p3 = new Package(4,5, "Maria", "Alfeneiros");
    Package *p4 = new Package(2,5, "Maria", "Alfeneiros");
    Package *p5 = new Package(1,5, "Josias", "Alfeneiros");
    
    DestinationPackages pacotes;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));
    CHECK_NOTHROW(pacotes.add_package(p3));
    CHECK_NOTHROW(pacotes.add_package(p4));
    CHECK_NOTHROW(pacotes.add_package(p5));
    
    CHECK(pacotes.custo_total() == 70);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}

TEST_CASE("04 - Checando um custo nulo para uma chave não presente no map; e para um map vazio") {
    Package *p1 = new Package(2,5, "Josias", "Alfeneiros");
    Package *p2 = new Package(5,5, "Carlos", "Alfeneiros");
    Package *p3 = new Package(4,5, "Maria", "Alfeneiros");
    Package *p4 = new Package(2,5, "Maria", "Alfeneiros");
    Package *p5 = new Package(1,5, "Josias", "Alfeneiros");
    
    DestinationPackages pacotes;
    DestinationPackages pacotes2;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));
    CHECK_NOTHROW(pacotes.add_package(p3));
    CHECK_NOTHROW(pacotes.add_package(p4));
    CHECK_NOTHROW(pacotes.add_package(p5));
    
    CHECK(pacotes.custo_total("Marcos") == 0);
    CHECK(pacotes2.custo_total()==0);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}


TEST_CASE("05 - Inserção de membros de classes derivadas e cálculo de custo polimorficamente") {
    Package *p1 = new OverNightPackage(2, 5, 7, "Maria", "Rio");
    Package *p2 = new OverNightPackage(3, 2, 1, "Paulo", "Juazeiro");
    Package *p3 = new TwoDayPackage(5, 2, 4, "Josias", "Juazeiro");
    Package *p4 = new TwoDayPackage(2, 5, 3, "Maria", "Juazeiro");
    Package *p5 = new Package(5, 7, "Paulo", "Juazeiro");

    DestinationPackages pacotes;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));
    CHECK_NOTHROW(pacotes.add_package(p3));
    CHECK_NOTHROW(pacotes.add_package(p4));
    CHECK_NOTHROW(pacotes.add_package(p5));
    
    CHECK(pacotes.custo_total("Josias") == 14);
    CHECK(pacotes.custo_total("Maria") == 37);
    CHECK(pacotes.custo_total("Paulo") == 44);
    CHECK(pacotes.custo_total() == 95);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}

TEST_CASE("06 - Testando o funcionamento dos construtores das classes"){
    CHECK_NOTHROW(OverNightPackage(16, 10, 4, "Lucas", "Rio"));
    CHECK_NOTHROW(TwoDayPackage(9, 35, 8, "Ingrid", "Contagem"));
    CHECK_NOTHROW(Package(3, 60, "Maria", "Betim"));
}

TEST_CASE("07 - Testando inserir o pacote e pegar o seu peso através da herança") {
    Package *p1 = new OverNightPackage(16, 10, 4, "Lucas", "Rio");
    Package *p2 = new OverNightPackage(5, 15, 2, "Maria", "Contagem");
    Package *p3 = new TwoDayPackage(9, 35, 8, "Ingrid", "Contagem");
    Package *p4 = new TwoDayPackage(20, 9, 5, "Lucas", "Belo Horizonte");
    Package *p5 = new Package(3, 60, "Maria", "Betim");
    
    CHECK(p1->getPeso() == 16);
    CHECK(p2->getPeso() == 5);
    CHECK(p3->getPeso() == 9);
    CHECK(p4->getPeso() == 20);
    CHECK(p5->getPeso() == 3);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}

TEST_CASE("08 - Testando inserir o pacote e pegar o seu custo através da herança") {
    
    Package *p1 = new OverNightPackage(16, 10, 4, "Lucas", "Rio");
    Package *p2 = new OverNightPackage(5, 15, 2, "Maria", "Contagem");
    Package *p3 = new TwoDayPackage(9, 35, 9, "Ingrid", "Contagem");
    Package *p4 = new TwoDayPackage(20, 9, 5, "Lucas", "Belo Horizonte");
    Package *p5 = new Package(3, 60, "Maria", "Betim");
    
    CHECK(p1->getCusto() == 10);
    CHECK(p2->getCusto() == 15);
    CHECK(p3->getCusto() == 35);
    CHECK(p4->getCusto() == 9);
    CHECK(p5->getCusto() == 60);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}

TEST_CASE("09 - Testando inserir o pacote e pegar o seu nome através da herança") {

    Package *p1 = new OverNightPackage(16, 10, 4, "Lucas Andre", "Rio");
    Package *p2 = new OverNightPackage(5, 15, 2, "Maria", "Contagem");
    Package *p3 = new TwoDayPackage(9, 35, 9, "Ingrid Silva", "Contagem");
    Package *p4 = new TwoDayPackage(20, 9, 5, "Antonio", "Belo Horizonte");
    Package *p5 = new Package(3, 60, "Pedro Lopes", "Betim");
    
    CHECK(p1->getNome().compare("Lucas Andre") == 0);
    CHECK(p2->getNome().compare("Maria")== 0);
    CHECK(p3->getNome().compare("Ingrid Silva") == 0);
    CHECK(p4->getNome().compare("Antonio") == 0);
    CHECK(p5->getNome().compare("Pedro Lopes") == 0);

    DestinationPackages pacotes;

    pacotes.add_package(p1);
    pacotes.add_package(p2);
    pacotes.add_package(p3);
    pacotes.add_package(p4);
    pacotes.add_package(p5);

    CHECK(pacotes.custo_total("Lucas") == 0);
    CHECK(pacotes.custo_total("Maria Leandra") == 0);
    CHECK(pacotes.custo_total("Ingrid") == 0);
    CHECK(pacotes.custo_total("Antonio Lopes") == 0);
    CHECK(pacotes.custo_total("Pedro") == 0);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    
}

TEST_CASE("10 - Testando inserir o pacote e pegar o seu endereço através da herança") {
    
    Package *p1 = new OverNightPackage(16, 10, 4, "Lucas", "Rio de Janeiro");
    Package *p2 = new OverNightPackage(5, 15, 2, "Maria", "Contagem");
    Package *p3 = new TwoDayPackage(9, 35, 9, "Ingrid", "Sete Lagoas");
    Package *p4 = new TwoDayPackage(20, 9, 5, "Antonio", "Belo Horizonte");
    Package *p5 = new Package(3, 60, "Pedro", "Betim");
    
    CHECK(p1->getEndereco().compare("Rio de Janeiro") == 0);
    CHECK(p2->getEndereco().compare("Contagem") == 0);
    CHECK(p3->getEndereco().compare("Sete Lagoas") == 0);
    CHECK(p4->getEndereco().compare("Belo Horizonte") == 0);
    CHECK(p5->getEndereco().compare("Betim") == 0);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}

TEST_CASE("11 - Testando inserir o pacote e pegar o seu custo através da herança e sobreposição") {
    
    Package *p1 = new OverNightPackage(16, 10, 4, "Lucas", "Rio de Janeiro");
    Package *p2 = new OverNightPackage(5, 15, 2, "Maria", "Contagem");
    Package *p3 = new TwoDayPackage(9, 35, 9, "Ingrid", "Sete Lagoas");
    Package *p4 = new TwoDayPackage(20, 9, 5, "Antonio", "Belo Horizonte");
    Package *p5 = new Package(3, 60, "Pedro", "Betim");
    Package *p6 = new Package(2, 180, "Mariana", "Nova Lima");

    CHECK(p1->calculate_cost() == 224);
    CHECK(p2->calculate_cost() == 85);
    CHECK(p3->calculate_cost() == 324);
    CHECK(p4->calculate_cost() == 185);
    CHECK(p5->calculate_cost() == 180);
    CHECK(p6->calculate_cost() == 360);

    DestinationPackages pacotes;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));
    CHECK_NOTHROW(pacotes.add_package(p3));
    CHECK_NOTHROW(pacotes.add_package(p4));
    CHECK_NOTHROW(pacotes.add_package(p5));
    CHECK_NOTHROW(pacotes.add_package(p6));

    CHECK(p1->calculate_cost() == pacotes.custo_total("Lucas"));
    CHECK(p2->calculate_cost() == pacotes.custo_total("Maria"));
    CHECK(p3->calculate_cost() == pacotes.custo_total("Ingrid"));
    CHECK(p4->calculate_cost() == pacotes.custo_total("Antonio"));
    CHECK(p5->calculate_cost() == pacotes.custo_total("Pedro"));
    CHECK(p6->calculate_cost() == pacotes.custo_total("Mariana"));

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}

TEST_CASE("12 - Testando inserir valores inválidos (Custo e peso negativo)") {
    Package *p1 = new OverNightPackage(-16, 10, 4, "Lucas", "Rio de Janeiro");
    Package *p2 = new OverNightPackage(5, -15, 2, "Maria", "Contagem");
    Package *p3 = new TwoDayPackage(9, -35, 9, "Ingrid", "Sete Lagoas");
    Package *p4 = new TwoDayPackage(-20, 9, 5, "Antonio", "Belo Horizonte");
    Package *p5 = new Package(3, -60, "Pedro", "Betim");
    Package *p6 = new Package(-2, 180, "Leonarda", "Nova Lima");

    CHECK(p1->getPeso() >= 0);
    CHECK(p2->getCusto() >= 0);
    CHECK(p3->getCusto() >= 0);
    CHECK(p4->getPeso() >= 0);
    CHECK(p5->getCusto() >= 0);
    CHECK(p6->getPeso() >= 0);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}

TEST_CASE("13 - Inserção de apenas pacotes comuns e cálculo de custo polimorficamente") {
    Package *p1 = new Package(5, 12, "Lucas", "Contagem");
    Package *p2 = new Package(7, 3, "Ludmila", "Belo Horizonte");
    Package *p3 = new Package(2, 6, "Mateus", "Rio Grande do Sul");
    Package *p4 = new Package(13, 9, "Ludmila", "Belo Horizonte");
    Package *p5 = new Package(4, 20, "Lucas", "Contagem");

    DestinationPackages pacotes;
    pacotes.add_package(p1);
    pacotes.add_package(p2);
    pacotes.add_package(p3);
    pacotes.add_package(p4);
    pacotes.add_package(p5);
    
    CHECK(pacotes.custo_total("Lucas") == 140);
    CHECK(pacotes.custo_total("Ludmila") == 138);
    CHECK(pacotes.custo_total("Mateus") == 12);
    CHECK(pacotes.custo_total() == 290);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}

TEST_CASE("14 - Inserção de twodays pacotes e cálculo de custo polimorficamente") {
    Package *p1 = new TwoDayPackage(5, 12, 7, "Sarah", "Contagem");
    Package *p2 = new TwoDayPackage(7, 3, 15, "Priscila", "Belo Horizonte");
    Package *p3 = new TwoDayPackage(2, 6, 25, "Fernando", "Fernando de Noronha");
    Package *p4 = new TwoDayPackage(13, 9, 1, "Priscila", "Belo Horizonte");
    Package *p5 = new TwoDayPackage(4, 20, 85, "Sarah", "Contagem");

    DestinationPackages pacotes;
    pacotes.add_package(p1);
    pacotes.add_package(p2);
    pacotes.add_package(p3);
    pacotes.add_package(p4);
    pacotes.add_package(p5);
    
    CHECK(pacotes.custo_total("Sarah") == 232);
    CHECK(pacotes.custo_total("Priscila") == 154);
    CHECK(pacotes.custo_total("Fernando") == 37);
    CHECK(pacotes.custo_total() == 423);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}

TEST_CASE("15 - Inserção de pacotes overnight e cálculo de custo polimorficamente") {
    Package *p1 = new OverNightPackage(5, 12, 8, "Kamila", "Rio");
    Package *p2 = new OverNightPackage(7, 3, 17, "Leandro", "Juazeiro");
    Package *p3 = new OverNightPackage(2, 6, 4, "Laila", "Juazeiro");
    Package *p4 = new OverNightPackage(13, 9, 11, "Leandro", "Juazeiro");
    Package *p5 = new OverNightPackage(4, 20, 2, "Kamila", "Juazeiro");

    DestinationPackages pacotes;
    pacotes.add_package(p1);
    pacotes.add_package(p2);
    pacotes.add_package(p3);
    pacotes.add_package(p4);
    pacotes.add_package(p5);
    
    CHECK(pacotes.custo_total("Kamila") == 188);
    CHECK(pacotes.custo_total("Leandro") == 400);
    CHECK(pacotes.custo_total("Laila") == 20);
    CHECK(pacotes.custo_total() == 608);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}