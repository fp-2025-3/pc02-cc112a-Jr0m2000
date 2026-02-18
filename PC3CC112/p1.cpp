#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int transformar(char*texto,int*N){
    char* token=strtok(texto,", ");
    int n=0;
    while (token!=nullptr)
    {
        *N=atoi(token);
        token=strtok(nullptr,", ");
        N++;
        n++;
    }
    return n;
}

bool sumaK(int*N,int n,int k){
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(N[i]+N[j]==k){
                return true;
            }
        }
        
    }
    return false;
}
//pequeñas correcciones en mis funciones aun me falta implementar el algoritmo O(n)
//en cuanto pueda resolver como hacerlo con esa complejidad le hago commit

int main()
{

    char texto[] = "1, 2, 4, 7, 11";
    int A[100];
    int k;
    cout<<"indique el numero K: ";
    cin>>k;
    int num= transformar(texto,A);
    if(sumaK(A,num,k)==true){
        cout<<"SI existen 2 numeros con suma "<<k<<endl;
    } else
    {
        cout<<"NO existen 2 numeros con suma "<<k<<endl;
    }
    
    
    return 0;
}
