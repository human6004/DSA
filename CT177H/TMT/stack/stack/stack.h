#include <stdio.h>
#include <stdlib.h>

// the maximum size of list
#define MaxSize 100
// the element type of list
typedef int ElementType;
// the position type of elements
typedef int Position;

typedef struct
{
    ElementType Elements[MaxSize];// mảng bao gồm các phần tử của danh sách
    Position top;// độ dài của danh sách
} Stack;

Stack S;

void makeNull(Stack *S);

int isEmpty(Stack S);

int isFull(Stack S);

pop(Stack *S);


void makeNull(Stack *S){
    S->top =-1;
}

int isEmpty(Stack S){
    return S.top == -1;
}

int isFull(Stack S){
    return S.top == MaxSize-1;
}

