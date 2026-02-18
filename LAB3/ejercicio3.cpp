#include <iostream>

using namespace std;

const int N=100;

void leerDatos(float nota[], int codigo[], int faltas[],int n){

    for (int i = 0; i < n; i++)
    {
        cout<<"ingrese el codigo del "<<i+1<<" estudiante: ";
        cin>>codigo[i];
        cout<<"ingrese su nota :";
        cin>>nota[i];
        cout<<"ingrese su numero de faltas :";
        cin>>faltas[i];
    }
    
}

void ordenarPorNota(float nota[], int codigo[], int faltas[], int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j <n-i-1 ; j++)
        {
            if (nota[j+1]>nota[j])
            {
                swap(nota[j+1],nota[j]);
                swap(codigo[j+1],codigo[j]);
                swap(faltas[j+1],faltas[j]);

            } else if(nota[j+1]==nota[j]){
                if (faltas[j+1]<faltas[j])
                {
                    swap(nota[j+1],nota[j]);
                    swap(codigo[j+1],codigo[j]);
                    swap(faltas[j+1],faltas[j]);
                }
            }
            
        }
        
    }
    
}


void mostrarRank(float nota[], int codigo[], int faltas[], int n){
    cout<<"el top 5 de estudiantes es: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<i+1<<". "<<codigo[i]<<" con nota: "<<nota[i]<<" y con "<<faltas[i]<<" inasistencias"<<endl;
    }
    float sumaNotas=0;
    int desaprobados=0;
    for (int i = 0; i < n; i++)
    {
        sumaNotas+=nota[i];
        if (nota[i]<10)
        {
            desaprobados++;
        }
        
    }
    float promedio=sumaNotas/n;
    cout<<"el promedio de nota del curso es: "<<promedio<<endl;
    cout<<"el numero de desaprobados es: "<<desaprobados<<endl;
}

void buscarPorCodigo(int codigo[], float nota[], int faltas[], int n, int codBuscado)
{
    for (int i = 0; i < n; i++)
    {
        if (codigo[i] == codBuscado)
        {
            cout << "estudiante encontrado"<<endl;
            cout << "codigo: " << codigo[i] << endl;
            cout << "nota: " << nota[i] << endl;
            cout << "faltas: " << faltas[i] << endl;
            cout << "posicion en el ranking: " << i + 1 << endl;
            return;
        }
    }

    cout << "estudiante no encontrado"<<endl;
}

void ordenarPorCodigo(int codigo[], float nota[], int faltas[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minPos = i;

        for (int j = i + 1; j < n; j++)
        {
            if (codigo[j] < codigo[minPos])
            {
                minPos = j;
            }
        }

        if (minPos != i)
        {
            swap(codigo[i], codigo[minPos]);
            swap(nota[i], nota[minPos]);
            swap(faltas[i], faltas[minPos]);
        }
    }
}

int busquedaBinaria(int codigo[], int n, int clave){
    int l=0;
    int r=n-1;

    while (l<=r)
    {
        int m=(l+r)/2;
        
        if (codigo[m]==clave)
        {
            return m;

        } else if(codigo[m]< clave){

            l=m+1;

        } else{
          
            r=m-1;
        
        }    
    
    }
    
    return -1;
}


int main()
{
    int codigo[N];
    float nota[N];
    int faltas[N];
    cout<<"ingrese el numero de estudiantes: ";
    int n;
    cin>>n;
    leerDatos(nota,codigo,faltas,n);

    ordenarPorNota(nota, codigo, faltas, n);

    mostrarRank(nota, codigo, faltas, n);

    int codBuscado;
    cout << "ingrese codigo a buscar: ";
    cin >> codBuscado;
    buscarPorCodigo(codigo, nota, faltas, n, codBuscado);

    ordenarPorCodigo(codigo, nota, faltas, n);

    cout << "ingrese codigo a buscar: ";
    cin >> codBuscado;
    int pos = busquedaBinaria(codigo, n, codBuscado);
    if (pos != -1)
    {
        cout << "estudiante encontrado" << endl;
        cout << "codigo: " << codigo[pos] << endl;
        cout << "nota: " << nota[pos] << endl;
        cout << "faltas: " << faltas[pos] << endl;
    }
    else
    {
        cout << "estudiante no encontrado" << endl;
    }


    return 0;
}


