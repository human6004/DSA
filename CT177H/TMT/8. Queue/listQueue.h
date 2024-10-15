#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxLength 10
typedef int ElementType;
typedef struct
{
    ElementType Elements[MaxLength];
    int front, rear;
} Queue;

void makeNull(Queue *Q); // khởi tạo hàng đợi

ElementType isEmpty(Queue Q); // kiểm tra rỗng

ElementType fullQueue(Queue Q); // kiểm tra đầy

ElementType sizeQueue(Queue Q); // kiểm tra kích thước

void shiftLeft(int n, Queue *Q); // dịch về bên trái

void enQueue(ElementType x, Queue *Q); // thêm phần tử

ElementType deQueue(Queue *Q); // xóa phần tử

void printQueue(Queue Q); // in ra

void makeNull(Queue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}

ElementType isEmpty(Queue Q)
{
    return Q.front == Q.rear;
}

ElementType fullQueue(Queue Q)
{
    return (Q.rear - Q.front == MaxLength);
}

ElementType sizeQueue(Queue Q)
{
    return Q.rear - Q.front;
}

void shiftLeft(int n, Queue *Q)
{
    for (int i = 0; i < Q->rear - Q->front; i++)
        Q->Elements[i] = Q->Elements[n + i];
    Q->front = 0;
    Q->rear -= n;
}

void enQueue(ElementType x, Queue *Q)
{
    if (!fullQueue(*Q))
    {
        if (Q->front != 0 && Q->rear == MaxLength)
            shiftLeft(Q->front, Q);
        Q->Elements[Q->rear++] = x;
    }
    else

        printf("hang day!!!");
}

ElementType deQueue(Queue *Q)
{
    if (!isEmpty(*Q))
    {
        ElementType rs = Q->Elements[Q->front];
        if (Q->front == Q->rear - 1)
            makeNull(Q);
        else
            Q->front++;
        return rs;
    }
    else
        printf("Queue rong !!!");
    exit(EXIT_FAILURE);
}

void printQueue(Queue Q)
{
    if (!isEmpty(Q))
    {
        int size = sizeQueue(Q);
        for (int i = 0; i < size; i++)
            printf("%d", Q.Elements[Q.front + i]);
        printf("\n");
    }
}