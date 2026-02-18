#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

char* leerFrase(){
    char temp[1000];
    cout<<"ingresar una frase: ";
    cin.getline(temp,1000);
    int len=strlen(temp);

    char*frase = new char[len+1];
    for (int i = 0; i <=len; i++)
    {
        *(frase+i)=*(temp+i);
    }
    
    return frase;
}


char* normalizarFrase(char* frase)
{

    char temp[1000];
    int i = 0;
    int j = 0;
    bool enPalabra = false;

    while (*(frase + j) != '\0')
    {
        if (!isspace(*(frase + j)))
        {
            *(temp + i) = tolower(*(frase + j));
            i++;
            enPalabra = true;
        }
        else
        {
            if (enPalabra)
            {
                *(temp + i) = ' ';
                i++;
                enPalabra = false;
            }
        }
        j++;
    }
    if (i > 0 && *(temp + i - 1) == ' ') 
    {
        i--;
    }
    *(temp + i) = '\0';

    char* Normalizada=new char [i+1];
    strcpy(Normalizada,temp);

    return Normalizada;
}


int contarPalabras(char* frase){

    int n=0;
    int i=0;
    while (*(frase+i) !='\0')
    {
        if(!isspace(*(frase+i)) && (i==0 || isspace(*(frase+i-1)))){
            n++;
        }
        i++;
    }

    return n;
}

char** separarPalabras(char* frase, int n){
    char** palabras = new char*[n];

    int i =0;
    int j =0;

    while (*(frase+i)!='\0')
    {
        while (isspace(*(frase+i)))
        {
            i++;
        }
        int inicio= i;
        int len = 0;
        while (*(frase+i) != '\0' && !isspace(*(frase+i)))
        {
            i++;
            len++;
        }
        *(palabras+j)= new char[len + 1];
        for (int k = 0; k < len; k++)
        {
            *(*(palabras+j)+k) = *(frase + inicio + k);
        }
        *(*(palabras+j)+len)='\0';

        j++;
    }
    return palabras;

}

void mostrarPalabras(char** palabras, int n) {
    for (int i = 0; i < n; ++i) {
        cout << palabras[i] << "\t" << strlen(palabras[i]) <<endl;
    } 

}


void liberarMemoria(char** palabras, int n){

    for (int i = 0; i < n; i++)
    {
        delete [] *(palabras+i);
    }
    delete [] palabras;
}


int main()
{
    char* frase = leerFrase();
    
    char* normalizada = normalizarFrase(frase);
 
    int numPal = contarPalabras(frase);

    char ** palabras= separarPalabras(normalizada,numPal);

    mostrarPalabras(palabras, numPal);

    delete [] frase;
    frase = nullptr;

    delete [] normalizada;
    normalizada = nullptr;

    liberarMemoria(palabras, numPal);
    palabras = nullptr;
    
    return 0;
}
