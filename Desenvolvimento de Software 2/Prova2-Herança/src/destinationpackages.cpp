#include <destinationpackages.h>

void DestinationPackages::add_package(Package* g){
    if(pacotes.count(g->getNome())){
        pacotes.at(g->getNome()).push_back(g);
    }else{
        std::vector<Package*> pacotesNome;
        pacotesNome.push_back(g);
        pacotes.insert({g->getNome(),pacotesNome});
    }
}

double DestinationPackages::custo_total(){
    double custo_total = 0;
    for(auto it = pacotes.begin(); it != pacotes.end();it++){
        custo_total += DestinationPackages::custo_total(it->first);
    }
    return custo_total;
}

double DestinationPackages::custo_total(std::string nome){
    double custo_total = 0;
    if(pacotes.count(nome)){
        for(Package* pacote: pacotes.at(nome)){
            custo_total += pacote->calculate_cost();
        }
    }
    return custo_total;
}