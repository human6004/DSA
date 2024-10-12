#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxLength 10
typedef int ElementType;
typedef struct
{
    ElementType Elements[MaxLength];
    int Front, Rear;
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
    Q->Front = -1;
    Q->Rear = -1;
}

ElementType isEmpty(Queue Q)
{
    return Q.Front == -1;
}

ElementType fullQueue(Queue Q)
{
    return (Q.Rear - Q.Front + 1) % MaxLength == 0;
}

ElementType sizeQueue(Queue Q)
{
    if (isEmpty(Q))
        return 0;
    if (Q.Front <= Q.Rear)
        return Q.Rear - Q.Front;
    return MaxLength - (Q.Front - Q.Rear);
}

void enQueue(ElementType x, Queue *Q)
{
    if (!fullQueue(*Q))
    {
        if (isEmpty(*Q))
        {
            Q->Front = 0;
            Q->Rear = 0;
        }
        Q->Elements[Q->Rear] = x;
        Q->Rear = (Q->Rear + 1) % MaxLength;
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
        ElementType rs = Q->Elements[Q->Front];
        Q->Front = (Q->Front + 1) % MaxLength;
        if (Q->Front == Q->Rear)
        {
            Q->Front = -1;
            Q->Rear = -1;
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
            printf("%d ", Q.Elements[(i + Q.Front) % MaxLength]);
        printf("\n");
    }
    else
    {
        printf("Hang doi rong!\n");
    }
}
