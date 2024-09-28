#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node
{
    ElementType data;
    struct Node *Next;
} Node;

typedef Node *Stack;

void makeNull(Stack *S); // Khởi tạo một ngăn xếp trống

ElementType isEmpty(Stack S); // Kiểm tra xem một ngăn xếp có trống

void push(ElementType x, Stack *S); // Đẩy x lên trên cùng

ElementType pop(Stack *S); // Trả về phần tử ở trên cùng và loại bỏ nó

void print(Stack S); // in ra

void to_binary(int n); // nhi phân

int calFibo(int n); // Hàm tính số Fibonacci

int calC(int k, int n); // tổ hợp

// int Fibonacci(int n)
// {
// if (n == 1 || n == 2)
// return 1;
// return Fibonacci(n - 1) + Fibonacci(n - 2);
// }

// int C(int k, int n) {
// if (k == 0 || k == n) return 1;
// if (k == 1) return n;
// return C(k - 1, n - 1) + C(k, n - 1);
int main()
{
    int n = 10;
    to_binary(n);

    printf("so  fibo thu %d la: %d\n", n, calFibo(n)); // In ra kết quả

    printf("top hop chap %d cua %d la: %d.\n", 3, 4, calC(3, 4));

    return 0;
}

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
    temp->Next = (*S)->Next; // truyền phần tử vào đầu stack
    (*S)->Next = temp;
}

// ElementType pop(Stack *S){
//     ElementType value = (*S)->Next->data;
//     Stack del = (*S)->Next;
//     (*S)->Next = del;
//     free(del);
//     return value;
// }

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

// Hàm in toàn bộ danh sách (ngăn xếp)
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

// Hàm chuyển đổi số nguyên sang nhị phân và in nó ra
void to_binary(int n)
{
    printf("%d -> ", n);
    Stack s;
    makeNull(&s);
    if (n == 0)
    {
        push(0, &s); // Nếu số là 0, đẩy 0 vào ngăn xếp
    }
    else
    {
        while (n != 0)
        {
            push(n % 2, &s); // Đẩy phần dư vào ngăn xếp (n % 2)
            n /= 2;          // Chia n cho 2
        }
    }

    // In ra các phần tử nhị phân từ ngăn xếp
    while (!isEmpty(s))
    {
        printf("%d", pop(&s)); // Lấy phần tử từ đỉnh ngăn xếp và in ra
    }
    printf("\n");
}

int calFibo(int n)
{
    Stack s;
    makeNull(&s);
    push(n, &s);
    int rs = 0;
    while (!isEmpty(s))
    {
        int temp = pop(&s);
        if (temp > 2)
        {
            push(temp - 2, &s);
            push(temp - 1, &s);
        }
        else
            rs += 1;
    }
    return rs;
}

// tổ hợp
int calC(int k, int n)
{
    Stack ks;
    makeNull(&ks);
    Stack ns;
    makeNull(&ns);
    int rs = 0;
    push(k, &ks);
    push(n, &ns);
    while (!(isEmpty(ks) && isEmpty(ns)))
    {

        int tempK = pop(&ks);
        int tempN = pop(&ns);
        if (tempK == 0 || tempK == tempN)
            rs += 1;
        else if (tempK == 1)
            rs += tempN;
        else
        {
            push(tempK - 1, &ks);
            push(tempK, &ks);
            push(tempN - 1, &ns);
            push(tempN - 1, &ns);
        }
    }
    return rs;
}