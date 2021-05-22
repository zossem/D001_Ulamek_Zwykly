#include <iostream>
#include <cmath>
#include "ulamek_zwykly.h"

using namespace std;

cUlamekZwykly::cUlamekZwykly(long long int Calosci, long long int Licznik, long long int Mianownik)
{
    m_Calosci=Calosci;
    m_Licznik=Licznik;
    while(Mianownik==0)
    {
        cout<<"Nie dziel przez zero i podaj inny mianownik"<<endl;
        cin>>Mianownik;
    }
    m_Mianownik=Mianownik;
}



void cUlamekZwykly::Skracanie()
{
    long long int NWD=NajwiekszyWspolnyDzielnik(m_Licznik, m_Mianownik);
    m_Licznik=m_Licznik/NWD;
    m_Mianownik=m_Mianownik/NWD;
    if(m_Mianownik<0)
    {
        m_Mianownik=m_Mianownik*(-1);
        m_Licznik=m_Licznik*(-1);
    }
}

void cUlamekZwykly::WyciaganieCalosciPrzed()
{
    m_Calosci=(m_Licznik/m_Mianownik)+m_Calosci;
    m_Licznik=m_Licznik%m_Mianownik;
    if(m_Calosci<0)
    {
        if(m_Licznik<0)
            m_Licznik=m_Licznik*(-1);
    }
}

void cUlamekZwykly::CalosciDoLicznika()
{
    m_Licznik=m_Licznik+m_Mianownik*m_Calosci;
    m_Calosci=0;
}

long long int cUlamekZwykly::Licznik(){return m_Licznik;}

long long int cUlamekZwykly::Mianownik(){return m_Mianownik;}

long long int cUlamekZwykly::Calosci(){return m_Calosci;}

void cUlamekZwykly::Wypisz()
{
    cout<<"To ulamek zwykly:"<<endl;
    int ile_cyfr_calosci=0, ile_cyfr_licznik=0, ile_cyfr_mianownik=0;
    long long int calosci=m_Calosci, licznik=m_Licznik, mianownik=m_Mianownik;
    while(calosci!=0)
    {
        calosci=calosci/10;
        ile_cyfr_calosci++;
    }
    while(licznik!=0)
    {
        licznik=licznik/10;
        ile_cyfr_licznik++;
    }
    while(mianownik!=0)
    {
        mianownik=mianownik/10;
        ile_cyfr_mianownik++;
    }
    if(m_Calosci<0)
        ile_cyfr_calosci++;
    if(m_Licznik<0)
        ile_cyfr_licznik++;
    if(m_Mianownik<0)
        ile_cyfr_mianownik++;

    if(ile_cyfr_mianownik>ile_cyfr_licznik)
    {
        if(m_Calosci!=0)
        {
            if(m_Licznik!=0)
            {
                for(int i=0; i<ile_cyfr_calosci+ile_cyfr_mianownik-ile_cyfr_licznik; i++)
                {
                    cout<<" ";
                }
                cout<<m_Licznik<<endl<<m_Calosci;
                for(int i=0; i< ile_cyfr_mianownik; i++)
                {
                    cout<<"-";
                }
                cout<<endl;
                for(int i=0; i<ile_cyfr_calosci; i++)
                {
                    cout<<" ";
                }
                cout<<m_Mianownik<<endl<<endl;
            }
            else
            {
                cout<<m_Calosci<<endl<<endl;
            }
        }
        else
        {
            if(m_Licznik!=0)
            {
                for(int i=0; i<ile_cyfr_mianownik-ile_cyfr_licznik; i++)
                {
                    cout<<" ";
                }
                cout<<m_Licznik<<endl;
                for(int i=0; i< ile_cyfr_mianownik; i++)
                {
                    cout<<"-";
                }
                cout<<endl;

                cout<<m_Mianownik<<endl<<endl;
            }
            else
            {
                cout<<m_Calosci<<endl<<endl;
            }
        }
    }
    else
    {
        if(m_Calosci!=0)
        {
            if(m_Licznik!=0)
            {
                for(int i=0; i<ile_cyfr_calosci; i++)
                {
                    cout<<" ";
                }
                cout<<m_Licznik<<endl<<m_Calosci;
                for(int i=0; i< ile_cyfr_licznik; i++)
                {
                    cout<<"-";
                }
                cout<<endl;
                for(int i=0; i<ile_cyfr_calosci-ile_cyfr_mianownik+ile_cyfr_licznik; i++)
                {
                    cout<<" ";
                }
                cout<<m_Mianownik<<endl<<endl;
            }
            else
            {
                cout<<m_Calosci<<endl<<endl;
            }
        }
        else
        {
            if(m_Licznik!=0)
            {
                cout<<m_Licznik<<endl;
                for(int i=0; i< ile_cyfr_licznik; i++)
                {
                    cout<<"-";
                }
                cout<<endl;
                for(int i=0; i<ile_cyfr_licznik-ile_cyfr_mianownik; i++)
                {
                    cout<<" ";
                }

                cout<<m_Mianownik<<endl<<endl;
            }
            else
            {
                cout<<m_Calosci<<endl<<endl;
            }
        }
    }
}

