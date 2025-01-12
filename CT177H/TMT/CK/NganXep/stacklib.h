#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef int ElementType;

typedef int Position;

typedef struct
{
    ElementType Elements[MaxSize];
    Position top;
} Stack;

void makeNull(Stack *S)
{
    S->top = -1;
}

ElementType isEmpty(Stack S)
{
    return S.top == -1;
}

int isFull(Stack S)
{
    return S.top == MaxSize - 1;
}

void push(ElementType X, Stack *S)
{
    if (isFull(*S))
    {
        printf("Stack is full");
        return;
    }
    else
    {
        S->top++;
        S->Elements[S->top] = X;
    }
}

ElementType pop(Stack *S)
{
    if (isEmpty(*S))
    {
        printf("Stack is empty");
        return -1;
    }
    else
    {
        return S->Elements[S->top--];
    }
}

void printStack(Stack S)
{
    if (isEmpty(S))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("stack: ");
        for (int i = 0; i <= S.top; i++)
        {
            printf("%d ", S.Elements[i]);
        }
        printf("\n");
    }
}