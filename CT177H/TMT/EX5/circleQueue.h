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
    // return (Q.rear - Q.front + 1) % MaxLength == 0;
    
    return (Q.rear + 1) % MaxLength == Q.front;
}

ElementType sizeQueue(Queue Q)
{
    if (fullQueue(Q))
        return MaxLength;  // Hàng đợi đầy
    return (Q.rear + MaxLength - Q.front) % MaxLength;
}

void enQueue(ElementType x, Queue *Q)
{
    if (!fullQueue(*Q))
    {
        if (isEmpty(*Q))
        {
            Q->front = 0;
            Q->rear = 0;
        }
        Q->Elements[Q->rear] = x;
        Q->rear = (Q->rear + 1) % MaxLength;
    }
    else
    {
        printf("Loi: Hang day!\n", x);
        exit(EXIT_FAILURE);
    }
}

ElementType deQueue(Queue *Q)
{
    if (!isEmpty(*Q))
    {
        ElementType rs = Q->Elements[Q->front];
        Q->front = (Q->front + 1) % MaxLength;
        if (Q->front == Q->rear)
        {
            Q->front = -1;
            Q->rear = -1;
        }
        return rs;
    }
    printf("loi: hang rong!!!\n");
    exit(EXIT_FAILURE);
}

void printQueue(Queue Q)
{
    if (!isEmpty(Q))
    {
        int sz = sizeQueue(Q);
        for (int i = 0; i < sz; i++)
            printf("%d ", Q.Elements[(i + Q.front) % MaxLength]);
        printf("\n");
    }
    else
    {
        printf("Hang doi rong!\n");
    }
}
