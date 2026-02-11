#include<iostream>

using namespace std;

struct Polinomio
{
    int grado;
    int* C;
};

void MostrarPolinomio(Polinomio p){
    for (int i = p.grado; i >= 0; i--)
    {
        if (i==0)
        {
            if (p.C[i]>0)
            {
                cout<<"+"<<p.C[i];
            }
            else if (p.C[i]<0)
            {
                cout<<"-"<<p.C[i];
            }
        }
        else if(i==p.grado)
        {
            if (p.C[i]>0)
            {
                cout<<p.C[i]<<"x^"<<i;
            }
            else if (p.C[i]<0)
            {
                cout<<"-"<<p.C[i]<<"x^"<<i;
            }
            
        }
        else if(i<p.grado&&i>0){
            
            if (p.C[i]>0)
            {
                cout<<"+"<<p.C[i]<<"x^"<<i;
            }
            else if (p.C[i]<0)
            {
                cout<<"-"<<p.C[i]<<"x^"<<i;
            }
        }
    }
    cout<<endl;
}

Polinomio SumadePolinomios(Polinomio p1,Polinomio p2){
    Polinomio pTotal;
    if (p1.grado>p2.grado)
    {
        pTotal.grado=p1.grado;
        pTotal.C=new int[pTotal.grado+1];
        for (int i = 0; i <=p2.grado; i++)
        {
            pTotal.C[i]=p2.C[i]+p1.C[i];
        }
        for (int j = p2.grado+1; j <=pTotal.grado; j++)
        {
            pTotal.C[j]=p1.C[j];
        }
    }
    if (p2.grado>p1.grado)
    {
        pTotal.grado=p2.grado;
        pTotal.C=new int[pTotal.grado+1];
        for (int i = 0; i <=p1.grado; i++)
        {
            pTotal.C[i]=p1.C[i]+p2.C[i];
        }
        for (int j = p1.grado+1; j <=pTotal.grado; j++)
        {
            pTotal.C[j]=p2.C[j];
        }
    }   

    if (p1.grado==p2.grado)
    {
        pTotal.grado=p1.grado;
        pTotal.C=new int[pTotal.grado+1];
        for (int i = pTotal.grado; i >= 0; i--)
        {
            pTotal.C[i]=p1.C[i]+p2.C[i];
        }
    
    }

    return pTotal;
}

Polinomio ProductoPolinomios(Polinomio p1,Polinomio p2){
    Polinomio producto;
    producto.grado=(p1.grado)+(p2.grado);
    producto.C=new int[producto.grado+1];
    for (int i = 0; i <=producto.grado; i++)
    {
        producto.C[i]=0;
    }
    for (int i = 0; i <=p1.grado; i++)
    {
        for (int j = 0; j <=p2.grado; j++)
        {
            producto.C[i+j]+=(p1.C[i]*p2.C[j]);
        }
    }
    
    return producto;
}



int main()
{
    Polinomio p1,p2;

    cout<<"Ingrese el grado del primer Polinomio: ";
    cin>>p1.grado;
    p1.C=new int[p1.grado+1];
    for (int i = 0; i < p1.grado+1; i++)
    {
        cout<<"Ingrese el coeficiente de x^"<<p1.grado-i<<": ";
        cin>>p1.C[p1.grado-i];
    }
    cout<<"Ingrese el grado del segundo Polinomio: ";
    cin>>p2.grado;
    p2.C=new int[p2.grado+1];
    for (int i = 0; i < p2.grado+1; i++)
    {
        cout<<"Ingrese el coeficiente de x^"<<p2.grado-i<<": ";
        cin>>p2.C[p2.grado-i];
    }
    cout<<"Primer Polinomio: ";
    MostrarPolinomio(p1);
    cout<<"Segundo Polinomio: ";
    MostrarPolinomio(p2);
    cout<<"La suma de los polinomios es : ";
    Polinomio Suma=SumadePolinomios(p1,p2);
    MostrarPolinomio(Suma);
    Polinomio producto=ProductoPolinomios(p1,p2);
    cout<<"El producto de los polinomios es: ";
    MostrarPolinomio(producto);

    delete [] Suma.C;
    delete [] producto.C;
    delete [] p1.C;
    delete [] p2.C;
    p1.C=nullptr;
    p2.C=nullptr;
    producto.C=nullptr;
    Suma.C=nullptr;
    return 0;
}
