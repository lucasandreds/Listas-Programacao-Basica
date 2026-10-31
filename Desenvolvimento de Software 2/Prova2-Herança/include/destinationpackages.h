#ifndef PROVA2_PDS2_DESTINATIONPACKAGES_H
#define PROVA2_PDS2_DESTINATIONPACKAGES_H

#include "package.h"
#include <map>
#include <vector>
#include <string>

class DestinationPackages{
    public:
        void add_package(Package* g);
        double custo_total();
        double custo_total(std::string nome);
    private:
        std::map<std::string, std::vector<Package*>> pacotes;
};

#endif