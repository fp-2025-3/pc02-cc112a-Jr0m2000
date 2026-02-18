#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<iomanip>

using namespace std;

struct Seleccion
{
    string nombre;
    int PG;
    int PE;
    int PP;
    int GF;
    int GC;
    int Puntaje;
    int DiffG;//GF-GC
    float Rend;//(PG*3+PE)/300 *100%
};

void generarPartidos(Seleccion &S);
void generarGoles(Seleccion &S);
void generarExtras(Seleccion &S);
void OrdenarSelecciones(Seleccion S[],int n);
void MostrarTabla(Seleccion S[],int n);

int main()
{
    srand(time(NULL));
    Seleccion Pais[5];
    Pais[0].nombre="Pais_1",Pais[1].nombre="Pais_2",Pais[2].nombre="Pais_3",Pais[3].nombre="Pais_4",Pais[4].nombre="Pais_5";
    for (int i = 0; i < 5; i++)
    {
        generarPartidos(Pais[i]);
        generarGoles(Pais[i]);
        generarExtras(Pais[i]);
    }
    OrdenarSelecciones(Pais,5);
    MostrarTabla(Pais,5);

    return 0;
}

void generarPartidos(Seleccion &S){
    S.PG=rand()%100;
    S.PE=rand()%(100-S.PG);
    S.PP=100-(S.PG+S.PE);
}

void generarGoles(Seleccion &S){

    int GFtotales=0,GCtotales=0;
    for (int i = 0; i < S.PG; i++)
    {
        do{
        S.GF=rand()%5;
        S.GC=rand()%5;
        }while (S.GF<=S.GC);
        GFtotales+=S.GF;
        GCtotales+=S.GC;
    }
    for (int i = 0; i < S.PE; i++)
    {
        do{
        S.GF=rand()%5;
        S.GC=rand()%5;
        }while (S.GF!=S.GC);
        GFtotales+=S.GF;
        GCtotales+=S.GC;
    }

    for (int i = 0; i < S.PP; i++)
    {
        do
        {
        S.GF=rand()%5;
        S.GC=rand()%5; 
        }while (S.GC<=S.GF);
        GFtotales+=S.GF;
        GCtotales+=S.GC;
    }
    
    S.GC=GCtotales;
    S.GF=GFtotales;
}

void generarExtras(Seleccion &S){
    S.Puntaje=(S.PG*3+S.PE);
    S.DiffG=(S.GF-S.GC);
    S.Rend=(float)(S.PG*3+S.PE)/3.0;
}

void OrdenarSelecciones(Seleccion S[],int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1-i; j++)//habia puesto i en lugar de j por ello no ordenaba
        {
            if (S[j+1].Puntaje>S[j].Puntaje)
            {
                swap(S[j+1],S[j]);
            }
            if (S[j+1].Puntaje==S[j].Puntaje)
            {
                if (S[j+1].DiffG>S[j].DiffG)
                {
                    swap(S[j+1],S[j]);
                }
                if (S[j+1].DiffG==S[j].DiffG)
                {
                    if (S[j+1].GF>S[j].GF)
                    {
                        swap(S[j+1],S[j]);
                    }
                    
                }
                
                
            }
            
            
        }
        
    }
    
}
void MostrarTabla(Seleccion S[],int n){
    cout<<"Seleccion\tPG\tPE\tPP\tGF\tGC\tDG\tPts\tRend(%)"<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<S[i].nombre<<"\t\t"<<S[i].PG<<"\t"<<S[i].PE<<"\t"<<S[i].PP<<"\t"<<S[i].GF<<"\t"<<S[i].GC<<"\t"<<S[i].DiffG<<"\t"<<S[i].Puntaje<<"\t"<<fixed<<setprecision(1)<<S[i].Rend;
        cout<<endl;
    }
    cout<<"CAMPEON: "<<S[0].nombre<<" | Puntaje: "<<S[0].Puntaje<<" | DG: "<<S[0].DiffG<<" | Rendimiento: "<<fixed<<setprecision(1)<<S[0].Rend<<endl;
}