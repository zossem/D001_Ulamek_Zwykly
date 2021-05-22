#include <iostream>
#include "ulamek_zwykly.h"

using namespace std;

int main()
{
    cUlamekZwykly Pierwszy(1, 3, 4);
    cUlamekZwykly Drugi(1, 0, 8);
    cUlamekZwykly Trzeci;

    //cout<<Drugi<<"  "<<Pierwszy<<endl;
    Drugi.Wypisz();

    Trzeci=Pierwszy+Drugi;
    Trzeci.Wypisz();

    Trzeci=Pierwszy-Drugi;
    Trzeci.Wypisz();

    Trzeci=Pierwszy*Drugi;
    Trzeci.Wypisz();

    Trzeci=Pierwszy/Drugi;
    Trzeci.Wypisz();

    Trzeci=Drugi/Pierwszy;
    Trzeci.Wypisz();
}
