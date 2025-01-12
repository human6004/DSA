#include <stdio.h>
#include <stdlib.h>

#define MaxLength 100
typedef int ElementType;
typedef int Position;

typedef struct
{
    ElementType Elements[MaxLength]; 
    Position Last;                   
} List;

List L;

void makeNull(List *L)
{
    L->Last = 0;
}

int len(List L)
{
    return L.Last;
}

int empty(List L)
{
    return L.Last == 0;
}

int fullList(List L)
{
    return L.Last == MaxLength;
}

int first(List L)
{
    return 1;
}

int endList(List L)
{
    return L.Last + 1;
}

int next(Position P, List L)
{
    return P + 1;
}

int getAt(Position P, List L)
{
    return L.Elements[P - 1];
}

void print(List L)
{
    if (empty(L))
    {
        printf("List is empty!!!!");
    }
    if (fullList(L))
    {
        printf("List is full!!!");
    }
    for (int i = first(L); i < endList(L); i++)
    {
        printf("%d ", L.Elements[i - 1]);
    }
}

void setAt(Position P, ElementType x, List *L)
{
    if (P < 1 || P > len(*L))
    {
        printf("Error!!!\n");
        return;
    }
    L->Elements[P - 1] = x;
}

void insertAt(Position P, ElementType X, List *L)
{
    if (fullList(*L))
    {
        printf("List is full!!");
        return;
    }
    else if ((P < 1) || (P > L->Last + 1))
    {
        printf("Error!!!");
        return;
    }
    else
    {
        for (int i = L->Last; i >= P; i--)
        {
            L->Elements[i] = L->Elements[i - 1];
        }
        L->Elements[P - 1] = X;
        L->Last++;
    }
}

int popAt(Position P, List *L)
{
    if (empty(*L))
        printf("List is full!!\n");
    else if ((P < 1) || (P > L->Last))
        printf("Error!!\n");
    else
    {
        int a = L->Elements[P - 1];
        for (int i = p - 1; i < endList(*L); i++)
        {
            L->Elements[i] = L->Elements[i + 1];
            L->Last--;
        }
        return a;
    }
}

int insertFirst(ElementType x, List *L)
{
    if (fullList(*L))
    {
        printf("List is full!!");
    }
    else
    {
        insertAt(first(*L), x, L);
    }
}

void popFirst(List *L)
{
    popAt(first(*L), L);
}

void append(ElementType x, List *L)
{
    if (fullList(*L))
        printf("Danh sách đầy!\n");
    else
    {
        L->Elements[L->Last] = x;
        L->Last++;
    }
}

void popLast(List *L)
{
    popAt(L->Last, L);
}

Position Locate(ElementType X, List L)
{
    for (int i = 0; i <= L.Last - 1; i++)
    {
        if (L.Elements[i] == X)
        {
            return i;
        }
    }
}

Position previous(Position p, List L)
{
    return p - 1;
}

void swap(Position p, Position q, List *L)
{
    ElementType temp;
    temp = getAt(p, *L);
    setAt(p, getAt(q, *L), L);
    setAt(q, temp, L);
}

void bubbleSort(List *L)
{
    int size = len(*L);
    for (int i = first(*L); i < size; i++)
    {
        for (int j = first(*L); j <= size - i; j++)
        {
            if (getAt(j, *L) > getAt(j + 1, *L))
            {
                swap(j, j + 1, L);
            }
        }
    }
}
