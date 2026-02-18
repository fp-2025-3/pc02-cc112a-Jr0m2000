#include <iostream>




using namespace std;

bool posPico(int (*A)[5],int n, int m){

    for (int (*i)[5] = A; i < A+n; i++)
    {
        for (int* j = *A; j < *A+m; j++)
        {
           if(*j>=*(j-1)||*j>=*(j+1)||*j>=*(*(i+1)+(j-*A))||*j>=*(*(i-1)+(j-*A))){
            if (*j>*(j-1)||*j>*(j+1)||*j>*(*(i+1)+(j-*A))||*j>*(*(i-1)+(j-*A)))
            {
                //tengo que implementar una condicion para evaluar sobre una posicion dada
                //luego solo recorrer y comparar
                
                return true;
            }
            
           } 
        }
        
    }
    
    return false;
}

int main()
{
    int M[4][5]={
    {3,3,3,3,3},
    {3,4,4,2,3},
    {3,4,5,4,3},
    {3,3,3,3,3}};
    
    int (*inicioF)[5]=M;
    int (*finF)[5]=M+4;
    
    for (int (*i)[5] = inicioF; i < finF; i++)
    {
        for (int* j = *i; j < *i+4; j++)
        {
            if (*j>=*(j-1)||*j>=*(j+1)||*j>=*(*(i+1)))
            {
                
            }
            
        }
        
    }
    

    return 0;
}