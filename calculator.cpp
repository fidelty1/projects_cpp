#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double a;
    double n;
    string koniec;
    int dzialanie;
    int silnia=1;
    double dzeta=1;

 cout<<"Podaj zmiena poczatkowa (a):"<<endl;
 cin>>a;

 BEGIN:
     cout<<endl;
    cout << "Podaj jakie dzialanie chcialbys wykonac: 1-dodawanie, 2-odejmowanie, 3-mnozenie, 4-dzielenie, 5-wartosc_bezwzgledna, 6-potegowanie, 7-pierwiastkowanie, 8-przyblizenie, 9-sinus, 10-cosinus, 11-tangens, 12-cotangens, 13-silnia, 14-logarytm_naturalny, 15-funkcja_dzeta_Riemanna_dla_zm_real(x=a)"<< endl;
    cin>>dzialanie;
        if (dzialanie==1)
        {
        cout<<"ile chcesz dodac:"<<endl;
        cin>>n;
        a=a+n;
        cout<<"Wynik jest rowny: "<<a;
        cout<<endl;
        }

        if (dzialanie==2)
        {
        cout<<"ile chcesz odjac:"<<endl;
        cin>>n;
        a=a-n;
        cout<<"Wynik jest rowny: "<<a;
        cout<<endl;
        }

        if (dzialanie==3)
        {
        cout<<"ile razy chcesz pomnozyc:"<<endl;
        cin>>n;
        a=a*n;
        cout<<"Wynik jest rowny: "<<a;
        cout<<endl;
        }

        if (dzialanie==4)
        {
        cout<<"ile razy chcesz podzielic:"<<endl;
        cin>>n;
        a=a/n;
        cout<<"Wynik jest rowny: "<<a;
        cout<<endl;
        }

        if (dzialanie==5)
        {
        a=abs(a);
        cout<<"Wynik jest rowny: "<<a;
        cout<<endl;
        }

        if (dzialanie==6)
        {
        cout<<"podaj wykladnik potegi:"<<endl;
        cin>>n;
        a=pow(a,n);
        cout<<"Wynik jest rowny: "<<a;
        cout<<endl;
        }

        if (dzialanie==7)
        {
        cout<<"podaj stopien pierwiastka:"<<endl;
        cin>>n;
        a=pow(a, (1/n));
        cout<<"Wynik jest rowny: "<<a;
        cout<<endl;
        }

        if (dzialanie==8)
        {
        cout<<"Podaj: 1-w gore, 2-w dol, 3-zgodnie z zasadami"<<endl;
        cin>>n;

        if (n==1)
            {
        a=ceil(a);
        cout<<"Wynik jest rowny: "<<a;
        cout<<endl;
            }

            if (n==2)
            {
        a=floor(a);
        cout<<"Wynik jest rowny: "<<a;
        cout<<endl;
            }

            if (n==3)
            {
        a=round(a);
        cout<<"Wynik jest rowny: "<<a;
        cout<<endl;
            }
        }


         if (dzialanie==9)
        {
        a=sin(a);
        cout<<"Wynik jest rowny: "<<a;
        cout<<endl;
        }

          if (dzialanie==10)
        {
        a=cos(a);
        cout<<"Wynik jest rowny: "<<a;
        cout<<endl;
        }

        if (dzialanie==11)
        {
        a=tan(a);
        cout<<"Wynik jest rowny: "<<a;
        cout<<endl;
        }

        if (dzialanie==12)
        {
        a=(1/tan(a));
        cout<<"Wynik jest rowny: "<<a;
        cout<<endl;
        }

         if (dzialanie==13)
        {

        for(int j=a; j>1; j--)
        silnia=silnia*j;
        cout<<"Wynik jest rowny: "<<silnia;
        a=silnia;
        cout<<endl;
        }

        if (dzialanie==14)
        {
        a=log(a);
        cout<<"Wynik jest rowny: "<<a;
        cout<<endl;
        }

         if (dzialanie==15)
        {
            double liczba=a;
        for (int k=0; k<100000; k++){

            int b=2+k;
        dzeta=dzeta+(1/pow(b,liczba));
        }
        if(a>1)
        a=dzeta;
        else
            a=(1.0/0);
        cout<<"Wynik jest rowny: "<<a;
        cout<<endl;
        }

 cout<<"Czy chcesz wykonac nastepe dzialanie?/n Wpisz t/n (tak lub nie): "<<endl;
 cin>>koniec;

 if (koniec=="n" || koniec=="nie")
 cout<<"Wynik ostateczny wynosi: "<<a<<endl;
else
    goto BEGIN;

    return 0;
}
