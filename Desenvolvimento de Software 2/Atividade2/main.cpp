#include <iostream>
#include <string>

using namespace std;

void verificaCaractere(string palavra, char caractere){
    int contador = 0;
    if(palavra.find(caractere) != string::npos){
        for(int i = 0; i < palavra.size();i++){
            if(palavra.at(i) == caractere){
                contador ++;
            }
        }
        cout << caractere << " " << contador << endl;
    }   
}

int main(){
    string palavra;
    cin >> palavra;

    verificaCaractere(palavra,'a');
    verificaCaractere(palavra,'e');
    verificaCaractere(palavra,'i');
    verificaCaractere(palavra,'o');
    verificaCaractere(palavra,'u');

    return 0;
}