#include <iostream>
#include <cmath>

using namespace std;

float suma_argumentow(int n, float T[])
{
    float suma=0;
    for(int i=0; i<n; i++)
    {
        suma+=T[i];
    }

    return suma;
}

float suma_wartosci(int n, float T[])
{
    float suma=0;
    for(int i=0; i<n; i++)
    {
        suma+=T[i];
    }

    return suma;
}

float suma_iloczynu_argumentow_i_wartosci(int n, float T1[], float T2[])
{
    float suma=0;
    for(int i=0; i<n; i++)
    {
        suma+=T1[i]*T2[i];
    }

    return suma;
}

float kwadrat_sumy_argumentow(int n, float T[])
{
    float suma=0;
    for(int i=0; i<n; i++)
    {
        suma+=T[i];
    }

    return pow(suma,2);
}

float suma_kwadratow_argumentow(int n, float T[])
{
    float suma=0;
    for(int i=0; i<n; i++)
    {
        suma+=pow(T[i],2);
    }

    return suma;
}

float suma_kwadratow_wartosci(int n, float T[])
{
    float suma=0;
    for(int i=0; i<n; i++)
    {
        suma+=pow(T[i],2);
    }

    return suma;
}

float wspolczynnik_a(int n, float T1[], float T2[])
{
    float a=(suma_argumentow(n, T1)*suma_wartosci(n, T2)-n*suma_iloczynu_argumentow_i_wartosci(n, T1, T2))/(kwadrat_sumy_argumentow(n, T1)-n*suma_kwadratow_argumentow(n, T1));

    return a;
}

float wspolczynnik_b(int n, float T1[], float T2[])
{
    float b=(suma_argumentow(n,T1)*suma_iloczynu_argumentow_i_wartosci(n,T1,T2)-suma_wartosci(n,T2)*suma_kwadratow_argumentow(n,T1))/(kwadrat_sumy_argumentow(n,T1)-n*suma_kwadratow_argumentow(n,T1));

    return b;
}

float srednia_argumentow(int n, float T[])
{
    float srednia=0;
    for(int i=0; i<n; i++)
    {
        srednia+=T[i]/n;
    }

    return srednia;
}

float srednia_wartosci(int n, float T[])
{
    float srednia=0;
    for(int i=0; i<n; i++)
    {
        srednia+=T[i]/n;
    }

    return srednia;
}

float kwadrat_sumy_iloczynu_roznicy_argumentu_i_sredniej_argumentow_oraz_roznicy_wartosci_i_sredniej_wartosci(int n, float T1[], float T2[])
{
    float suma=0;
    for(int i=0; i<n; i++)
    {
        suma+=(T1[i]-srednia_argumentow(n,T1))*(T2[i]-srednia_wartosci(n,T2));
    }

    return pow(suma,2);
}

float suma_kwadratow_roznicy_argumentu_i_sredniej_argumentow(int n, float T[])
{
    float suma=0;
    for(int i=0; i<n; i++)
    {
        suma+=pow(T[i]-srednia_argumentow(n,T),2);
    }

    return suma;
}

float suma_kwadratow_roznicy_wartosci_i_sredniej_wartosci(int n, float T[])
{
    float suma=0;
    for(int i=0; i<n; i++)
    {
        suma+=pow(T[i]-srednia_wartosci(n,T),2);
    }

    return suma;
}

float wspolczynnik_korelacji(int n, float T1[], float T2[])
{
    float R2=kwadrat_sumy_iloczynu_roznicy_argumentu_i_sredniej_argumentow_oraz_roznicy_wartosci_i_sredniej_wartosci(n,T1,T2)/(suma_kwadratow_roznicy_argumentu_i_sredniej_argumentow(n,T1)*suma_kwadratow_roznicy_wartosci_i_sredniej_wartosci(n,T2));

    return R2;
}

void wywolaj(void)
{
        cout<<"WYZNACZANIE REGRESJI LINIOWEJ METODA NAJMNIEJSZYCH KWADRATOW GAUSSA"<<endl<<endl;
    int n;

    cout<<"Wprowadz ilosc dokonanych pomiarow (argumentow/wartosci): ";
    cin>>n;


//Argumenty
    cout<<endl;
    float *Targ=new float[n];
    cout<<"Wprowadz wartosci kolejnych argumentow x do tablicy: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"Wprowadz wartosc argumentu Targ["<<i<<"]: ";
        cin>>Targ[i];
    }

//Wartosci
    cout<<endl;
    float *Twar=new float[n];
    cout<<"Wprowadz wartosci kolejnych wartosci y do tablicy: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"Wprowadz wartosc wartosci Twar["<<i<<"]: ";
        cin>>Twar[i];
    }


    cout<<endl<<endl;
    cout<<"Prosta, ktora jest aproksymacja podanych argumentow i wartosci ma postac: ";
    if(wspolczynnik_b(n,Targ,Twar)>0)
    {
        cout<<"y = "<<wspolczynnik_a(n,Targ,Twar)<<"x + "<<wspolczynnik_b(n,Targ,Twar)<<endl;
    }
    else if(wspolczynnik_b(n,Targ,Twar)<0)
    {
       cout<<"y = "<<wspolczynnik_a(n,Targ,Twar)<<"x "<<wspolczynnik_b(n,Targ,Twar)<<endl;
    }
    else
    {
        cout<<"y = "<<wspolczynnik_a(n,Targ,Twar)<<"x"<<endl;
    }

    cout<<endl<<"Wspolczynnik a prostej ma wartosc: "<<wspolczynnik_a(n,Targ,Twar)<< " [jednostka y/jednostka x]"<<endl;
    cout<<endl<<"Wspolczynnik b prostej ma wartosc: "<<wspolczynnik_b(n,Targ,Twar)<< " [jednostka y]"<<endl;
    cout<<endl<<"Wspolczynnik korelacji R^2 ma wartosc: "<<wspolczynnik_korelacji(n,Targ,Twar)<< " [brak jednostki]"<<endl;
    cout<<"Wartosc wspolczynnika korelacji z zakresu <0;1>, gdzie 0 oznacza calkowita niezgodnosc badanych punktow z otrzymana prosta, a 1 oznacza calkowita zgodnosc badanych punktow z otrzymana prosta"<<endl;

    delete [] Targ;
    delete [] Twar;
}



int main(void)
{
    wywolaj();
    return 0;
}
