#include <iostream>
#include <string>
using namespace std;
bool  verificarNumero(string numRomano){
    int cant1=0;
    int cant5=0;
    int cant10=0;
    int cant50=0;
    int cant100=0;
    int cant500=0;
    int cant1000=0;
    for (int i = 0; i <numRomano.length() ; ++i) {
        if (numRomano[i]=='I') {
            cant1++;
        }
        else if (numRomano[i]=='V') {
            cant5++;
        }
        else if (numRomano[i]=='X') {
            cant10++;
        }
        else if (numRomano[i]=='L') {
            cant50++;
        }
        else if (numRomano[i]=='C') {
            cant100++;
        }
        else if (numRomano[i]=='D') {
            cant500++;
        }
        else if (numRomano[i]=='M') {
            cant1000++;
        }
    }
    if(cant1>3||cant10>3|| cant100>3|| cant1000>3){
        cout<<"Numero invalido "<<endl;
        return false;
    }
    if(cant5>=2||cant50>=2|| cant500>=2){
        cout<<"Numero invalido "<<endl;
        return false;
    }
    for (int i = 0; i < numRomano.length() ; ++i) {
       if(numRomano[i]=='I'){
           if (numRomano[i+1]=='L'||numRomano[i+1]=='C'||numRomano[i+1]=='D'||numRomano[i+1]=='M'){
            cout<<"Numero invalido "<<endl;
            return false;
           }
       }
    }

    return true;
}

int buscador(string simbolo, char c){
    for (int i=0;i< simbolo.length();i++){
        if(simbolo[i]==c){
            return i;
        }
    }
}
void convertirADecimal (string numRomano){
    if(verificarNumero(numRomano)==0){}
    else{
            int valor[] = {1000, 500, 100, 50, 10, 5, 1};
        string simbolo = "MDCLXVI";
        char c;
        int resultado=0;
        int i=0;
        int j=0;
        int ultimovalor=0;
        bool valido=true;
        while(valido && (i < numRomano.length())){
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
}

int main()
{
    string  numeroRomano;
    cout<<"Ingrese un numero Romano"<<endl;
    cin>>numeroRomano;
    cout<<"Su valor en decimal es: ";
    convertirADecimal(numeroRomano);
    return 0;
}
