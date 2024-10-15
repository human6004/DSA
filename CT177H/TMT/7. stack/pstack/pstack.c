#include "pstack.h"
#include <stdio.h>


int main()
{
    Stack S;
    makeNull(&S);

    // Đẩy các phần tử vào ngăn xếp
    push(10, &S);
    push(20, &S);
    push(30, &S);

    // In ngăn xếp
    print(S);

    // Lấy phần tử ra khỏi ngăn xếp
    pop(&S);
    print(S);

    pop(&S);
    print(S);

    return 0;
}