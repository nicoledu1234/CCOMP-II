#include <iostream>

using namespace std;

void vuelto(float var){

    int entero= static_cast<int>(var);
    float decimalFloat= var*10;
    int decimal=decimalFloat-(entero*10);

    int billetes[]={200,100,50,20,10,5,2,1};
    int centimos[]={5,2,1};
    string arr[]={" moneda de "," monedas de "};
    string arr1[]={" billete de "," billetes de "};
    for(int i=0;i<=7;i++){
        int temporal=entero/billetes[i];
        if(temporal==1){
            if(i>=4){
                cout<< temporal << arr[0]<< billetes[i]<<endl;
            }
            else {
                cout<< temporal << arr1[0]<< billetes[i]<<endl;
            }
        }
        else{
            if(i>=4){
                cout<< temporal << arr[1]<< billetes[i]<<endl;
            }
            else {
                cout<< temporal << arr1[1]<< billetes[i] <<endl;}
        }
        entero= entero%billetes[i];
    }

    for(int i=0;i<=2;i++){
        int temporalCentimos=decimal/centimos[i];
        if(temporalCentimos==1){
            cout<< temporalCentimos << arr[0]<< "0."<< centimos[i]<<endl;
        }
        else{
            cout<< temporalCentimos << arr[1]<< "0."<< centimos[i]<<endl;
        }
        decimal=decimal%centimos[i];
    }
}
int main(){
    cout<<"Ingresa un numero decimal"<<endl;
    float a;
    cin>>a;
    vuelto(a);
}
