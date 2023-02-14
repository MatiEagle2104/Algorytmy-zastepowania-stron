#ifndef LRU_H_INCLUDED
#define LRU_H_INCLUDED

#include <vector>
#include "strona.h"

using namespace std;

vector<strona> LRU(strona a[20], int x, int odwolanie[100]);    // funkcja symulujaca algorytmem Least Recently Used

#endif // LRU_H_INCLUDED
