#include <vector>
#include "strona.h"
#include "MFU.h"

using namespace std;

vector<strona> MFU(strona a[20], int x, int odwolanie[100])
{
    int ramka[x];              //  ramka
    for(int i=0; i<x; i++)
    {
        ramka[i]=0;
    }
    int now=0;                 // zmienna mowiaca, ktore odwolanie teraz

    while(now<100)
    {
        int w_ramce=10;         // zmienna bufor - sprawdza czy odwolanie znajduje sie juz w ramce
        for(int i=0; i<x; i++)
        {
            if(ramka[i]==odwolanie[now])
            {
                w_ramce=i;      // do bufora trafia miejsce w ramce, w ktorym juz wystepuje odwolanie
                break;
            }
        }
        if(w_ramce<10)          // sprawdzenie bufora
        {
            a[(odwolanie[now])-1].bufor++;  // dodanie kroku do danych strony
        }
        else
        {
            int wolna_ramka=10; // zmienna bufor - sprawdza czy jest jeszcze jakies wolne miejsce w ramce
            for(int i=0; i<x; i++)
            {
                if(ramka[i]==0) // do bufora trafia miejsce w ramce, ktore jest wolne
                {
                    wolna_ramka=i;
                    ramka[i]=odwolanie[now];
                    break;
                }
            }
            if(wolna_ramka<10)        // sprawdzenie bufora
            {
                a[(odwolanie[now])-1].brakuje++;    // dodanie informacji o brakujacej strony
                a[(odwolanie[now])-1].bufor++;      // dodanie kroku do danych strony
            }
            else  // szukanie co bylo najczesciej uzyte
            {
                int mf=ramka[0];                                         // bufor - liczba z ramki
                int pozycja=0;                                           // bufor - pozycja najczestszego odwolanie
                for(int i=1; i<x; i++)                                   // szukanie najczestszego odwolania
                {
                    if(a[(ramka[i])-1].bufor>a[mf-1].bufor)
                    {
                        mf=a[(ramka[i])-1].numer;
                        pozycja=i;
                    }
                }
                ramka[pozycja]=odwolanie[now];          // dodanie do ramki nowego odwolania, zastepujac najczestsze
                a[(odwolanie[now])-1].brakuje++;        // dodanie informacji o brakujacej strony
                a[(odwolanie[now])-1].bufor++;          // dodanie kroku do danych strony
            }
        }
        now++;          // kolejne odwolanie
    }

    vector<strona> gotowe;
    for(int i=0; i<20; i++)
    {
        gotowe.push_back(a[i]);
        a[i].bufor=0;
        a[i].brakuje=0;
    }
    // wyslanie wektora z danymi po symulacji
    return gotowe;
}
