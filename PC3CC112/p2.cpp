#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void tominus(char*token){
    while (*token!='\0')
    {
        if(*token>='A'&&*token<='Z'){
            *token=*token+32;
        }
        token++;
    }
    
}


int vocales(char*texto){
    int i=0;
    char * token = strtok(texto," ");
    while (token!=nullptr)
    {
        tominus(token);
        if (*token == 'a'||*token == 'e'||*token == 'i'||*token == 'o'||*token == 'u')
        {
            i++;
        }
        
        token=strtok(nullptr," ");
    }
    
return i;

}

int main()
{
    char texto[]="    Este es   un ejemplo en C++  END";
    cout<<texto<<endl;
    cout<<"Numero de palabras que empiezan con vocal: "<<vocales(texto)<<endl;
    return 0;
}


