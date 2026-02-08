#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int guardarDirecciones(char* texto,char** indice);
int comparar(const char* a, const char* b);
void ordenarIndice(char** indice,int n);
void imprimir(char* texto, char** indice, int n);

int main()
{
    char texto[]="los punteros no se copian se referencian y se ordenan";
    char *p[1000];
    char **indice=p;
    int n = guardarDirecciones(texto, indice);
    ordenarIndice(indice, n);
    imprimir(texto, indice, n);

    return 0;
}

int guardarDirecciones(char* texto,char** indice){
    char* token=strtok(texto," ");
    int i =0;
    while (token!=nullptr)
    {
        *indice=token;
        token = strtok(nullptr," ");
        indice++;
        i++;
    }
    
    return i;
}

int comparar(const char* a, const char* b){
    while (*a != '\0' && *b != '\0') {
        char ca = tolower(*a);
        char cb = tolower(*b);

        if (ca != cb){
            return ca - cb;
        }
        a++;
        b++;
    }
    return tolower(*a) - tolower(*b);
}

void ordenarIndice(char** indice, int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (comparar(*(indice + j), *(indice + j + 1)) > 0) {
                char* aux = *(indice + j);
                *(indice + j) = *(indice + j + 1);
                *(indice + j + 1) = aux;
            }
        }
    }
}

void imprimir(char* texto, char** indice, int n){
    for (int i = 0; i < n; i++) {
        cout << *(indice + i)
             << " (posicion " << (*(indice + i) - texto) << ")"
             << endl;
    }
}

//me falto tiempo para poder revisar y realizar esta pregunta en el examen
