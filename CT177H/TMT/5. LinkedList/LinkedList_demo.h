#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;
typedef int Position;

typedef struct NodeTag
{
    ElementType data;
    struct NodeTag *next;
} Node;

typedef Node *List;
typedef Node *PNode;

void makeNull(List *L);                         // Khởi tạo danh sách rỗng
int len(List L);                                // Trả về độ dài danh sách
int empty(List L);                              // Kiểm tra danh sách rỗng
Position first(List L);                         // Trả về vị trí đầu tiên
Position end(List L);                           // Trả về vị trí cuối cùng
ElementType getAt(Position P, List L);          // Trả về phần tử tại vị trí P
PNode getPosition(Position p, List L);          // Trả về con trỏ trỏ đến phần tử thứ i
void print(List L);                             // In ra các phần tử trong danh sách
void setAt(Position p, ElementType x, List *L); // Cập nhật giá trị ở vị trí p

void makeNull(List *L)
{
    Node *header = (Node *)malloc(sizeof(Node)); // Cấp phát bộ nhớ cho nút đầu
    header->next = NULL;                         // Khởi tạo danh sách rỗng
    *L = header;
}

int len(List L)
{
    int count = 0;
    Node *current = L;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int empty(List L)
{
    return L->next == NULL; // Kiểm tra danh sách có rỗng không
}

ElementType getAt(Position p, List L)
{
    int n = len(L);
    if (p < 1 || p > n)
    {
        printf("Vị trí không hợp lệ\n");
        return -1; // Giá trị báo lỗi
    }
    Node *current = L->next; // Bỏ qua phần tử header
    for (int i = 1; i < p; i++)
    {
        current = current->next;
    }
    return current->data;
}

PNode getPosition(Position p, List L)
{
    int n = len(L);
    if (p < 1 || p > n)
    {
        printf("Vị trí không hợp lệ\n");
        return NULL; // Trả về NULL nếu vị trí không hợp lệ
    }
    PNode current = L->next; // Bỏ qua phần tử header
    for (int i = 1; i < p; i++)
    {
        current = current->next;
    }
    return current;
}

void print(List L)
{
    Node *current = L->next; // Bỏ qua phần tử header
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void setAt(Position p, ElementType x, List *L)
{
    PNode current = getPosition(p, *L);
    if (current != NULL)
    {
        current->data = x;
    }
}

/*
Insert x at position p
*/
void insertAt(Position p, ElementType x, List *L)
{
    PNode *newNode = (PNode *)malloc(sizeof(node));
    newNode->data = x;
    newNode.
}
/*
Remove and return the element at position p
*/
ElementType popAt(Position p, List *L)
{
}

/*
Insert x to the first position
*/
void insertFirst(ElementType x, List *L)
{
}

/*
Remove and return the first element
*/
ElementType popFirst(List *L)
{
}
/*
Append a new element to the list
*/
void append(ElementType x, List *L)
{
}

/*
Remove and return the last element
*/
ElementType popLast(List *L)
{
}

/*
Return the position of the first appearance of x in the list
*/
Position locate(ElementType x, List L)
{
}

/*
Return the pointer referring to the next position of i in L
*/
PNode next(Position p, List L)
{
}

/*
Return the pointer referring to the previous position of p in L
*/
PNode previous(Position p, List L)
{
}