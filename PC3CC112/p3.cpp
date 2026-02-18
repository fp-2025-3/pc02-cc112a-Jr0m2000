#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void crearM(int**M,int f,int c){
    srand(time(NULL));
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(j!=0){
                *(*M+i*c+j)=1+rand()%9;
                while (*(*M+i*c+j)==*(*M+i*c+j-1))
                {
                    *(*M+i*c+j)=1+rand()%9;
                }
            }else{
                *(*M+i*c+j)=1+rand()%9;
            }
        }
    }
    for (int i = 0; i < f; i++)
    {
        for (int j = 1; j < c; j++)
        {
            for (int k = 0; k < j; k++)
            {
                if(*(*M+i*c+k)==*(*M+i*c+j)){
                    *(*M+i*c+j)=1+rand()%9;
                    j--;
                }
            }
            
        }
    }

}
void imprimir(int**M,int f,int c){
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<*(*M+i*c+j)<<" ";
            
        }
        cout<<endl;
    }

}
void modificar(int**M,int f, int c,int n,int m){
    int aux=*(*M+(n-1)*c+(m-1));//valor (n,m)
    for (int i = 0; i < f; i++)
    {
        *(*M+i*c+m-1)=aux;
    }

}

int main()
{

    
    int M[9][9];
    int* fM=&M[0][0];
    int ** pM=&fM;
    int n;
    int m;


    crearM(pM,9,9);
    cout<<"Matriz original: "<<endl;
    imprimir(pM,9,9);
    do
    {
        cout<<"fila inicial: ";
        cin>>n;
        cout<<"columna inicial: ";
        cin>>m;
    } while ((n>=10||n<=0)||(m>=10||m<=0));
    
    cout<<"MATRIZ MODIFICADA:"<<endl;
    modificar(pM,9,9,n,m);
    imprimir(pM,9,9);
    return 0;
}