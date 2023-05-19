//Espinosa Razo Uriel Alejandro
//Gutierrez Prats Hervey Gabriel
//Mota Correa Marco Antonio
//Zetina Hernandez Issac

#include <iostream>
#include <cmath>

using namespace std;

float reglaSimp(float a, float b,float n);
float sumaE(float a, float b,float n,float deltaX);
double ecuacion(double x);
double ErrorSimp(double x,float a, float b);
double Derivada4(double  x, double (*f)(double));

//--------------------Main-----------------------------------------------------------------

int main(){

    float a,b,result,err;
    double x=-1;
    cout<<"Ingrese los valores de a,b y n para la integral de f(x)=e^(-x^2)"<<endl;
    cout<<"Cual sera el valor de a: ";
    cin>>a;
    cout<<"Cual sera el valor de b: ";
    cin>>b;
    err=ErrorSimp(x,a,b);
    cout<<"Para que el error sea el deseado se debe partir en: "<<err;
    result=reglaSimp(a,b,err);
    cout<<"\t\t\t\t\t\t  "<<b<<endl;
    cout<<"Resultado de regla de Simpson para la integral de ?e^(-x^2)dx: "<<result<<endl;
    cout<<"\t\t\t\t\t\t  "<<a<<endl;
    return 0;
}

//--------------------Regla de Simpson-----------------------------------------------------------------
float reglaSimp(float a, float b,float n){
    float deltaX,Sn;
    deltaX = (b-a)/n;
    cout<<"\ndelta x: "<<b-a<<"/"<<n;
    cout<<"\t\tXi: "<<a<<"+i("<<b-a<<"/"<<n<<")"<<endl;
    cout<<"\n";
    Sn= (deltaX/3)*(sumaE(a,b,n,deltaX));

    return Sn;
}

//--------------------Suma de los valores (Sn)-----------------------------------------------------------------
float sumaE(float a, float b,float n,float deltaX){
    double suma = 0;

    for(int i = 0; i < n+1; i++){
        if(i == 0 || i == n){
            suma += 1/exp(pow(a+(i*deltaX),2));
        }else if((i+1) % 2 == 0){
            suma += 4/exp(pow(a+(i*deltaX),2));
        }else{
            suma += 2/exp(pow(a+(i*deltaX),2));
        }
    }
    return suma;

}

//--------------------Error de Simpson-----------------------------------------------------------------
double ecuacion(double x){
  return (16*pow(x,4)-48*pow(x,2)+12)/exp(pow(x,2));
}

double ErrorSimp(double x,float a, float b)
{
    double k;
    float error,err;
    cout<<"De cuanto quiere que sea su error?"<<endl;
    cin>>err;
    k=ecuacion(x);
    k=abs(k);
    error=pow((k*pow((b-a),2))/(err*180),0.25);
    error = ceil(error);
    return error;
}
