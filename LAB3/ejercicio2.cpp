#include <iostream>
#include <climits>

using namespace std;

const int N = 5;

bool esFilaDominante(int (*M)[N], int fila);

int contarColumnasCriticas(int (*M)[N]);

bool esMatrizEscalonada(int (*M)[N]);

int valorNucleo(int (*M)[N]);

int main()
{
    int M[N][N] = {
        {0, 0, 7, 8, 9},
        {0, 0, 0, 5, 6},
        {0, 0, 0, 0, 4},
        {1, 2, 3, 4 ,5},
        {9, 10, 11, 12, 13}
    };
    cout << "filas dominantes:"<<endl;
    for (int i = 0; i < N; i++)
    {
        if (esFilaDominante(M, i))
        {
            cout << "la fila " << i << " es dominante"<<endl;
        }
    }

    int colCriticas = contarColumnasCriticas(M);
    cout << "cantidad de columnas criticas: " << colCriticas << endl;

    if(esMatrizEscalonada(M)){
         cout << "SI es escalonada" <<endl;
    } else {
        cout  << "NO es escalonada" <<endl;
    }

    int nucleo = valorNucleo(M);

    if (nucleo != -1)
    {
        cout << "valor nucleo de la matriz: " << nucleo << endl;
    }
    else
    {
        cout << "la matriz no tiene nucleo"<<endl;
    }


    return 0;
}



bool esFilaDominante(int (*M)[N], int fila){
    
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            
            if(M[fila][j]<=M[i][j] && i!=fila){
                return false;
            }

        }
        
    }
    
    return true;
}

int contarColumnasCriticas(int (*M)[N]){
    int sumaFilaMax=INT_MIN;

    for (int i = 0; i < N; i++)
    {
        int sumaF=0;
        for (int j = 0; j < N; j++)
        {
            sumaF+=M[i][j];
        }
        if (sumaF>sumaFilaMax)
        {
            sumaFilaMax=sumaF;
        }
        
    }
    
    int nColCrit=0;
    for (int j = 0; j < N; j++)
    {
        int sumaC=0;
        for (int i = 0; i < N; i++)
        {
            sumaC+=M[i][j];
        }
        if (sumaC>sumaFilaMax)
        {
            nColCrit++;
        }
        
    }
    
    return nColCrit;
}

bool esMatrizEscalonada(int (*M)[N]){

    int posAnterior = -1;

    for (int i = 0; i < N; i++)
    {
        int* fila= *(M+i);
        int posActual=-1;
        for (int j = 0; j< N; j++)
        {
            if (*(fila+j)!= 0)
            {
                posActual=j;
                break;
            }
            
        }
        if (posActual!=-1)
        {
            if (posActual<=posAnterior)
            {
                return false;
            }
            posAnterior=posActual;
            
        }
        
    
    }
    
    return true;
}

int valorNucleo(int (*M)[N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x = M[i][j];
            bool maxFila = true;
            bool minCol = true;
            for (int k = 0; k < N; k++)
            {
                if (M[i][k] > x)
                {
                    maxFila = false;
                    break;
                }
            }

            for (int k = 0; k < N; k++)
            {
                if (M[k][j] < x)
                {
                    minCol = false;
                    break;
                }
            }

            if (maxFila && minCol){
                return x;
            }
        }
    }
    return -1;
}
