#include <iostream>
using namespace std;

// Complete la funcion de busqueda
int* buscar(
    int* inicio,                 // Estos dos primeros parametros
    int* fin,                    // delimitan el rango de busqueda a [inicio, fin)
    bool (*equivale)(int, int),  // equivale es una funcion que determina cuando dos enteros se condideran equivalentes
    int clave                    // clave es el valor a buscar segun el criterio indicado
) {
    // Complete aqui 
    for (; inicio < fin; inicio++)
    {
        if(equivale(clave,*inicio)){
            cout<<"encontrado valor: "<<*inicio<<" Pos: ";
            return inicio;
        }

    }
    cout<<"No encontrado;";
    return fin;
}

// Implemente aqui los Criterios de equivalencia
// y si es necesario algunas funciones adicionales para reproducir el ejemplo de salida
bool igual(int a, int b){
    if(a==b) return true;
    return false;
}

bool mismaParidad(int a,int b){
    if(a%2==0 && b%2==0) return true;
    if(a%2!=0 && b%2!=0) return true;
    return false;
}

bool divideA(int a, int b){
    if(a%b==0) return true;
    return false;
}
bool mismaCantidadDigitos(int a, int b){
    int Da=0;
    while (a>0)
    {
        Da++;
        a=a/10;
    }
    int Db=0;
    while (b>0)
    {
        Db++;
        b=b/10;
    }    
    if(Da==Db)return true;
    return false;
}
bool mismoResiduoMod5(int a, int b){
    if(a%5==b%5) return true;
    return false;


}
void imprimirArreglo(int * inicio,int*fin){
    for (; inicio < fin; inicio++)
    {
        cout<<*inicio<<" ";
    }
    
}

int main() {
    int A[] = { -1, 21, 2, -2, 8, 13, 25 };
    int* inicio = A;
    int* fin = A + 7;

    int clave = 13;

    // Imprima el arreglo
    imprimirArreglo(inicio,fin);


    // Llame a la funcion buscar para cada criterio implementado
    cout<<"igualdad exacta: "<<buscar(inicio,fin,igual,clave)<<endl;
    cout<<"Misma Paridad: "<<buscar(inicio,fin,mismaParidad,clave)<<endl;
    cout<<"Divide a: "<<buscar(inicio,fin,divideA,clave)<<endl;
    cout<<"Misma cantidad de digitos: "<<buscar(inicio,fin,mismaCantidadDigitos,clave)<<endl;
    cout<<"Mismo residuo modulo 5: "<<buscar(inicio,fin,mismoResiduoMod5,clave)<<endl;
 

    return 0;
}
