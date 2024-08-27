#include <stdio.h>
#define MaxLength 300
#define MaxLength 300
// the maximum size of list
#define MaxLength 300
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

// Creating an Empty List
List makenullList();
// Checking an Empty List
int fullList(List L);
// Determining the first position of list.
Position first(List L);
// Determining the position after the last element of list
Position endList(List L);
// Inserting an Element
void insertList(ElementType x, Position P, List *pL);
// Deleting an Element
void deleteList(Position P, List *pL);
// Determining the previous position of P
Position next(Position P, List L);
// Determining the next position of P
Position previous(Position P, List L);
// Returning the element at position P of list L
ElementType retrieve(Position P, List L);
// Searching the Element x
Position locate(ElementType x, List L);
// Printing the Elements
void printList(List L);



int main()
{
	//1
	List L;
	readList(&L);
    return 0;
}


void readList(List* pL) {
	makenullList(pL);
	int n;
	printf("Nhap so phan tu muon cho vao : ");
	scanf("%d", &n);
	for (Position i = 1; i <= n; i++) {
		ElementType temp;
		printf("Nhap phan tu muon them vao : ");
		scanf("%d", &temp);
		insertList(temp, i, pL);
	}

}


List makenullList(List* pL)
{
  pL->Last=0;
}

int fullList(List L)
{
    return L.Last == MaxLength;
}

Position first(List L)
{
    return 1;
}

Position endList(List L)
{
    return L.Last + 1;
}

void insertList(ElementType x, Position P, List *pL)
{
    if (pL->Last == MaxLength)
        printf("List is full");
    else if ((P < 1) || (P > (pL->Last + 1)))
        printf("Position is invalid");
    else
    {
        Position Q;
        for (Q = pL->Last; Q >= P; Q--)
            pL->Elements[Q] = pL->Elements[Q - 1];
        pL->Elements[P - 1] = x;
        pL->Last++;
    }
}

void deleteList(Position P, List *pL)
{
    if ((P < 1) || (P > pL->Last))
        printf("Position is invalid");
    else if (&pL)
        printf("List is empty");
    else
    {
        Position Q;
        for (Q = P; Q < pL->Last; Q++)
            pL->Elements[Q - 1] = pL->Elements[Q];
        pL->Last--;
    }
}

Position next(Position P, List L)
{
    return P + 1;
}

Position previous(Position P, List L)
{
    return P - 1;
}

ElementType retrieve(Position P, List L)
{
    return L.Elements[P - 1];
}

Position locate(ElementType x, List L)
{
    Position P;
    int Found = 0;
    P = first(L);
    while ((P != endList(L)) && (Found == 0))
        if (retrieve(P, L) == x)
            Found = 1;
        else
            P = next(P, L);
    return P;
}

void printList(List L)
{
    Position P = 1;
    while (P != L.Last + 1)
    {
        printf("%d ", L.Elements[P - 1]);
        P = P + 1;
    }
    printf("\n");
}