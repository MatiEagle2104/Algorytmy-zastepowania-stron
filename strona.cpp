#include <iostream>
#include <time.h>
#include "strona.h"

using namespace std;

strona::strona()
{
    numer = 0;
    bufor = 0;
    brakuje = 0;
}

strona::~strona() {}

void strona::dane() const
{
    cout << "Strona " << numer << endl;
    cout << "Bufor: " << bufor << endl;
    cout << "Ilosc brakujacych stron - " << brakuje << endl << endl;
}