long long int cUlamekZwykly::NajwiekszyWspolnyDzielnik(long long int LiczbaA, long long int LiczbaB)
{
    long long int reszta;
    while(LiczbaB!=0)
    {
        reszta=LiczbaA%LiczbaB;
        LiczbaA=LiczbaB;
        LiczbaB=reszta;
    }
    if(LiczbaA>0)
        return LiczbaA;
    else
        return (LiczbaA*(-1));
}

long long int cUlamekZwykly::NajmniejszaWspolnaWielokrotnosc(long long int LiczbaA, long long int LiczbaB)
{
    long long int NWD=NajwiekszyWspolnyDzielnik(LiczbaA, LiczbaB);
    if (((LiczbaA/NWD)*LiczbaB)>0)
        return ((LiczbaA/NWD)*LiczbaB);
    else
        return ((LiczbaA/NWD)*LiczbaB* (-1));
}

cUlamekZwykly cUlamekZwykly::operator*(cUlamekZwykly UlamekP)
{
    cUlamekZwykly UlamekLewy(m_Calosci, m_Licznik, m_Mianownik);
    cUlamekZwykly UlamekPrawy(UlamekP.Calosci(), UlamekP.Licznik(), UlamekP.Mianownik());

    UlamekLewy.CalosciDoLicznika();
    UlamekPrawy.CalosciDoLicznika();

    long long int Licznik=UlamekLewy.Licznik()*UlamekPrawy.Licznik();
    long long int Mianownik=UlamekLewy.Mianownik()*UlamekPrawy.Mianownik();

    cUlamekZwykly rezultat(0, Licznik, Mianownik);

    rezultat.Skracanie();
    rezultat.WyciaganieCalosciPrzed();
    return rezultat;
}
cUlamekZwykly cUlamekZwykly::operator/(cUlamekZwykly UlamekP)
{
    cUlamekZwykly UlamekLewy(m_Calosci, m_Licznik, m_Mianownik);
    cUlamekZwykly UlamekPrawy(UlamekP.Calosci(), UlamekP.Licznik(), UlamekP.Mianownik());

    UlamekLewy.CalosciDoLicznika();
    UlamekPrawy.CalosciDoLicznika();

    cUlamekZwykly Odwrotnosc(0, UlamekPrawy.Mianownik(), UlamekPrawy.Licznik());

    cUlamekZwykly rezultat=UlamekLewy*Odwrotnosc;
    return rezultat;
}
cUlamekZwykly cUlamekZwykly::operator+(cUlamekZwykly UlamekP)
{
    cUlamekZwykly UlamekLewy(m_Calosci, m_Licznik, m_Mianownik);
    cUlamekZwykly UlamekPrawy(UlamekP.Calosci(), UlamekP.Licznik(), UlamekP.Mianownik());

    UlamekLewy.CalosciDoLicznika();
    UlamekPrawy.CalosciDoLicznika();

    long long int NWW=NajmniejszaWspolnaWielokrotnosc(UlamekLewy.Mianownik(), UlamekPrawy.Mianownik());

    long long int Licznik=(NWW/UlamekLewy.Mianownik())*UlamekLewy.Licznik() + (NWW/UlamekPrawy.Mianownik())*UlamekPrawy.Licznik();
    long long int Mianownik=NWW;

    cUlamekZwykly rezultat(0, Licznik, Mianownik);
    rezultat.Skracanie();
    rezultat.WyciaganieCalosciPrzed();
    return rezultat;
}
cUlamekZwykly cUlamekZwykly::operator-(cUlamekZwykly UlamekP)
{
    cUlamekZwykly UlamekLewy(m_Calosci, m_Licznik, m_Mianownik);
    cUlamekZwykly UlamekPrawy(UlamekP.Calosci(), UlamekP.Licznik(), UlamekP.Mianownik());

    UlamekLewy.CalosciDoLicznika();
    UlamekPrawy.CalosciDoLicznika();

    long long int NWW=NajmniejszaWspolnaWielokrotnosc(UlamekLewy.Mianownik(), UlamekPrawy.Mianownik());

    long long int Licznik=(NWW/UlamekLewy.Mianownik())*UlamekLewy.Licznik() - (NWW/UlamekPrawy.Mianownik())*UlamekPrawy.Licznik();
    long long int Mianownik=NWW;

    cUlamekZwykly rezultat(0, Licznik, Mianownik);
    rezultat.Skracanie();
    rezultat.WyciaganieCalosciPrzed();
    return rezultat;
}
bool cUlamekZwykly::operator==(cUlamekZwykly UlamekP)
{
    cUlamekZwykly UlamekLewy(m_Calosci, m_Licznik, m_Mianownik);
    cUlamekZwykly UlamekPrawy(UlamekP.Calosci(), UlamekP.Licznik(), UlamekP.Mianownik());

    UlamekLewy.CalosciDoLicznika();
    UlamekPrawy.CalosciDoLicznika();

    long long int NWW=NajmniejszaWspolnaWielokrotnosc(UlamekLewy.Mianownik(), UlamekPrawy.Mianownik());

    long long int LicznikLewy=(NWW/UlamekLewy.Mianownik())*UlamekLewy.Licznik();
    long long int LicznikPrawy=(NWW/UlamekPrawy.Mianownik())*UlamekPrawy.Licznik();

    bool rezultat=(LicznikLewy==LicznikPrawy);
    return rezultat;
}

