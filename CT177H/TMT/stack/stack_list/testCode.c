#include "stack_list.h"
#include <stdio.h>


int main() {
    Stack S;
    makeNull(&S);  // Khởi tạo ngăn xếp rỗng

    // Đẩy các phần tử vào ngăn xếp
    push(10, &S);
    push(20, &S);
    push(30, &S);

    // In danh sách các phần tử trong ngăn xếp
    printStack(S);

    // Lấy các phần tử ra khỏi ngăn xếp
    pop(&S);
    pop(&S);

    // In lại danh sách
    printStack(S);

    // Đẩy thêm phần tử vào ngăn xếp
    push(40, &S);
    
    // In lại danh sách
    printStack(S);

    return 0;
}