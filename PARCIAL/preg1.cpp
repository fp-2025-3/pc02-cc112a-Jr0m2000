#include <iostream>

using namespace std;

int costoMaximo(int*A,int n,int pos){
    //caso base
    if (n==pos)
    {
        return 0;
    }
    //segmento
    
    for (int i = pos; i < n; i++)
    {
        int valor=1;
        valor *= *(A+i);
    }

    return 1;
    
}

int main()
{
    
    return 0;
}
