#include<iostream>
#include<cmath>

using namespace std;

struct Punto
{
    int x;
    int y;
    int z;
};

double Distanciaentre(Punto p1,Punto p2){

    double d;
    double x,y,z;
    x=pow((double)(p1.x-p2.x),2);
    y=pow((double)(p1.y-p2.y),2);
    z=pow((double)(p1.z-p2.z),2);
    d=sqrt(x+y+z);
    return d;
}


int main()
{
    Punto p1,p2;
    cout<<"Ingrese las coordenadas del primer punto: "<<endl;
    cout<<"x:";cin>>p1.x;
    cout<<"y:";cin>>p1.y;
    cout<<"z:";cin>>p1.z;
    cout<<"Ingrese las coordenadas del segundo punto: "<<endl;
    cout<<"x:";cin>>p2.x;
    cout<<"y:";cin>>p2.y;
    cout<<"z:";cin>>p2.z;
    cout<<"La distancia entre los dos puntos es :"<<Distanciaentre(p1,p2)<<endl;
    cout<<"\n\n-----------------------------------------------------------------\n";
    return 0;
}
