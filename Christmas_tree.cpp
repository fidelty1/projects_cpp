#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    int a=0;
    cout<<"Christmas tree"<<endl; //program rysujacy drzewko choinkowe
    cout<<"Wprowadz szerokosc choinki (liczba wieksza lub rowna 7, nieparzysta, dajaca 1 przy dzieleniu przez 3):"<<endl; //warunki 1. >=7 - minimalna wielkosc drzewka wynosi 7; 2. nieparzystosc konieczna aby po srodku znajdowala sie pierwsza gwiazdka; 3. reszta z dzielenia aby choinka zachowała swoj ksztalt
    cin>>n;
    cout<<endl;

    cout<<setfill('*')<<setw(n)<<"*"<<setfill(' ')<<endl;//gorna rama z gwiazdek






        for(int j=0; j<3; j++)//trzy pietra korony drzewa
        {

        cout<<"*"<<setw(n/2)<<"*"<<setw(n/2)<<"*"<<endl;//pierwsza gwiazdka czubkowa zrobiona recznie
         a=0;

        for(int i=0; i<(n/2)-1; i++)//jedno z trzech pieter korony drzewa
        {
          cout<<"*"<<setfill(' ')<<setw((n/2)-(i+1))<<"*"<<setfill('*')<<setw(a+2)<<"*"<<setfill(' ')<<setw((n/2)-i-1)<<"*"<<endl;//funkcja na odstep-gwiazdki-odstep
            a++;
            a++;//a jest kolejna liczba parzysta co petle, poniewaz co petle potrzebne jest o 2 wiecej gwiazdek
        }
        }




        for(int i=0; i<(n/2)-1; i++)//pien drzewa
            cout<<"*"<<setfill(' ')<<setw(n/3)<<"*"<<setfill('*')<<setw(n/3)<<"*"<<setfill(' ')<<setw(n/3)<<"*"<<endl;//funkcja na pien drzewa stanowiaca 1/3 powierzchni odstep, 1/3 powierzchni gwiazdki, 1/3 powierzchni odstep

        cout<<setfill('*')<<setw(n)<<"*"<<setfill(' ')<<endl;//dolna rama z gwiazdek

    return 0;
}
