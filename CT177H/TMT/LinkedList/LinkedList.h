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

void makeNull(List *L); // KHỞI TẠO DANH SÁCH RỖNG

int len(List L); // trả về đồ dài ds

int empty(List L); // KIỂM TRA DANH SÁCH RỖNG

int fullList(List L); // KIỂM TRA DANH SÁCH ĐẦY

Position first(List L); // trả về vị trí đầu tiên trong danh sách

Position end(List L); // trả về vị trí cuối danh sách

Position next(Position P, List L); // trả về vị trí kế tiếp

ElementType getAt(Position P, List L); // Trả về phần tử ở vị trí p

void print(List L); // Duyệt qua danh sách để in ra tất cả các phần tử

PNode getPosition(Position p, List L); // Trả về con trỏ trỏ đến phần tử thứ i

PNode first(List L); // trả về vị trí đầu tiên trong danh sách

PNode end(List L); // trả về vị trí cuối danh sách

void setAt(Position p, ElementType x, List *L); // Cập nhật phần tử ở vị trí p bằng một giá trị mới

void insertAt(Position p, ElementType x, List *L);// 

/*
Initialize an empty list
*/
void makeNull(List *L)
{
  Node *header = (Node *)malloc(sizef(Node)); // cấp phát động cho phần tử mới
  header->next = NULL;                        // cho phần tử mới next = NULL
  (*L) = header;
}

/*
return Number of elements
*/
int len(List L)
{
  int count = 0;
  List P = L;
  while (P != NULL)
  {
    count++;
    P = P->nextnext;
  }
  return count;
}

/*
Check whether the list is empty?
*/
int empty(List L)
{
  return L->next == NULL; // Kiểm tra danh sách có rỗng không
}

/*
Check whether the list is full?
*/
int fullList(List L)
{ // bỏ trống
}

/*
Traverse the list to print out all elements
*/
void print(List L)
{
  Node *current = L;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

/*
Return the element at position p
*/
ElementType getAt(Position p, List L)
{
  int n = len(L);
  if (p < 1 || p > n + 1)
  {
    printf("vi tri ko hop le");
    return -1;
  }
  Node *current = L;
  for (int i = 1; i <= p; i++)
  {
    current = current->next;
  }
  return current->data;
}

/*
Return the pointer referring to the ith element
*/
PNode getPosition(Position p, List L)
{
  PNode newHead = L;
  int n = len(L);
  if (p < 1 || p > n + 1)
  {
    printf("vi tri ko hop le");
    break;
  }
  for (int i = 1; i < p; i++)
  {
    newHead = newHead->next
  }
  return newHead;
}

/*
Return the pointer referring to the first element of L
*/
PNode first(List L)
{
  return L;
}

/*
Return the pointer referring to the last element of L
*/
PNode end(List L)
{
  PNode P = L;
  while (P->next != NULL)
  {
    P = P->next;
  }
  return P;
}

/*
Update the element at position p by a new value
*/
void setAt(Position p, ElementType x, List *L)
{
  PNode newHead = L;
  int n = len(L);
  if (p < 1 || p > n + 1)
  {
    printf("vi tri ko hop le");
  }
  for (int i = 1; i < p; i++)
  {
    newHead = newHead->next
  }
}

/*
Insert x at position p
*/
void insertAt(Position p, ElementType x, List *L)
{
  List 
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