#include <iostream>

using namespace std;

int main(){
    int valor = 10; //1
    int *ponteiro = nullptr; //2
    int vetor[] = {9,8,7,6,5,4,3,2,1,0}; //3

    cout << &valor << endl; //4
    cout << valor << endl; //5
    cout << &ponteiro << endl; //6
    cout << ponteiro << endl; //7
    cout << &vetor << endl; //8
    cout << &vetor[0] << endl; //9
    cout << vetor[0] << endl; //10

    ponteiro = &valor; //11

    cout << ponteiro << endl; //12
    cout << *ponteiro << endl; //13

    cout << (&valor == ponteiro) << endl; //14

    *ponteiro = 5; //15

    cout << valor << endl; //16

    ponteiro = vetor; //17

    cout << ponteiro << endl; //18
    cout << *ponteiro << endl; //19

    ponteiro = &vetor[0]; //20

    cout << ponteiro << endl; //21
    cout << *ponteiro << endl; //22

    for(int i = 0; i < 10;i++){
        *(ponteiro + i) *= 10; //23
    }

    for(int i =0; i < 9; i++){
        cout << vetor[i] << " "; //24
    }
    cout << vetor[9] << endl;


    for(int i =0; i < 9; i++){
        cout << *(vetor+i) << " "; //25
    }
    cout << *(vetor + 9) << endl;

    for(int i =0; i < 9; i++){
        cout << *(ponteiro + i) << " "; //26
    }
    cout << *(ponteiro + 9) << endl;

    ponteiro = &vetor[4]; //27
    cout << ponteiro << endl; //28
    cout << *ponteiro << endl; //29
    cout << *(ponteiro-4) << endl; //30

    int **ponteiro_para_ponteiro = &ponteiro; //31

    cout << ponteiro_para_ponteiro << endl; //32
    cout << &ponteiro_para_ponteiro << endl; //33
    cout << *ponteiro_para_ponteiro << endl; //34
    cout << **ponteiro_para_ponteiro << endl; //35

    return 0;
}