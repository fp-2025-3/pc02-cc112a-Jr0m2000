#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int transformar(char*texto,int*N){
    char* token=strtok(texto,", ");
    int n=0;
    while (token!=nullptr)
    {
        *N=(int)(*token);
        token=strtok(nullptr,", ");
        N++;
        n++;
    }
    return n;
}

bool sumaK(int*N,int n,int k){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < n; i++)
        {
            if(i!=j&&N[i]+N[j]==k){
                return true;
            }
        }
        
    }
    return false;
}

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
