#include <stdio.h>
#include <stdlib.h>

// the maximum size of list
#define MaxLength 100
// the element type of list
typedef int ElementType;
// the position type of elements
typedef int Position;

typedef struct
{
    // array consisting elements of list
    ElementType Elements[MaxLength];
    // the current length of list
    Position Last;
} List;

List L;

// Initialize an empty list
void makeNull(List *L)
{
    L->Last = 0;
    // (*L).Last=0;
}

// return Number of elements
int Len(List L)
{
    return L.Last;
}

// Check whether the list is empty?
int empty(List L)
{
    return L.Last == 0;
}

// Check whether the list is full?
int fullList(List L)
{
    return L.Last == MaxLength;
}

// Return the first position in L
int first(List L)
{
    return 1;
}

// Return the end position in L
int end(List L)
{
    return L.Last + 1;
}

// Return the next position of p in L
int next(Position P, List L)
{
    return P + 1;
}

// Return the element at position p
int getAt(Position P, List L)
{
    return L.Elements[P - 1];
}

// Traverse the list to print out all elements
void print(List L)
{
    Position P;
    P = first(L);
    while (P != end(L))
    {
        printf("%d", getAt(P, L));
        P = next(P, L);
    }
}

// Update the element at position p by a new value
void setAt(Position P, ElementType x, List *L)
{
    L->Elements[P - 1] = x;
}

// Insert x at position p
void InsertAt(ElementType X, Position P, List *L)
{
    if (L->Last == MaxLength)
        printf("Danh sach day");
    else if ((P < 1) || (P > L->Last + 1))
        printf("Vi tri khong hop le");
    else
    {
        Position Q;
        /*Dời các phtử từ vị trí p đến cuối dsách ra
        sau 1 vị trí*/
        for (Q = (L->Last - 1) + 1; Q >= P; Q--)
        {
            L->Elements[Q] = L->Elements[Q - 1];
            // Đưa x vào vị trí p
        }
        L->Elements[P - 1] = X;
        // Tăng độ dài danh sách lên 1
        L->Last++;
    }
}

// Remove and return the element at position p
void popAt(Position P, List *L)
{
    if (empty(*L))
        printf("Danh sách rỗng!\n");
    else if ((P < 1) || (P > L->Last))
        printf("Vị trí không hợp lệ!\n");
    else
    {
        Position Q;
        for (Q = P - 1; Q < L->Last - 1; Q++)
        {
            L->Elements[Q] = L->Elements[Q + 1];
        }
        L->Last--;
    }
}

// Insert x to the first position
void insertFirst(ElementType x, List *L)
{
    InsertAt(x, first(*L), L); // Chèn phần tử x vào vị trí đầu tiên
}

// Remove and return the first element
void popFirst(List *L)
{
    popAt(first(*L), L);
}

// Append a new element to the list
void append(ElementType x, List *L)
{
    if (fullList(*L)) // Kiểm tra danh sách có đầy không
        printf("Danh sách đầy!\n");
    else
    {
        L->Elements[L->Last] = x;
        L->Last++;
    }
}

// Remove and return the last element
void popLast(List *L)
{
    popAt(L->Last, L); // Xóa phần tử cuối cùng
}

// Return the position of the first appearance of x in the list
Position Locate(ElementType X, List L)
{
    Position P;
    int Found = 0;
    P = first(L); // vị trí phần tử đầu tiên
    /*trong khi chưa tìm thấy và chưa kết thúc
    danh sách thì xét phần tử kế tiếp*/
    while ((P != end(L)) && (Found == 0))
        if (getAt(P, L) == X)
            Found = 1;
        else
            P = next(P, L);
    return P;
}

//Return the previous position of p in L
Position previous(Position p,List L){
	return p-1;

}