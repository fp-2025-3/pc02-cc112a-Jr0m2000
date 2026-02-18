#include <iostream>




using namespace std;

int SumaSubMatriz(int (*A)[5],int n, int m,int i1,int j1,int i2, int j2){

    int suma=0;
    if(i1>n||j1>m||i2>n||j2>m||i1<0||i2<0||j1<0||j2<0) return 0;
    for (int (*i)[5] = A+i1; i < A+i2; i++)
    {
        for (int* j = *A+j1; j < *A+j2; j++)
        {
            suma=suma+*j;
        }
        
    }
    
    return suma;
}

void SubMatrizMax(int (*A)[5],int n, int m){
 
    int sumaMax=**A;
    int i1,i2,j1,j2;
    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l < m; l++)
        {
            for (int (*i)[5] = A; i < A+n; i++){

                for (int* j = *A; j < *A+m; j++){
                    if (SumaSubMatriz(A,n,m,k,l,i-A,j-*A)>sumaMax){
                        sumaMax=SumaSubMatriz(A,n,m,k,l,i-A,j-*A);
                        i1=k,j1=l-3,i2=i-A,j2=j-*A-1;
                    }
            
                }
        
            }
        }
    }
    
        
    cout<<"SubMatriz de suma Maxima: "<<endl;
    cout<<"esquina superior izquierda: ("<<i1<<","<<j1<<")"<<endl;
    cout<<"esquina inferior derecha: ("<<i2<<","<<j2<<")"<<endl;
    cout<<"suma Maxima: "<<sumaMax<<endl;



    
}


int main()
{
    int M[4][5]={
    {-2,1,-3,4,-1},
    {2,3,-2,1,-5},
    {-1,4,2,-3,2},
    {1,-2,3,4,-1}};
    
    int (*inicioF)[5]=M;
    SubMatrizMax(inicioF,4,5);

    return 0;
}
