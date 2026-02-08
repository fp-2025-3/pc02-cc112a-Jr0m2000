#include <iostream>

using namespace std;

void agregarEstudiante(int*codigos,int*promedios,int n){

    
}

int main()
{
    int n=5;

    int* codigos=new int[n];
    int* promedios=new int[n];
    agregarEstudiante(codigos,promedios,n);

    delete [] codigos;
    delete [] promedios;
    return 0;
}