#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;
typedef int Position;

typedef struct NodeTag
{
    ElementType data;
    struct NodeTag *next;
} Node;

typedef Node *List;
typedef Node *PNode;

void makeNull(List *L)
{
    Node *header = (Node *)malloc(sizeof(Node));
    header->next = NULL;
    (*L) = header;
}

int len(List L)
{
    int count = 0;
    List P = L;
    while (P != NULL)
    {
        count++;
        P = P->next;
    }
    return count;
}

int empty(List L)
{
    return L->next == NULL;
}

void print(List L)
{
    List header = L->next;
    while (header != NULL)
    {
        printf("%d ", header->data);
        header = header->next;
    }
    printf("\n");
}

ElementType getAt(Position p, List L)
{
    int n = len(L);
    if (p < 1 || p > n)
    {
        printf("Vị trí không hợp lệ\n");
        return -1;
    }

    List temp = L;
    for (int i = 1; i < p; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

PNode getPosition(Position p, List L)
{
    int n = len(L); // Khai báo và tính độ dài danh sách
    if (p < 1 || p > n)
    {
        printf("Vị trí không hợp lệ\n");
        return NULL;
    }

    PNode newHead = L;
    for (int i = 1; i < p; i++)
    {
        newHead = newHead->next;
    }
    return newHead;
}

PNode first(List L)
{
    List header = L;
    return header;
}

PNode end(List L)
{
    PNode P = L;
    while (P->next != NULL)
    {
        P = P->next;
    }
    return P;
}

void setAt(Position p, ElementType x, List *L)
{
    PNode posi = getPosition(p, *L);
    if (posi != NULL)
    {
        posi->data = x;
    }
}

void insertAt(Position p, ElementType x, List *L)
{
    List newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    List temp = *L;
    for (int i = 1; i < p; i++) // p-1
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

ElementType popAt(Position p, List *L)
{
    if (*L == NULL || p <= 0)
    {
        printf("vi tri khong hop le");
        return -1;
    }
    List temp = *L;
    for (int i = 1; i < p - 1; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        return -1;
    }

    List del = temp->next;
    ElementType data = del->data;
    temp->next = del->next;
    free(del);
    return data;
}

void insertFirst(ElementType x, List *L)
{
    List newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = (*L)->next;
    (*L)->next = newNode;
}

ElementType popFirst(List *L)
{
    if (*L == NULL)
    {
        return -1;
    }

    List temp = *L;
    ElementType data = (*L)->next->data;
    *L = (*L)->next;
    free(temp);
    return data;
}

void append(ElementType x, List *L)
{
    insertAt(len(*L), x, L);
}

ElementType popLast(List *L)
{
    ElementType value;
    PNode posLast = *L;
    while (posLast->next->next != NULL)
    {
        posLast = posLast->next;
    }
    value = posLast->next->data;
    popAt(len(*L), L);
}

Position locate(ElementType x, List L)
{
    List temp = L->next;
    int count = 1;
    while (temp != NULL)
    {
        if (x == temp->data)
        {
            return count;
        }
        temp = temp->next;
        count++;
    }
    return -1;
}

PNode next(Position p, List L)
{
    if (p < 1 || p > len(L))
    {
        printf("Vị trí không hợp lệ\n");
        return NULL;
    }

    PNode temp = getPosition(p, L);
    if (temp != NULL)
    {
        return temp->next;
    }

    return NULL;
}

PNode previous(Position p, List L)
{
    List temp = L;
    for (int i = 1; i < p - 1; i++)
    {
        temp = temp->next;
    }
    return temp;
}
