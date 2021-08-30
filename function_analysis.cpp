#include <iostream> //biblioteka podstawowych funkcji w c++
#include <cmath> //biblioteka funkcji dzialan matematycznych
#include <complex> //biblioteka obslugujaca liczby zespolone

using namespace std;

int main()
{
    double a; //deklaruje stala przy x^2
    double b; //deklaruje stala przy x
    double c; //deklaruje stala
    double x; //miejsce zerowe rownania liniowego
    double x0; //miejsce zerowe dla delty=0
    double x1; //pierwsze miejsce zerowe dla delty
    double x2; //drugie miejsce zerowe dla delty
    double delta;

    cout << "Podaj wspolczynnik a rownania:" << endl;
    cin>>a;
    cout << "Podaj wspolczynnik b rownania:" << endl;
    cin>>b;
    cout << "Podaj wspolczynnik c rownania:" << endl;
    cin>>c;
    //teraz obliczam poszczegolne zmienne zgodnie z regulami matematycznymi:
    x=-c/b;
    x0=-b/(2*a);
    delta=pow(b,2)-4*a*c;
    x1=(-b-sqrt(delta))/(2*a);
    x2=(-b+sqrt(delta))/(2*a);
    complex<double> z1((-b/(2*a)),-sqrt(abs(delta))/(2*a));
    complex<double> z2((-b/(2*a)),+sqrt(abs(delta))/(2*a));


    cout<<"Wprowadzone przez Ciebie rownanie ma postac: f(x) = "<<a<<"x^2 + "<<b<<"x + "<<c<<endl;

    if(a==0 && b==0 && c==0) //sprawdzam funkcje typu f(x)=c=0
         cout<<"Jest to funkcja stala w calym zbiorze liczb rzeczywistych. Jej miejscem zerowym jest kazda liczba rzeczywista."<<endl;
    else if(a==0 && b==0 && c!=0) //sprawdzam funkcje typu f(x)=c
        cout<<"Jest to funkcja stala w calym zbiorze liczb rzeczywistych. Nie posiada ona miejsc zerowych."<<endl;
    else if (a==0 && b!=0) //sprawdzam funkcje typu f(x)=bx+c
        cout<<"To jest rownanie liniowe. Niewiadoma x jest rowna x= "<<x<<endl;
    else //sprawdzam funkcje typu f(x)=ax^2+bx+c o niezerowych wspolczynnikach
        {
        if (delta>0) //sprawdzam przypadek dla delty wiekszej od 0
        cout<<"To jest rownanie kwadratowe. Ma ono dwa pierwiastki rzeczywiste rowne x1= "<<x1<<" oraz x2="<<" "<< x2<<endl;
        else if (delta==0) //sprawdzam przypadek dla delty rownej zero
        cout<<"To jest rownanie kwadratowe. Ma ono jeden pierwiastek rzeczywisty podwojny rowny x0= "<<x0<<endl;
        else //sprawdzam przypadek dla delty mniejszej od 0
            {
            if(z1.real()==0) //jezeli czesc rzeczywista jest rowna 0 to pozbywam sie zbednego -0 (-0+/-...i) z przodu
            cout<<"To jest rownanie kwadratowe. Nie ma ono zadnych pierwiastkow rzeczywistych. Ma ono natomiast dwa pierwiastki zespolone rowne: z1= "<<z1.imag()<<"i"<<" oraz z2= "<<z2.imag()<<"i"<<endl;
            else //jezeli nie ma -0 z przodu to podaje miejsca zerowe z czescia rzeczywista i urojana
                {
                if (z1.imag()>0) //gdy przy czesci urojonej w z2 stoi minus pozbywam sie zbednego plusa (z2=...+-...i)
                cout<<"To jest rownanie kwadratowe. Nie ma ono zadnych pierwiastkow rzeczywistych. Ma ono natomiast dwa pierwiastki zespolone rowne: z1= "<<z1.real()<<"+"<<z1.imag()<<"i"<<" oraz z2= "<<z2.real()<<z2.imag()<<"i"<<endl;
                else //gdy przy czesci urojonej w z1 stoi minus pozbywam sie zbednego plusa (z1=...+-...i)
                cout<<"To jest rownanie kwadratowe. Nie ma ono zadnych pierwiastkow rzeczywistych. Ma ono natomiast dwa pierwiastki zespolone rowne: z1= "<<z1.real()<<z1.imag()<<"i"<<" oraz z2= "<<z2.real()<<"+"<<z2.imag()<<"i"<<endl;
                }
            }
        }
    return 0;
}
