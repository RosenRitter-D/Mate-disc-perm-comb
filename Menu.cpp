#include <iostream>
#include <windows.h>
#include <cmath>//Esta libreria la use para redirigir un mensaje de error al usuario en caso de que el resultado de su operacion sea NAN 

using namespace std;

int factorial(int n);
int regresar();
int salir();
int permutacionesSinRepeticion();
int permutacionesConRepetcion();
int permutacionesDeSubConjuntosDivididos();
int PermutacionesCirculares();
int combinacionesSinRepeticion();
int combinacionesConRepeticion();

int menuPrincipal,regr,mPer,mCom;

int main(){
    system("cls");
    cout<<"Bienvenido, este programa calcula permutaciones y combinaciones\n";
    cout<<"Presione 1 si desea calcular Permutaciones.\nPresione 2 para calcular combinaciones\nPresione 3 para salir\n";
    cin>>menuPrincipal;
    switch (menuPrincipal)
        {
        case 1://Permutaciones
            system("cls");
            cout<<"Ha elegido permutaciones\n";
            cout<<"Presione 1 para permutaciones sin repeticion\n";
            cout<<"Presione 2 para permutaciones con repeticion\n";
            cout<<"Presione 3 para permutaciones en subconjuntos divididos\n";
            cout<<"Presione 4 para permutaciones circulares\n";
            cout<<"Presione 5 para volver al menu principal\n";
            cin>>mPer;
                switch (mPer)
                {
                    case 1:
                        permutacionesSinRepeticion();
                        regresar();
                    break;
        
                    case 2:
                        permutacionesConRepetcion();
                        regresar();
                    break;
                    case 3:
                        permutacionesDeSubConjuntosDivididos();
                        regresar();
                    break;
                    case 4:
                        PermutacionesCirculares();
                        regresar();
                    break;
                    case 5:
                        main();
                    break;
                }
        break;
    
        case 2://Combinaciones
            system("cls");
            cout<<"Ha elegido Combinaciones\n";
            cout<<"Presione 1 para combinaciones sin repeticion\n";
            cout<<"Presione 2 para combinaciones con repeticion\n";
            cin>>mCom;
                switch (mCom)
                {
                    case 1:
                        combinacionesSinRepeticion();
                        regresar();
                    break;
        
                    case 2:
                        combinacionesConRepeticion();
                        regresar();
                    break;
        break;
        }
        case 3://sarir
            salir();
        break;
}       
}

int regresar(){ //Funcion que regresa desde los submenus   
    cout<<"\nPresione 1 para regresar al menu principal, o cualquier otro numero si desea salir\n";
    cin>>regr;        
        if (regr==1){
            main();
                    }
        else{
            salir();
            return 0;
            }
}
//-----------------------------------------------------------------------------------------------------------------
//Salir 
int salir(){
    system("cls");
    cout<<"Ha seleccionado Salir...\nQue tenga un feliz dia\n";
    for(int i=0; i<=50; i++){
        cout<<"==";
        Sleep(10);
    }
    cout<<endl;
    system("cls");
    exit(1);
}
//--------------------------------------------------------------------------------------------------------------------------
int factorial(int f) {
   if(f < 0) return 0;
   else if(f > 1) return f*factorial(f-1);
   return 1;
}
//--------------------------------------------------------------------------------------------------------------------------
int permutacionesSinRepeticion(){
    system("cls");
    float n,k,N,K,Div,div,R;
    cout<<"Ha elegido permutaciones sin repeticion\n";
    cout<<"Ingrese los Valores de n y k\n";
    cout<<"N: ";cin>>n;
    cout<<"K: ";cin>>k;
    Div=(n-k);
    N=factorial(n);
    div=factorial(Div);
    R=N/div;
    if(isnan(R)||R==INFINITY){ //Todo lo referente a los valores nan e inf lo encontre en este articulo: https://www.geeksforgeeks.org/nan-in-cpp-what-is-it-and-how-to-check-for-it/  y en este https://c.dokry.com/6215/cual-es-el-resultado-de-convertir-float-inf-inf-y-nan-a-entero-en-c.html                      
        cout<<"Error Metematico\n";
    }
    else{ 
    cout<<"El resultado de la permutacion es: "<<R<<"\n";
    }
    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
int permutacionesConRepetcion(){
    system("cls");
    float n,k,R;
    cout<<"Ha elegido permutaciones con repeticion\n";
    cout<<"Ingrese los Valores de n y k\n";
    cout<<"N: ";cin>>n;
    cout<<"K: ";cin>>k;
    R=pow(n,k);
    if(isnan(R)||R==INFINITY){ //Todo lo referente a los valores nan e inf lo encontre en este articulo: https://www.geeksforgeeks.org/nan-in-cpp-what-is-it-and-how-to-check-for-it/  y en este https://c.dokry.com/6215/cual-es-el-resultado-de-convertir-float-inf-inf-y-nan-a-entero-en-c.html                      
        cout<<"Error Metematico\n";
    }
    else{ 
    cout<<"El resultado de la permutacion es: "<<R<<"\n";
    }
    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
int permutacionesDeSubConjuntosDivididos(){
    system("cls");
    int n,c,N,m=1,M,div;
    cout<<"Ha elegido permutaciones de subconjuntos divididos\n";
    cout<<"Ingrese el valor de n: ";cin>>n;
    cout<<"Ahora la cantidad de elementos para n1,n2...\nCantidad: ";
    cin>>c;
    int arreglo[c];
    
    N=factorial(n);
    for(int i=0; i<c; i++){
        cout<<"n"<<i+1<<": ";
        cin>>arreglo[i];
        m*=factorial(arreglo[i]);
    }
    div=N/m;
    if(isnan(div)||div==INFINITY){ 
        cout<<"Error Metematico\n";
    }
    else{ 
    cout<<"\nEl resultado de la permutacion es: "<<div;
    }
    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
int PermutacionesCirculares(){
    system("cls");
    int n,N,Nf;
    cout<<"Ha elegido permutaciones circulares\n";
    cout<<"Ingrese el valor de n: ";cin>>n;
    N=(n-1);
    Nf=factorial(N);
    cout<<"El valor de la permutacion es: "<<Nf<<"\n";
}
//--------------------------------------------------------------------------------------------------------------------------
int combinacionesSinRepeticion(){
    system("cls");
    int n,N,k,K,div,rs,RS;
    cout<<"Ha elegido Combinaciones sin Repetecion\n";
    cout<<"Ingrese los siguientes valores\nn: ";
    cin>>n;
    cout<<"k";cin>>k;
    rs=n-k;
    RS=factorial(rs);
    N=factorial(n);
    K=factorial(k);
    div=N/(K*RS);
    if(isnan(div)||div==INFINITY){ 
        cout<<"Error Metematico\n";
    }
    else{ 
    cout<<"El resultado de la combinacion es: "<<div<<"\n";
    }
    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
int combinacionesConRepeticion(){
    system("cls");
    int n,k,K,rsm,RSM,r,R,div;
    cout<<"Ha elegido Combinaciones con repeticion\n";
    cout<<"Ingrese los siguientes valores\nn: ";
    cin>>n;
    cout<<"k: ";cin>>k;
    rsm=(n+k)-1;
    r=n-1;
    RSM=factorial(rsm);
    R=factorial(r);
    K=factorial(k);
    div=RSM/(K*R);
    if(isnan(div)||div==INFINITY){ 
        cout<<"Error Metematico\n";
    }
    else{
        cout<<"El resultado de la combinacion es: "<<div<<"\n";
    }
    return 0;
}