bool cUlamekZwykly::operator!=(cUlamekZwykly UlamekP)
{
    cUlamekZwykly UlamekLewy(m_Calosci, m_Licznik, m_Mianownik);
    cUlamekZwykly UlamekPrawy(UlamekP.Calosci(), UlamekP.Licznik(), UlamekP.Mianownik());

    UlamekLewy.CalosciDoLicznika();
    UlamekPrawy.CalosciDoLicznika();

    long long int NWW=NajmniejszaWspolnaWielokrotnosc(UlamekLewy.Mianownik(), UlamekPrawy.Mianownik());

    long long int LicznikLewy=(NWW/UlamekLewy.Mianownik())*UlamekLewy.Licznik();
    long long int LicznikPrawy=(NWW/UlamekPrawy.Mianownik())*UlamekPrawy.Licznik();

    bool rezultat=(LicznikLewy!=LicznikPrawy);
    return rezultat;
}

bool cUlamekZwykly::operator>(cUlamekZwykly UlamekP)
{
    cUlamekZwykly UlamekLewy(m_Calosci, m_Licznik, m_Mianownik);
    cUlamekZwykly UlamekPrawy(UlamekP.Calosci(), UlamekP.Licznik(), UlamekP.Mianownik());

    UlamekLewy.CalosciDoLicznika();
    UlamekPrawy.CalosciDoLicznika();

    long long int NWW=NajmniejszaWspolnaWielokrotnosc(UlamekLewy.Mianownik(), UlamekPrawy.Mianownik());

    long long int LicznikLewy=(NWW/UlamekLewy.Mianownik())*UlamekLewy.Licznik();
    long long int LicznikPrawy=(NWW/UlamekPrawy.Mianownik())*UlamekPrawy.Licznik();

    bool rezultat=(LicznikLewy>LicznikPrawy);
    return rezultat;
}

