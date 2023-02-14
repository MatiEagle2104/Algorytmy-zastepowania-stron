#include <vector>
#include "strona.h"
#include "statystyka.h"

using namespace std;

float statystyka (vector<strona>x)
{
    float staty=0;                 // zmienna przechowujacy dane dot. ilosci brakujacych stron

    // obliczenie sredniej
    for(int i=0; i<20; i++)
    {
        staty += x[i].brakuje;
    }

    return staty;
}
