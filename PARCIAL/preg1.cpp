#include <iostream>

using namespace std;

const int N=5;


int costoMaximo(int* A, int n, int pos) {
    //caso base
    if (pos == n) {
        
        return 0;
    }
    int maximo = -1; 
    int valor = 1;

    //segmentos desde pos
    for (int i = pos; i < n; i++) {
        valor *= *(A + i);

        int costo = valor + costoMaximo(A, n, i + 1);

        if (maximo == -1 || costo > maximo){
            
            maximo = costo;
        }
    }

    return maximo;
}


int MostrarPila(int* A, int n, int pos) {

    cout << "costoMaximo(pos=" << pos << ")" << endl;

    // caso base
    if (pos == n) {
        cout << "retorna 0" << endl;
        return 0;
    }

    int maximo = -1;
    int valor = 1;

    for (int i = pos; i < n; i++) {
        valor *= *(A + i);

        cout << "segmento [" << pos << "," << i << "] valor=" << valor << endl;

        int costo = valor + MostrarPila(A, n, i + 1);

        cout << "costo total = " << costo << endl;

        if (maximo == -1 || costo > maximo){
            
            maximo = costo;
        }
    }

    cout << "retorna " << maximo << endl;

    return maximo;
}

//simplemente la misma funcion pero imprimimos en cada paso de la recursion


void MostrarArreglo(int * A, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<*(A+i)<<" ";
    }
    cout<<endl;
}

int main()
{
    
    int A[N] = {1,2,3,4,5};
    MostrarArreglo(A,N);
    cout<<"Costo maximo: "<<costoMaximo(A,N,0)<<endl;

    //ahora para el arreglo {2,1,3}
    int B[3]={2,1,3};
    cout<<"para el arreglo {2,1,3}, llamando a la funcion costoMaximo "<<endl;
    MostrarPila(B,3,0);
    cout<<endl;

    return 0;
}
