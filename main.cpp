#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>

#include "strona.h"
#include "LRU.h"
#include "MFU.h"
#include "statystyka.h"

using namespace std;

int main()
{
    srand(time(NULL));

    // tworzenie i otwarcie plikow do ktorych zapisywane beda dane i wyniki
    ofstream zapis_danych;
    zapis_danych.open("dane.txt", ios::out);
    ofstream zapis_statystyk;
    zapis_statystyk.open("wyniki.txt", ios::out);

    for(int i=0; i<100; i++)
    {
        strona a[20];
        for(int i=0; i<20; i++)          // tworzenie obiektow odpowiadajacych stronom zajmowanych przez procesy
        {
            a[i].numer=i+1;
        }

        int odwolanie[100];                         // tworzenie ciagu odwolan
        zapis_danych << i+1 << ". CIAG - ";         // zapis danych do pliku
        for(int i=0; i<100; i++)
        {
            odwolanie[i] = rand()%20 + 1;           // losowo wybrane numery stron
            zapis_danych << odwolanie[i] << " ";    // zapis danych do pliku
        }
        zapis_danych << "\n";

        vector<strona>L3, L5, L7, M3, M5, M7;
        L3=LRU(a, 3, odwolanie);                    // uruchomienie algorytmu LRU dla liczby ramek R=3
        L5=LRU(a, 5, odwolanie);                    // uruchomienie algorytmu LRU dla liczby ramek R=5
        L7=LRU(a, 7, odwolanie);                    // uruchomienie algorytmu LRU dla liczby ramek R=7
        M3=MFU(a, 3, odwolanie);                    // uruchomienie algorytmu MFU dla liczby ramek R=3
        M5=MFU(a, 5, odwolanie);                    // uruchomienie algorytmu MFU dla liczby ramek R=5
        M7=MFU(a, 7, odwolanie);                    // uruchomienie algorytmu MFU dla liczby ramek R=7

        // zapis statystyk do pliku
        zapis_statystyk << i+1 << " " << statystyka(L3) << " " << statystyka(L5) << " " << statystyka(L7) << " - ";
        zapis_statystyk << statystyka(M3) << " " << statystyka(M5) << " " << statystyka(M7) << "\n";
    }

    // zamkniecie plikow do ktorych zapisywano dane i wyniki
    zapis_danych.close();
    zapis_statystyk.close();

    cout << "Wykonano symulacje!" << endl;              // komunikat na ekranie o zakonczeniu symulacji

    return 0;
}
