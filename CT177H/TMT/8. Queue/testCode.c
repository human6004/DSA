#include <stdio.h>
// #include "listQueue.h"
#include "circleQueue.h"
// #include "linkedQueue.h"

int main(int argc, char const *argv[])
{
    Queue q;
    makeNull(&q);
    enQueue(1, &q);
    enQueue(2, &q);
    enQueue(3, &q);
    enQueue(4, &q);
    enQueue(5, &q);
    printQueue(q);
    printf("de: %d\n", deQueue(&q));
    printf("de: %d\n", deQueue(&q));
    printf("de: %d\n", deQueue(&q));
    printf("de: %d\n", deQueue(&q));
    printQueue(q);
    enQueue(5, &q);
    enQueue(6, &q);
    enQueue(6, &q);
    enQueue(6, &q);
    printf("add 5,6,6,6:\n");
    printf("size: %d\n",sizeQueue(q));
    printQueue(q);
    printf("de: %d\n", deQueue(&q));
    printf("de: %d\n", deQueue(&q));
    printf("de: %d\n", deQueue(&q));
    printf("de: %d\n", deQueue(&q));
    printf("de: %d\n", deQueue(&q));
    printQueue(q);
    enQueue(5, &q);
    enQueue(6, &q);
    enQueue(6, &q);
    enQueue(6, &q);
    enQueue(7, &q);
    printf("add 5,6,6,6,7:\n");
    printQueue(q);

     return 0;
}