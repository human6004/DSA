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


void makeNull(Stack *S);// Khởi tạo một ngăn xếp trống

int isEmpty(Stack S);// Kiểm tra xem một ngăn xếp có trống

int isFull(Stack S);// Kiểm tra xem ngăn xếp đã đầy chưa?

void push(ElementType x,Stack *S);// Thêm phần tử X vào đỉnh ngăn xếp S / Đẩy x lên trên cùng

ElementType pop(Stack *S);// Trả về phần tử ở trên cùng và loại bỏ nó


// Khởi tạo một ngăn xếp trống
void makeNull(Stack *S){
    S->top =-1;
}

// Kiểm tra xem một ngăn xếp có trống
ElementType isEmpty(Stack S){
    return S.top == -1;
}

// Kiểm tra xem ngăn xếp đã đầy chưa?
int isFull(Stack S){
    return S.top == MaxSize-1;
}

// Thêm phần tử X vào đỉnh ngăn xếp S
void push(ElementType X, Stack *S){
    if(isFull(*S)){
        printf("Stack is full");
        return;
    }
    else{
        S->top++;
        S->Elements[S->top] = X;
    }
}

// Trả về phần tử ở trên cùng và loại bỏ nó
ElementType pop(Stack *S ){
    if(isEmpty(*S)){
        printf("Stack is empty");
        return -1;
    }
    else{
        return S->Elements[S->top--];
    }
}

// Hàm in toàn bộ danh sách (ngăn xếp)
void printStack(Stack S) {
    if (isEmpty(S)) {
        printf("Stack is empty\n");
    } else {
        printf("stack: ");
        for (int i = 0; i <= S.top; i++) {
            printf("%d ", S.Elements[i]);
        }
        printf("\n");
    }
}