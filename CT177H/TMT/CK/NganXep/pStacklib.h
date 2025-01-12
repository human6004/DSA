#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node
{
    ElementType data;
    struct Node *Next;
} Node;

typedef Node *Stack;

void makeNull(Stack *S)
{
    Node *header = (Stack)malloc(sizeof(Node));
    header->Next = NULL;
    (*S) = header;
}

ElementType isEmpty(Stack S)
{
    return S->Next == NULL;
}

void push(ElementType x, Stack *S)
{
    Node *temp = (Stack)malloc(sizeof(Node));
    temp->data = x;
    temp->Next = (*S)->Next; // truyền node temp  vào đầu stack
    (*S)->Next = temp;       // gắn lại cho S
}

ElementType pop(Stack *S)
{
    if (isEmpty(*S))
    {
        printf("stack is empty\n");
        return -1; // Nếu ngăn xếp rỗng, trả về -1
    }

    Node *temp = (*S)->Next;
    ElementType value = temp->data;
    (*S)->Next = temp->Next;
    free(temp);
    return value;
}

void print(Stack S)
{
    printf("Stack : ");
    while (S->Next != NULL)
    {
        printf("%d ", S->Next->data);
        S = S->Next;
    }
    printf("\n");
}