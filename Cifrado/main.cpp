#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
string alfabeto="abcdefghijklmnopqrstuvwxyz0123456789/ ";
string claveG="";
void cifrado(string texto){
    string mensaje;
    string copia;
    ifstream entrada ( texto);
    ofstream salida ("textoCifrado.txt");
    while (getline (entrada,copia)) {
        string temp=copia;
        mensaje.append(copia);
        mensaje.push_back('/');
    }
    int tam=mensaje.length();
    string clave="";
    srand(time(NULL));
    int i, aleatorio, DESDE=0, HASTA=alfabeto.length();
    for (i = 0; i < tam; i ++){
        aleatorio = rand()%(HASTA-DESDE+1)+DESDE;
        clave.push_back(alfabeto.at(aleatorio));
    }
    claveG=clave;
    cout<< "clave "<<clave<<endl;
    for (int i=0 ; i< tam;i++){
        int m=alfabeto.find(mensaje.at(i));
        int c=alfabeto.find(clave.at(i));
        int sumaT=(m+c)%38;
        mensaje.at(i)=alfabeto.at(sumaT);
    }
    cout<<"mensaje "<<mensaje<<endl;
    salida << mensaje << endl;
    salida.close();
    entrada.close();
}
void descifrado(string texto, string clave){
    string mensaje1;
    string copia1;
    ifstream entrada1( texto);
    ofstream salida1 ("textoDescifrado.txt");
    while (getline (entrada1,copia1)) {
        string temp=copia1;
        cout<<"copia "<<copia1<<endl;
        mensaje1.append(copia1);
    }
    int tam=mensaje1.length();
    for (int i=0 ; i< tam;i++){
        int m=alfabeto.find(mensaje1.at(i));
        int c=alfabeto.find(clave.at(i));
        int restaT=(m-c)%38;
        if(restaT<0){
            restaT = (38 + restaT)%38;
        }
        mensaje1.at(i)=alfabeto.at(restaT);
    }
    cout<<"mensaje "<<mensaje1<<endl;
    for (int i=0;i<tam;i++){
        if(mensaje1.at(i)=='/'){
            salida1<<endl;
        }
        else{
            salida1 << mensaje1[i];
        }
    }
    salida1.close();
    entrada1.close();
}
int main()
{

    cifrado("textoPlano.txt" );
    descifrado("textoCifrado.txt",claveG);
    return 0;
}
