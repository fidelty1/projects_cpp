#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    string you;
    string opponent;
    int o=0;
    string potwierdz;

BEGIN1:
    cout << "Witaj w grze kamien-papier-nozyce. Zasady gry sa proste: \nGrasz z komputerem. W grze chodzi o to, ze papier owija kamien, kamien tepi nozyce, a nozyce tna papier. Wszystko jasne? (tak/nie)" << endl;
    cin>>potwierdz;

    if (potwierdz=="tak"){}
        else if (potwierdz=="nie")
        {
            cout<<endl;
             goto BEGIN1;
        }
        else
        {
            cout<<endl<<"napisz tak lub nie!!!\n"<<endl;
            goto BEGIN1;
        }

        BEGIN2:
        cout<<endl<<"OK. Czyli wszystko jasne. Wiec gramy dalej. Podaj co wystawiasz (papier/kamien/nozyce): "<<endl;
        cin>>you;

        srand(time(NULL));
        o=(rand()%3)+1;

        if(o==1) opponent="kamien";
            else if (o==2) opponent="papier";
            else opponent="nozyce";

            if(you==opponent)
            cout<<"Nieslychane. Zarowno Ty jak i komputer wybraliscie "<<you<<". Sproboj jeszcze raz."<<endl;
        else if (you=="kamien" && opponent=="papier")
            cout<<"Oops. Wybrales "<<you<<", natomiast komputer wybral "<<opponent<<". Papier owija kamien. Przykro nam. Przegrales."<<endl;
        else if (you=="kamien" && opponent=="nozyce")
            cout<<"Wow. Wybrales "<<you<<", natomiast komputer wybral "<<opponent<<". Kamien tepi nozyce. Gratulacje. Wygrales."<<endl;
        else if (you=="papier" && opponent=="nozyce")
            cout<<"Oops. Wybrales "<<you<<", natomiast komputer wybral "<<opponent<<". Nozyce tna papier. Przykro nam. Przegrales."<<endl;
        else if (you=="papier" && opponent=="kamien")
            cout<<"Wow. Wybrales "<<you<<", natomiast komputer wybral "<<opponent<<". Papier owija kamien. Gratulacje. Wygrales."<<endl;
        else if (you=="nozyce" && opponent=="kamien")
            cout<<"Oops. Wybrales "<<you<<", natomiast komputer wybral "<<opponent<<". Kamien tepi nozyce. Przykro nam. Przegrales."<<endl;
        else if (you=="nozyce" && opponent=="papier")cout<<"Wow. Wybrales "<<you<<", natomiast komputer wybral "<<opponent<<". Nozyce tna papier. Gratulacje. Wygrales."<<endl;
        else
        	{
        		cout<<"Podales zla wartosc. Wpisz paper/kamien/nozyce! Wroc do zasad!"<<endl<<endl;
        		goto BEGIN1;
			}

BEGIN3:
cout<<endl<<"Czy chcesz grac dalej? (tak/nie)\n"<<endl;
cin>>potwierdz;


    if (potwierdz=="tak")
        {
            cout<<endl;
             goto BEGIN2;
        }
        else if (potwierdz=="nie")
            return 0;
          else
        {
            cout<<endl<<"napisz tak lub nie!!!\n"<<endl;;
            goto BEGIN3;
        }
}