bool cUlamekZwykly::operator<(cUlamekZwykly UlamekP)
{
    cUlamekZwykly UlamekLewy(m_Calosci, m_Licznik, m_Mianownik);
    cUlamekZwykly UlamekPrawy(UlamekP.Calosci(), UlamekP.Licznik(), UlamekP.Mianownik());

    UlamekLewy.CalosciDoLicznika();
    UlamekPrawy.CalosciDoLicznika();

    long long int NWW=NajmniejszaWspolnaWielokrotnosc(UlamekLewy.Mianownik(), UlamekPrawy.Mianownik());

    long long int LicznikLewy=(NWW/UlamekLewy.Mianownik())*UlamekLewy.Licznik();
    long long int LicznikPrawy=(NWW/UlamekPrawy.Mianownik())*UlamekPrawy.Licznik();

    bool rezultat=(LicznikLewy<LicznikPrawy);
    return rezultat;
}

bool cUlamekZwykly::operator>=(cUlamekZwykly UlamekP)
{
    cUlamekZwykly UlamekLewy(m_Calosci, m_Licznik, m_Mianownik);
    cUlamekZwykly UlamekPrawy(UlamekP.Calosci(), UlamekP.Licznik(), UlamekP.Mianownik());

    UlamekLewy.CalosciDoLicznika();
    UlamekPrawy.CalosciDoLicznika();

    long long int NWW=NajmniejszaWspolnaWielokrotnosc(UlamekLewy.Mianownik(), UlamekPrawy.Mianownik());

    long long int LicznikLewy=(NWW/UlamekLewy.Mianownik())*UlamekLewy.Licznik();
    long long int LicznikPrawy=(NWW/UlamekPrawy.Mianownik())*UlamekPrawy.Licznik();

    bool rezultat=(LicznikLewy>=LicznikPrawy);
    return rezultat;
}

bool cUlamekZwykly::operator<=(cUlamekZwykly UlamekP)
{
    cUlamekZwykly UlamekLewy(m_Calosci, m_Licznik, m_Mianownik);
    cUlamekZwykly UlamekPrawy(UlamekP.Calosci(), UlamekP.Licznik(), UlamekP.Mianownik());

    UlamekLewy.CalosciDoLicznika();
    UlamekPrawy.CalosciDoLicznika();

    long long int NWW=NajmniejszaWspolnaWielokrotnosc(UlamekLewy.Mianownik(), UlamekPrawy.Mianownik());

    long long int LicznikLewy=(NWW/UlamekLewy.Mianownik())*UlamekLewy.Licznik();
    long long int LicznikPrawy=(NWW/UlamekPrawy.Mianownik())*UlamekPrawy.Licznik();

    bool rezultat=(LicznikLewy<=LicznikPrawy);
    return rezultat;
}

ostream& operator<<(ostream& tekst, const cUlamekZwykly Ulamek)
{
    tekst<<Ulamek.m_Calosci<<" "<<Ulamek.m_Licznik<<"/"<<Ulamek.m_Mianownik;
    return tekst;
}

