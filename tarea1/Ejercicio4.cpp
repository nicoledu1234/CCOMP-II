#include <iostream>
#include <string>
using namespace std;

int lenString(string numRomano){
    int contador=0;
    for(int i=0;numRomano[i]!='\0';i++,contador++);
    return contador;
}

int buscador(string simbolo, char c){
    for (int i=0;i< lenString(simbolo);i++){
        if(simbolo[i]==c){
            return i;
        }
    }
}
void convertirADecimal (string numRomano){
    int valor[] = {1000, 500, 100, 50, 10, 5, 1};
    string simbolo = "MDCLXVI";
    char c;
    int resultado=0;
    int i=0;
    int j=0;
    int ultimovalor=0;
    bool valido=true;
    while(valido && (i < lenString(numRomano))){
        c = numRomano[i];
        j = buscador(simbolo,c);
        if(j>=0){
            resultado += valor[j];
            if(valor[j] > ultimovalor){
                resultado -= 2 * ultimovalor;
            }
            ultimovalor = valor[j];
        }
        else{
            valido = false;
            resultado = -1;
        }
        i++;
    }
     cout<<resultado<<endl;
}

int main()
{
    string  numeroRomano;
    cout<<"Ingrese un numero Romano"<<endl;
    cin>>numeroRomano;
    convertirADecimal(numeroRomano);
    cout<<"Su valor en decimal es: ";
    return 0;
}
