/**/
#include <iostream>
using namespace std;

// Complete la funcion que calcula la derivada de orden k de un polinomio
// Usar EXCLUSIVAMENTE punteros (NO indices)

void derivadaK(
    const double* coef, //
    int grado, int k,   //
    double* res,        //
    int& gradoRes       //
) {
    // Escriba su codigo aqui
    gradoRes = grado - k;

    for (int i = 0; i <=gradoRes; i++)
    {
        *(res +i)= *(coef + i + k);
        for (int j = 0; j < k; j++)
        {
            *(res+i)= *(res+i) *(i+k-j);
        }
        
    }
    
    
}




// Complete la función auxiliar para imprimir un polinomio
void imprimirPolinomio(const double* p, int grado) {
   
    for (int i = 0; i <=grado; i++)
    {
        if (i==grado)
        {
            cout<<*(p+grado-i)<<endl;
        }else
        {
            cout<<*(p+grado-i)<<"x^"<<grado-i<<"+";
        } 
        
    }
    
}

int main() {
    // Polinomio:
    // P(x) = 2 + 3x - x^2 + 4x^3
    double coef[] = {2, 3, -1, 4};
    const int grado = 3;

    double resultado[10]; // espacio suficiente
    int gradoResultado;

    int k = 2; // derivada de orden 2
    cout<<"Polinomio original: "<<endl;
    imprimirPolinomio(coef,grado);

    // Llamar a su funcion derivadaK
    derivadaK(coef,grado,k,resultado,gradoResultado);

    // Llamar la funcion imprimir para mostrar el polinomio original y  la derivada
    cout<<"Polinomio derivado: "<<endl;
    imprimirPolinomio(resultado,gradoResultado);
    cout<<endl;
    return 0;
}
