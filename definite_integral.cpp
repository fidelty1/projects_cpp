#include <iostream>
#include <cmath>

using namespace std;

void wynik(float pole1, float pole2)//funkcja wypisujaca finalne wartosci
{
    cout<<"Pole pod wykresem funkcji metoda prostakatow ma wartosc: "<<pole1<<endl;
    cout<<"Pole pod wykresem funkcji metoda trapezow ma wartosc: "<<pole2<<endl;
}

float funkcja(float x)//fukcja zawierajaca funkcje matematyczna, ktora bedziemy calkowac
{
    float f;
   f=sqrt(25-pow(x,2))+x*sin(x); // <-- Tu wpisz funkcje, ktorej pole pod wykresem chcesz obliczyc
   return f;//zwraca wartosc funkcji matematycznej dla danego x
}

float metoda_prostokatow(float a, float b, int n)
{
    float m=(b-a)/n;//ustalamy dlugosc przedzialu m w zaleznosci od ilosci przedzialow n oraz wartosci skrajnych przedzialu a oraz b
    float x=a;//pierwszy x to poczatek przedzialu
    float suma=0;//na paczatek zerujemy zmienna suma

    while(x<b)//petla liczaca calke metoda prostakatow do momentu osiagniecia kanca przedzialu
    {
        suma+=(m*abs(funkcja(x+(m/2))));//zwiekszamy sume o kolejne prostakaty. Ustalamy wysokosc prastakata dla wartosci funkcji w srodku przedzialu m i mnozymy przez dlugosc przedzialu (wzor na pole prostakata)
        x=x+m;//przeskakujemy o jeden przedzial dalej
    }

    return suma;//zwracamy wartosc calki metoda prostokatow
}

float metoda_trapezow(float a, float b, int n)
{
    float m=(b-a)/n;//j.w.
    float x=a;//j.w.
    float suma=0;//j.w.

    while(x<b)//petla liczaca calke metoda trapezow do momentu osiagniecia kanca przedzialu
    {
        suma+=(0.5*(abs(funkcja(x))+abs(funkcja(x+m)))*m);//zwiekszamy sume o kolejne trapezy. Liczymy pole trapezow dla wartosci funkcji zgodnie ze wzorem na pole trapezu: 1/2 * (a+b)*h
        x=x+m;//j.w.
    }

    return suma;//zwracamy wartosc calki metoda trapezow
}

int main()
{
    float a;//dolna granica calkowania
    float b;//gorna granica calkowania
    int n;
    cout << "Program obliczajacy pole pod wykresem funkcji metoda prostakantow. Funkcje mozesz zmienic na dowolna w kodzie programu w funkcji zewnetrznej o nazwie ''fukcja''" << endl;
    cout<<"Wprowadz dolna granice calkowania:"<<endl;
    cin>>a;
    cout<<"Wprowadz gorna granice calkowania:"<<endl;
    cin>>b;
    cout<<"Podaj, na ile przedzialow chcesz podzielic funkcje (im wieksza wartosc, tym dokladniejsza calka):"<<endl;
    cin>>n;

    wynik(metoda_prostokatow(a, b, n), metoda_trapezow(a, b, n));//wywoluje funkcje wypisania wyniku (program strukturalny)
    return 0;
}
