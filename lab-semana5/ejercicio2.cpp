#include<iostream>

using namespace std;

struct Estudiante
{
    string Nombre;
    float nota;

};

void llenarNestdiantes(Estudiante*&A,int n){
    for (int i = 0; i < n; i++)
    {
        cout<<"ingrese el nombre del estudiante "<<i+1<<": ";
        getline(cin,A[i].Nombre);
        cout<<"ingrese la nota del estudiante "<<i+1<<": ";
        cin>>A[i].nota;cin.ignore();
    }
    
}

int indiceMayorNota(Estudiante* A, int n){
    int NotaMax=-1;
    int k;
    for (int i = 0; i < n; i++)
    {
        if (A[i].nota>=NotaMax)
        {
            NotaMax=A[i].nota;
            k=i;
        }
        
    }
    return k;
}


int main()
{
    cout<<"ingrese el numero de estudiantes: ";
    int n;
    cin>>n;
    cin.ignore();
    Estudiante* A=new Estudiante[n];
    llenarNestdiantes(A,n);
    int k = indiceMayorNota(A,n);
    cout<<"el estudiante con la mayor nota es: "<<A[k].Nombre<<endl;
    cout<<"Nota: "<<A[k].nota<<endl;

    delete []A;
    A=nullptr;
    return 0;
}
