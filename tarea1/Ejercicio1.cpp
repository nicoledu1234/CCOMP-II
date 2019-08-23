#include <iostream>
#include <string>
using namespace std;
void vuelto(double numero){
double billetes[]={200,100,50,20,10,5,2,1,0.50,0.20,0.10};
    string arr[]={" moneda de "," monedas de "};
    string arr1[]={" billete de "," billetes de "};
    for(int i=0;i<=10;i++){
        int temporal=numero/billetes[i];
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
            numero=numero-temporal*billetes[i];
        }
}
int main()
{
    vuelto(1750.20);
    return 0;
}
