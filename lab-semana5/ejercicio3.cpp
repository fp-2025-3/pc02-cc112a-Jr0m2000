#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

struct Seleccion
{
    int PG;
    int PE;
    int PP;
    int Pts;
    float Rnd;
};

void llenar(Seleccion M[],int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        M[i].PG=rand()%100;
        M[i].PP=rand()%(100-M[i].PG);
        M[i].PE=100-(M[i].PG+M[i].PP);
        M[i].Pts=M[i].PG*3+M[i].PE;
        M[i].Rnd=(float)M[i].Pts/(float)((M[i].PG+M[i].PP+M[i].PE)*3);
        M[i].Rnd*=100;
    }
    
}

void Imprimir(Seleccion M[], int n){
    cout<<"Seleccion       \t\tPG\tPP\tPE\tPuntaje\tRendimiento\n";
    for (int i = 0; i < n; i++)
    {
        cout<<"Pais_Seleccion "<<i<<"\t\t"<<M[i].PG<<"\t"<<M[i].PP<<"\t"<<M[i].PE<<"\t"<<M[i].Pts<<"\t"<<M[i].Rnd<<endl;
    }
    cout<<endl;
}


int indiceMayorRend(Seleccion M[],int n){
    int rndMAX=-1;
    int k=0;
    for (int i = 0; i < n; i++)
    {
        if (M[i].Rnd>rndMAX)
        {
            rndMAX=M[i].Rnd;
            k=i;
        }
        
    }

    return k;
}

int main()
{

    Seleccion M[5];
    llenar(M,5);
    Imprimir(M,5);
    int k = indiceMayorRend(M,5);
    cout<<"La seleccion con mejor rendimiento es : Seleccion "<<k<<" Rendimiento: "<<M[k].Rnd<<endl;


    
    return 0;
}
