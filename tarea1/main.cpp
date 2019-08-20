#include <iostream>
#include <string>
using namespace std;
void vuelto(double num){
//    double num=1750.20;
    double arr[]={200,100,50,20,10,5,2,1,0.50,0.20,0.1};
    for(int i=0;i<=1;i++){
           num=num/arr[i];
           cout<< num <<endl;
    }
}

void letras(long long int numero){
    string unidades[]={"","uno","dos ","tres ","cuatro ","cinco ","seis ","siete ","ocho ","nueve "};
    string unidadesAux[]={"","un ","dos ","tres ","cuatro ","cinco ","seis ","siete ","ocho ","nueve "};
    string decenas[]={"","dies y ","veinti","treinta y ","cuarenta y ","cincuenta y ","secenta y ","setenta y ","ochenta y ","noventa y "};
    string centenas[]={"","ciento ","dos cientos ","tres cientos ","cuatro cientos ","quinientos ","seis cientos ","setecientos ","ocho cientos ","novecientos "};
    int arr[10]={};
    long long int auxnumero=numero;
    for(int i=0;i<10;i++){
        int copia=numero%10;
         arr[i]=copia;
            cout<<copia<<endl;
            numero/=10;
    }
        string numeroL[10]={};
        numeroL[0]=unidadesAux[arr[9]]+"mil millones ";
        numeroL[1]=centenas[arr[8]];
        numeroL[2]=decenas[arr[7]];
        numeroL[3]=unidades[arr[6]]+ "millones ";
        numeroL[4]=centenas[arr[5]];
        numeroL[5]=decenas[arr[4]];
        numeroL[6]=unidadesAux[arr[3]]+ "mil ";
        numeroL[7]=centenas[arr[2]];
        numeroL[8]=decenas[arr[1]];
        numeroL[9]=unidades[arr[0]];

        if((arr[1]==1)&&(arr[0]!=0)){
           numeroL[9]="";
           string decenasAux[]={"","once","doce","trece","catorce","quince"};
           numeroL[8]=decenasAux[arr[0]];
            cout<<"copia1"<<endl;

        }

        if((arr[0]==0)){
           numeroL[9]="";
           string decenasAux1[]={"","dies ","veinte ","treinta ","cuarenta ","cincuenta ","sesenta ","setenta ","ochenta ","noventa "};
           numeroL[8]=decenasAux1[arr[1]];
 cout<<"copia2"<<endl;
        }

        if((arr[0]==0)&&(arr[1]==0)){
           numeroL[7]="cien ";
            cout<<"copia3"<<endl;
        }

           if((arr[4]==1)&&(arr[3]!=0)){
           numeroL[6]="";
           string decenasMilAux[]={"","once ","doce ","trece ","catorce ","quince "};
           numeroL[5]=decenasMilAux[arr[3]]+"mil ";
        }

         if((arr[3]==0)){
           numeroL[5]="";
           string decenasMilAux[]={"","dies ","veinte ","treinta ","cuarenta ","cincuenta ","sesenta ","setenta ","ochenta ","noventa "};
           numeroL[5]=decenasMilAux[arr[4]];
        }


        if((arr[3]==0)&&(arr[4]==0)&&(arr[5]==1)){
           numeroL[4]="cien ";
        }
        else if ((arr[4]==0)&&(arr[5]==1)&&(arr[3]==1)){
                numeroL[6]="";
           numeroL[4]="ciento un mil ";
        }
        /*if((arr[4]==0)&&(arr[3]!=1)){
        numeroL[5]="";
           numeroL[5]=unidades[arr[3]]+ "mil";
            cout<<"copia8"<<endl;
        }*/

        if((arr[3]==1)&&(arr[4]==0)&&(arr[5]==0)){
           numeroL[6]="mil ";

        }

        if((arr[6]==1)){
           numeroL[3]="un millon ";
        }

          if((arr[7]==1)&&(arr[6]!=0)){
           numeroL[3]="";
           string decenasMilAux[]={"","once ","doce ","trece ","catorce ","quince "};
           numeroL[2]=decenasMilAux[arr[6]]+"millones ";

        }


         if((arr[6]==0)&&(arr[7]!=0)){
           numeroL[2]="";
           string decenasMilAux[]={"","dies ","veinte ","treinta ","cuarenta ","cincuenta ","sesenta ","setenta ","ochenta ","noventa "};
           numeroL[2]=decenasMilAux[arr[7]];

        }
        if((arr[6]==0)&&(arr[7]==0)&&(arr[8]==1)){
           numeroL[1]="cien ";

        }
        else if((arr[7]==0)&&(arr[8]==1)&&(arr[6]==1)){
           numeroL[1]="ciento un ";

        }



        if (auxnumero<1000){
            for(int i=7;i<10;i++){
                cout<<numeroL[i];
           }
        }
        else if (auxnumero<1000000){
            for(int i=4;i<10;i++){
                cout<<numeroL[i];
           }
        }
        else if (auxnumero<1000000000){
            for(int i=1;i<10;i++){
                cout<<numeroL[i];
           }
        }
        else {
            for(int i=0;i<10;i++){
                cout<<numeroL[i];
           }
        }




}
int main()
{
   letras(8856897721);
    return 0;
}
