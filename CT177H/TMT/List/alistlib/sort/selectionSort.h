#include "alistlib.h"
#include <stdio.h>


// selection sort
void selectionSort(List *L) {
    for (Position p = first(*L); p < end(*L) - 1; p = next(p, *L)) {
        for (Position q = next(p, *L); q < end(*L); q = next(q, *L)) {
            if (getAt(p, *L) > getAt(q, *L)) {
                ElementType temp = L->Elements[p - 1];
                L->Elements[p - 1] = L->Elements[q - 1];
                L->Elements[q - 1] = temp;
            }
        }
    }
}