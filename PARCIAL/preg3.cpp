#include <iostream>


using namespace std;

const int N=4;

bool esFilaDominanteEstricta(int(*M)[N],int f){
    bool dominante=true;
    
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (i!=f&&M[f][j]<M[i][j])
            {
                dominante=false;
                return dominante;
            }
        }
        

        
    }
    
    return dominante;
}

bool esFilaFuertementeDominante(int(*M)[N],int f){
    if (esFilaDominanteEstricta(M,f))
    {
        int sumaFMax=-100;
        
        for (int i = 0; i < N; i++)
        {
            int sumaF=0;
            for (int j = 0; j < N; j++)
            {
                sumaF+=M[i][j];
            }
            if (sumaF>sumaFMax)
            {
                sumaFMax=sumaF;
            }
        }
        
        int sumaDom=0;
        for (int j = 0; j < N; j++)
        {
            sumaDom+=M[f][j];
        }
        if(sumaDom>=sumaFMax){
            return true;

        }else
        {
            return false;
        }
        
    }else
    {
        return false;
    }
}


int main()
{
    int M[N][N]={
        {2,3,1,4},
        {1,2,3,2},
        {5,6,7,8},
        {0,1,2,1},
    };
    cout<<"Fila\tDominante Estricta\tFuertmente Dominante"<<endl;

    for (int i = 0; i < N; i++)
    {
        cout<<i<<"\t";
        if (esFilaDominanteEstricta(M,i))
        {
            cout<<"SI\t";
        }else
        {
            cout<<"NO\t";
        }
        if (esFilaFuertementeDominante(M,i))
        {
            cout<<"SI\t";
        }else
        {
            cout<<"NO\t";
        }
        cout<<endl;
    }
    

    return 0;
}
