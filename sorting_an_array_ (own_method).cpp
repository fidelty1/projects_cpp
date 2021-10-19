#include <iostream>

using namespace std;

int main()
{
    int n=0;
    float tab[10]={0,0,0,0,0,0,0,0,0,0};
    float L=0, Lmax=0;
    int z=0;

BEGIN1:
    cout << "Podaj, ile liczb chcesz wprowadzic:" << endl;
    cin>>n;


    if(n>10)
    {
        cout<<"Podales za duze n. Nie moze byc wieksze od 10. Podaj poprawna wartosc!"<<endl;
        goto BEGIN1;
    }

    for(int i=0; i<n; i++)
    {
        cout<<"Wprowadz liczbe L"<<i+1<<" do tablicy"<<endl;
        cin>>L;
        tab[i]=L;
    }


    float pom1[10]={0,0,0,0,0,0,0,0,0,0};
    float pom2[10]={0,0,0,0,0,0,0,0,0,0};
    float pom3[10]={0,0,0,0,0,0,0,0,0,0};
    float pom4[10]={0,0,0,0,0,0,0,0,0,0};

    for(int b=0; b<n; b++)
        {
            pom1[b]=tab[b];
        }

    for(int b=0; b<n; b++)
        {
            pom3[b]=tab[b];
        }

 for(int k=0; k<n; k++)
    {

        for(int j=0; j<n; j++)
    {

        if(pom1[j]>Lmax)
        {
            Lmax=pom1[j];
            z=j;
        }

    }

    pom2[9-k]=Lmax;
    pom1[z]=0;
    Lmax=0;

    }


    for(int k=0; k<n; k++)
    {

        for(int j=0; j<n; j++)
    {

        if(pom3[j]<Lmax)
        {
            Lmax=pom3[j];
            z=j;
        }

    }

    pom4[k]=Lmax;
    pom3[z]=0;
    Lmax=0;

    }




    for(int c=0; c<10; c++)
    {
        if(pom2[c]>0)
        tab[c]=pom2[c];

        if(pom4[c]<0)
        tab[c]=pom4[c];

        if(pom2[c]==0 && pom4[c]==0)
        tab[c]=0;
    }


cout<<endl<<endl;

cout<<"Wypisaywanie dziesiecioelementowej rosnacej tablicy tab[] w kolejnosci malejacej:"<<endl;

for(int d=9; d>=0; d--)
{
    cout<<"tab ["<<d<<"] wynosi: "<<tab[d]<<endl;
}


    return 0;
}
