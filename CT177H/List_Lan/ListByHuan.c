#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int ElementType;
typedef int Position;
#define MAXLENGTH 200
typedef struct
{
	ElementType elements[MAXLENGTH];
	Position last;

} List;

void makenullList(List *pL)
{
	pL->last = 0;
}

int emptyList(List L)
{
	return L.last == 0;
}

int fullList(List L)
{
	return L.last == MAXLENGTH;
}

Position first(List L)
{
	return 1;
}

Position endList(List L)
{
	return L.last + 1;
}

void insertList(ElementType x, Position P, List *pL)
{
	if (P < 1 || P > pL->last + 1 || fullList(*pL))
	{
	}
	else
	{
		Position q;
		for (q = pL->last; q >= P; q--)
		{
			pL->elements[q] = pL->elements[q - 1];
		}
		pL->elements[P - 1] = x;
		pL->last++;
	}
}

void deleteList(Position P, List *pL)
{
	if (emptyList(*pL))
	{
	}
	else if (P < 1 || P > pL->last)
	{
	}
	else
	{
		for (Position i = P - 1; i < pL->last; i++)
		{
			pL->elements[i] = pL->elements[i + 1];
		}
		pL->last--;
	}
}

ElementType retrieve(Position P, List L)
{
	return L.elements[P - 1];
}

Position next(Position P, List L)
{
	return P + 1;
}

Position locate(ElementType x, List L)
{
	Position p = first(L);
	while (p != endList(L))
	{
		if (retrieve(p, L) == x)
		{
			return p;
		}
		p = next(p, L);
	}
	return endList(L);
}

void readList(List *pL)
{
	makenullList(pL);
	int n;
	printf("Nhap so phan tu muon cho vao : ");
	scanf("%d", &n);
	for (Position i = 1; i <= n; i++)
	{
		ElementType temp;
		printf("Nhap phan tu muon them vao : ");
		scanf("%d", &temp);
		insertList(temp, i, pL);
	}
}

void printList(List L)
{
	for (Position i = first(L); i < endList(L); i++)
	{
		printf("%d ", retrieve(i, L));
	}
	printf("\n");
}

Position previous(Position P, List L)
{
	return P - 1;
}

void deleteValue(ElementType x, List *pL)
{
	Position P = locate(x, *pL);
	while (P != endList(*pL))
	{
		deleteList(P, pL);
		P = locate(x, *pL);
	}
}

float getAverage(List L)
{
	float sum = 0;
	for (Position P = first(L); P != endList(L); P = next(P, L))
	{
		sum += retrieve(P, L);
	}
	return sum / L.last;
}

void split(List *L, List *L1, List *L2)
{
	makenullList(L1);
	makenullList(L2);

	Position P = first(*L);
	while (P != endList(*L))
	{
		ElementType val = retrieve(P, *L);
		if (val % 2 != 0)
		{
			insertList(val, endList(*L1), L1);
		}
		else
		{
			insertList(val, endList(*L2), L2);
		}
		P = next(P, *L);
	}
}

int main()
{
	// 1
	List L;
	readList(&L);

	// 2
	printList(L);

	// 3
	ElementType x;
	printf("Hay nhap x de xoa : ");
	scanf("%d", &x);
	deleteValue(x, &L);

	// 4
	printf("Trung binh : %f\n", getAverage(L));

	// 5
	List L1, L2;
	split(&L, &L1, &L2);
	printList(L1);
	printList(L2);
}