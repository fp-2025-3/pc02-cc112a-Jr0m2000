#include <iostream>
#include <string>


using namespace std;

const int N=30;

void MostrarRanking(string Corredor[],int Tiempo[],int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (Tiempo[j+1]<Tiempo[j])
            {
                swap(Tiempo[j+1],Tiempo[j]);
                Corredor[j+1].swap(Corredor[j]);
            }
        }
        
    }

    cout<<"RANKING FINAL\n";
    for (int i = 0; i < n; i++)
    {
        cout<<i+1<<". "<<(*Corredor)[i]<<" - "<<Tiempo[i]<<" segundos\n";
    }
    
}

int BusquedaporNombre(string Corredor[],int n,string clave){
    
    for (int i = 0; i < n; i++)
    {
        if (clave==Corredor[i])
        {
            return i;
        }
    }
    
    return -1;
}

void MostrarEnRango(string Corredor[],int Tiempo[],int n,int t_min,int t_max){

    cout<<"Corredores en el Rango ["<<t_min<<", "<<t_max<<"]: \n";
    for (int i = 0; i < n; i++)
    {
        //t_min<=Tiempo[i] && Tiempo[i]<=t_max
        if (t_min<=Tiempo[i] && Tiempo[i]<=t_max)
        {
            cout<<Corredor[i]<<" - "<<Tiempo[i]<<" segundos\n";
        }

    }

}





int main()
{
    string Corredor[N];
    int Tiempo[N]={0}; 
    int n;
    do
    {
    cout<<"Ingrese el numero de corredores: ";
    cin>>n;
    } while(1>n||n>30);
    

    for (int i = 0; i < n; i++)
    {
        cout<<"Nombre del corredor "<<i+1<<": ";
        cin>>Corredor[i];
        do
        {
            cout<<"Tiempo (en segundos): ";
            cin>>Tiempo[i];
        } while(Tiempo[i]<0);

    }
    
    MostrarRanking(Corredor,Tiempo,n);

    cout<<"\nIngrese nombre a buscar: ";
    string clave;
    cin>>clave;
    if (BusquedaporNombre(Corredor,n,clave)==-1)
    {
        cout<<"el corredor no existe"<<endl;
    } else
    {
        cout<<"Corredor encontrado\n";
        cout<<"Posicion: "<<BusquedaporNombre(Corredor,n,clave)+1<<endl;
        cout<<"Tiempo: "<<Tiempo[BusquedaporNombre(Corredor,n,clave)]<<" segundos"<<endl;   
    }
    
    int t_min,t_max;
    cout<<"\nIngrese tiempo minimo y maximo: ";
    cin>>t_min>>t_max;
    MostrarEnRango(Corredor,Tiempo,n,t_min,t_max);    

    return 0;
}
