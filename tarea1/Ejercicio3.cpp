#include<iostream>
#include <string>
using namespace std;

string meses(int mes){
    string nombresMeses[]={"","Enero","Febrero","Marzo",  "Abril", "Mayo", "Junio",  "Julio", "Agosto", "Septiembre", "Octubre ",  "Noviembre","Diciembre"};
    if(mes>12){
        return 0;
    }
    return nombresMeses[mes];
}

int algoritmoZeller(int a, int mes){
    int A =(14-mes)/12;
    int y= a-A;
    int m= mes+12 * A-2;
    int dia =1,d;
    d=(dia + y+y / 4-y /100+ y/ 400+(31*m)/12)%7;
    return d;
}

bool esBisiesto(int a){
    if((a%4==0 && a%100!=0) || a%400==0){
        return true;
    }
    return false;
}

int diasMeses(int a,int mes){
    if (mes==1 or mes==3 or mes==5 or mes==7 or mes==10 or mes==12){
        return 31;
    }
    if (mes==2){
        if (esBisiesto(a)){
            return 29;
        }
        return 28;
    }
    return 30;
}


void calendario(int a,int mm){
    cout<<"Año: "<< a <<endl;
    cout<<"Mes: "<< meses(mm)<<endl;
    cout<<"Do  Lu  Ma  Mi  Ju  Vi  Sa"<<endl;
    int z=algoritmoZeller(a, mm);
    for (int i=0;i<z;i++){
        cout<<"    ";
    }
    int diasMes = diasMeses(a, mm);
    for (int dia=1; dia <=diasMes;dia++){
        if (dia >=10){
            cout<<dia<<"  ";
        }
        else{
            cout<<dia<<"   ";
        }
        z++;
        if (z % 7==0){
            cout<<endl;
        }
    }
    cout<<endl;
}

int main(){
    int aa;
    cout<<"Ingrese un año"<<endl;
    cin>>aa;
    int mm;
    cout<<"Ingrese un mes"<<endl;
    cin>>mm;
    calendario(aa,mm);
}
