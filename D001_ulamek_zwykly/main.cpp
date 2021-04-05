#include <iostream>
#include "ulamek_zwykly.h"

using namespace std;

int main()
{
    cUlamekZwykly Pierwszy(1, 3, 4);
    cUlamekZwykly Drugi(1, -436, 8);
    cUlamekZwykly Trzeci;

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
