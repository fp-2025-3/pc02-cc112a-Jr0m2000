#include<iostream>

using namespace std;

struct Polinomio
{
    int grado;
    int* C;
};

Polinomio SumaPolinomios(Polinomio &p1,Polinomio &p2,Polinomio &p3);

Polinomio ProdutoPolinomios(Polinomio &p1,Polinomio &p2,Polinomio &p3);

void MostrarPolinomio(Polinomio &p);

int main()
{
    Polinomio p1,p2,p3;

    p1.grado=2;
    p1.C=new int[p1.grado+1];
    p1.C[0]=1,p1.C[1]=0,p1.C[2]=3;
    p2.grado=1;
    p2.C=new int[p2.grado+1];
    p2.C[0]=-4,p2.C[1]=5;
    p3.grado=2;
    p3.C=new int[p3.grado+1];
    p3.C[0]=3,p3.C[1]=0,p3.C[2]=1;

    Polinomio Suma=SumaPolinomios(p1,p2,p3);

    Polinomio Producto=ProdutoPolinomios(p1,p2,p3);

    cout<<"Polinomio 1: ";
    MostrarPolinomio(p1);
    cout<<endl;
    cout<<"Polinomio 2: ";
    MostrarPolinomio(p2);
    cout<<endl;
    cout<<"Polinomio 3: ";
    MostrarPolinomio(p3);
    cout<<endl;
    cout<<"La suma de los tres Polinomios: ";
    MostrarPolinomio(Suma);
    cout<<endl;
    cout<<"El producto de los tres Polinomios: ";
    MostrarPolinomio(Producto);
    cout<<endl;

    delete [] p1.C;
    delete [] p2.C;
    delete [] p3.C;
    delete [] Suma.C;
    delete [] Producto.C;
    p1.C=nullptr;
    p2.C=nullptr;
    p3.C=nullptr;
    Suma.C=nullptr;
    Producto.C=nullptr;
    return 0;
}

Polinomio SumaPolinomios(Polinomio &p1,Polinomio &p2,Polinomio &p3){
    Polinomio Suma;
    Suma.grado=0;
    if(p1.grado>=Suma.grado){
        Suma.grado=p1.grado;
    }
    if (p2.grado>=Suma.grado)
    {
        Suma.grado=p2.grado;
    }
    if (p3.grado>=Suma.grado)
    {
        Suma.grado=p3.grado;
    }
    
    Suma.C=new int[Suma.grado+1];
    for (int i = 0; i < Suma.grado+1; i++)
    {
        Suma.C[i]=0;
    }
    for (int i = 0; i < p1.grado+1; i++)
    {
        Suma.C[Suma.grado-i]+=p1.C[p1.grado-i];
    }
    for (int i = 0; i < p2.grado+1; i++)
    {
        Suma.C[Suma.grado-i]+=p2.C[p2.grado-i];
    }
    for (int i = 0; i < p3.grado+1; i++)
    {
        Suma.C[Suma.grado-i]+=p3.C[p3.grado-i];
    }
    
    return Suma;
    
}

Polinomio ProdutoPolinomios(Polinomio &p1,Polinomio &p2,Polinomio &p3){
    Polinomio prod;
    prod.grado=p1.grado+p2.grado+p3.grado;
    prod.C=new int[prod.grado+1];
    for (int i = 0; i < prod.grado+1; i++)
    {
        prod.C[i]=0;
    }
    for (int i = 0; i < p1.grado+1; i++)
    {
        for (int j = 0; j < p2.grado+1; j++)
        {
            for (int k = 0; k < p3.grado+1; k++)
            {
                prod.C[i+j+k]+=p1.C[i]*p2.C[j]*p3.C[k];
            }
            
        }
        
    }
    
    return prod;
}
void MostrarPolinomio(Polinomio &p){
    for (int i = 0; i < p.grado+1; i++)
    {
        
        if (i==0&&p.C[i]!=0)
        {
            cout<<p.C[i]<<"x^"<<p.grado;
        }
        if (i==p.grado&& p.C[i]!=0)
        {
            cout<<"+ "<<p.C[i];
        }    
        if (i!=0 && i!=p.grado && p.C[i]!=0)
        {
            cout<<"+ "<<p.C[i]<<"x^"<<p.grado-i;
        }
        
        
    }
    
}