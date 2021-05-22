#include <iostream>

using namespace std;

#if !defined(_ULAMEK_ZWYKLY_)
#define _ULAMEK_ZWYKLY_



class cUlamekZwykly
{
public:
    cUlamekZwykly(long long int Calosci=0, long long int Licznik=1, long long int Mianownik=1);

    void Skracanie();
    void WyciaganieCalosciPrzed();
    void CalosciDoLicznika();

    long long int Licznik();
    long long int Mianownik();
    long long int Calosci();
    void Wypisz();

    long long int NajwiekszyWspolnyDzielnik(long long int LiczbaA, long long int LiczbaB);
    long long int NajmniejszaWspolnaWielokrotnosc(long long int LiczbaA, long long int LiczbaB);
    cUlamekZwykly operator*(cUlamekZwykly UlamekP);
    cUlamekZwykly operator/(cUlamekZwykly UlamekP);
    cUlamekZwykly operator+(cUlamekZwykly UlamekP);
    cUlamekZwykly operator-(cUlamekZwykly UlamekP);
    bool operator==(cUlamekZwykly UlamekP);
    bool operator!=(cUlamekZwykly UlamekP);
    bool operator>(cUlamekZwykly UlamekP);
    bool operator<(cUlamekZwykly UlamekP);
    bool operator>=(cUlamekZwykly UlamekP);
    bool operator<=(cUlamekZwykly UlamekP);

    friend ostream& operator<<(ostream& tekst, const cUlamekZwykly Ulamek);
private:

    long long int m_Licznik, m_Mianownik, m_Calosci;

};


#endif //_ULAMEK_ZWYKLY_

