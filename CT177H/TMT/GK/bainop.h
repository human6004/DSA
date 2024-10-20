#include <stdio.h>
#include <stdlib.h>

#define MaxLength 100
typedef int ElementType;
typedef int Position;

typedef struct {
    ElementType Elements[MaxLength];
    Position Last;
}List;
void makeNull(List *L) {
    L->Last = 0;
}

int len(List L) {
    return L.Last;
}

int empty(List L) {
    return L.Last == 0;
}

int fullList(List L) {
    return L.Last == MaxLength;
}

Position first(List L) {
    return 1;
}

Position endList(List L) {
    return L.Last + 1;
}

Position next(Position P, List L) {
    return P + 1;
}

ElementType getAt(Position P, List L) {
    return L.Elements[P - 1];
}

void print(List L) {
    if (empty(L)) {
        printf("List is empty!\n");
        return;
    }
    if (fullList(L)) {
        printf("List is full!\n");
        return;
    }
    for (int i = first(L); i < endList(L); i++) {
        printf("%d ", L.Elements[i - 1]);
    }
    printf("\n");
}

void setAt(Position P, ElementType x, List *L) {
    if (P < 1 || P > len(*L)) {
        printf("Error: Invalid position!\n");
        return;
    }
    L->Elements[P - 1] = x;
}

void insertAt(Position P, ElementType X, List *L) {
    if (fullList(*L)) {
        printf("List is full!\n");
        return;
    }
    if (P < 1 || P > L->Last + 1) {
        printf("Error: Invalid position!\n");
        return;
    }
    for (int i = L->Last; i >= P; i--) {
        L->Elements[i] = L->Elements[i - 1];
    }
    L->Elements[P - 1] = X;
    L->Last++;
}

ElementType popAt(Position P, List *L) {
    if (empty(*L)) {
        printf("List is empty!\n");
        return -1;
    }
    if (P < 1 || P > L->Last) {
        printf("Error: Invalid position!\n");
        return -1;
    }
    ElementType a = L->Elements[P - 1];
    for (int i = P - 1; i < L->Last - 1; i++) {
        L->Elements[i] = L->Elements[i + 1];
    }
    L->Last--;
    return a;
}


int insertFirst(ElementType x, List *L) {
    if (fullList(*L)) {
        printf("List is full!\n");
        return 0;
    }
    insertAt(first(*L), x, L);
    return 1;
}


void popFirst(List *L) {
    popAt(first(*L), L);
}


void append(ElementType x, List *L) {
    if (fullList(*L)) {
        printf("List is full!\n");
        return;
    }
    L->Elements[L->Last] = x;
    L->Last++;
}


void popLast(List *L) {
    popAt(L->Last, L);
}

Position locate(ElementType x, List L) {
    for (Position p = first(L); p < endList(L); p++) {
        if (L.Elements[p - 1] == x) {
            return p;
        }
    }
    return -1; 
}

Position previous(Position p, List L) {
    return p - 1;
}