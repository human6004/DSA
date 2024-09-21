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

void insertAt(Position p, ElementType x, List *L); // Thêm vào vị trí bất kỳ

ElementType popAt(Position p, List *L); // Xóa và trả về phần tử ở vị trí p

void insertFirst(ElementType x, List *L); // Chèn x vào vị trí đầu tiên

ElementType popFirst(List *L); // Xóa và trả về phần tử đầu tiên

void append(ElementType x, List *L); // Thêm một phần tử mới vào danh sách

ElementType popLast(List *L); // Xóa và trả về phần tử cuối cùng

Position locate(ElementType x, List L); // Trả về vị trí xuất hiện đầu tiên của x trong danh sách

PNode next(Position p, List L); // Trả về vị trí xuất hiện đầu tiên của x trong danh sách

PNode previous(Position p, List L); // Trả về con trỏ trỏ đến vị trí trước đó của p trong L

/*
Initialize an empty list
*/
void makeNull(List *L)
{
  Node *header = (Node *)malloc(sizeof(Node)); // cấp phát động cho phần tử mới
  header->next = NULL;                         // cho phần tử mới next = NULL
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
    P = P->next;
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
  List header = L;
  while (header->next != NULL)
  {
    printf("%d ", header->data);
    header = header->next;
  }
  printf("\n");
}

/*
Return the element at position p
*/
ElementType getAt(Position p, List L)
{
  int n = len(L); // Khai báo và tính độ dài của danh sách
  if (p < 1 || p > n)
  {
    printf("Vị trí không hợp lệ\n");
    return -1;
  }

  List temp = L;
  for (int i = 1; i < p; i++)
  {
    temp = temp->next;
  }
  return temp->data;
}

/*
Return the pointer referring to the ith element
*/
PNode getPosition(Position p, List L)
{
  int n = len(L); // Khai báo và tính độ dài danh sách
  if (p < 1 || p > n)
  {
    printf("Vị trí không hợp lệ\n");
    return NULL;
  }

  PNode newHead = L;
  for (int i = 1; i < p; i++)
  {
    newHead = newHead->next;
  }
  return newHead;
}

/*
Return the pointer referring to the first element of L
*/
PNode first(List L)
{
  List header = L;
  return header;
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
  PNode p = getPosition(p, *L);
  if (p != NULL)
  {
    p->data = x;
  }
}

/*
Insert x at position p
*/
void insertAt(Position p, ElementType x, List *L)
{
  List newNode = (List)malloc(sizeof(Node));
  newNode->data = x;
  List temp = *L;
  for (int i = 1; i < p - 1; i++)
  {
    temp = temp->next;
  }
  if (temp != NULL)
  {
    newNode->next = temp->next;
    temp->next = newNode;
  }
}
/*
Remove and return the element at position p
*/
ElementType popAt(Position p, List *L)
{
  if (*L == NULL || posi <= 0)
  {
    printf("vi tri khong hop le");
    return -1; // Vị trí không hợp lệ
  }
  List temp = *L; // khai báo biến tạm lưu cả ds
  for (int i = 1; i < posi - 1; i++)
  {                    // cho posi = 3
    temp = temp->next; // nếu i = 1 < 2 thì temp dịch sang phần tử tiếp theo
  }
  if (temp->next == NULL)
  {
    return -1; // Vị trí không tồn tại
  }

  List del = temp->next;
  ElementType data = del->data;
  temp->next = del->next;
  free(del); // xóa
  return data;
}

/*
Insert x to the first position
*/
void insertFirst(ElementType x, List *L)
{
  List newNode = (Node *)malloc(sizeof(Node));
  newNode->data = x;    // gán gtri cho node mới
  newNode->next = (*L); // cho node mới trỏ đến node đầu của ds
  (*L)->next = newNode; // cập nhật lại ds sau khi đã thêm node mới
}

/*
Remove and return the first element
*/
ElementType popFirst(List *L)
{
  if (*L == NULL)
  {
    return -1;
  }

  List temp = *L; // Danh sách hiện tại
  ElementType data = temp->data;
  *L = (*L)->next; // Cập nhật danh sách để bỏ qua phần tử đầu tiên
  free(temp);
  return data;
}
/*
Append a new element to the list
*/
void append(ElementType x, List *L)
{
  List newNode = (List)malloc(sizeof(Node));
  newNode->data = x;
  newNode->next = NULL;
  List temp = *L;
  while (temp != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

/*
Remove and return the last element
*/
ElementType popLast(List *L)
{
  if (*L == NULL || (*L)->next == NULL)
  {
    return -1; // Danh sách rỗng
  }
  List temp = L;
  while (temp->next->next != NULL)
  {
    temp = temp->next;
  }
  List last = temp->next;
  ElementType data = last->data;
  last->next = NULL;
  free(last);
  return data;
}

/*
Return the position of the first appearance of x in the list
*/
Position locate(ElementType x, List L)
{
  List temp = L->next;
  int count = 1;
  while (temp != NULL)
  {
    if (x == temp->data)
    {
      return count;
    }
    temp = temp->next;
    count++;
  }
  return -1;
}

/*
Return the pointer referring to the next position of i in L
*/
PNode next(Position p, List L)
{
  // Kiểm tra nếu vị trí p không hợp lệ
  if (p < 1 || p > len(L))
  {
    printf("Vị trí không hợp lệ\n");
    return NULL;
  }

  PNode temp = getPosition(p, L); // Lấy con trỏ đến vị trí p
  if (temp != NULL)
  {
    return temp->next; // Trả về phần tử kế tiếp
  }

  return NULL; // Trả về NULL nếu không có phần tử tiếp theo
}

/*
Return the pointer referring to the previous position of p in L
*/
PNode previous(Position p, List L)
{
  List temp = L->next;
  int count = 1;
  while (temp != NULL)
  {
    if (x == temp->data)
    {
      return count;
    }
    temp = temp->next;
    count++;
  }
  return -1;
}








// int main() {
//     List L;
//     makeNull(&L); // Khoi tao danh sach rong
//     int choice;
//     ElementType x;
//     Position p;

//     // Vong lap de hien thi menu va thuc hien cac thao tac
//     while (1) {
//         printf("\nMenu:\n");
//         printf("1. Them phan tu vao dau danh sach\n");
//         printf("2. Them phan tu vao cuoi danh sach\n");
//         printf("3. Lay phan tu tai vi tri p\n");
//         printf("4. Cap nhat phan tu tai vi tri p\n");
//         printf("5. In danh sach\n");
//         printf("6. Xoa phan tu tai vi tri p\n");
//         printf("7. Kiem tra danh sach rong\n");
//         printf("8. Do dai danh sach\n");
//         printf("0. Thoat\n");
//         printf("Nhap lua chon cua ban: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 // Them phan tu vao dau danh sach
//                 printf("Nhap gia tri can them vao dau danh sach: ");
//                 scanf("%d", &x);
//                 insertFirst(x, &L);
//                 printf("Da them %d vao dau danh sach.\n", x);
//                 break;

//             case 2:
//                 // Them phan tu vao cuoi danh sach
//                 printf("Nhap gia tri can them vao cuoi danh sach: ");
//                 scanf("%d", &x);
//                 append(x, &L);
//                 printf("Da them %d vao cuoi danh sach.\n", x);
//                 break;

//             case 3:
//                 // Lay phan tu tai vi tri p
//                 printf("Nhap vi tri p de lay phan tu: ");
//                 scanf("%d", &p);
//                 x = getAt(p, L);
//                 if (x != -1) {
//                     printf("Phan tu tai vi tri %d la: %d\n", p, x);
//                 }
//                 break;

//             case 4:
//                 // Cap nhat phan tu tai vi tri p
//                 printf("Nhap vi tri p de cap nhat: ");
//                 scanf("%d", &p);
//                 printf("Nhap gia tri moi: ");
//                 scanf("%d", &x);
//                 setAt(p, x, &L);
//                 printf("Da cap nhat phan tu tai vi tri %d thanh %d.\n", p, x);
//                 break;

//             case 5:
//                 // In danh sach
//                 printf("Danh sach hien tai: ");
//                 print(L);
//                 break;

//             case 6:
//                 // Xoa phan tu tai vi tri p
//                 printf("Nhap vi tri p de xoa phan tu: ");
//                 scanf("%d", &p);
//                 x = popAt(p, &L);
//                 if (x != -1) {
//                     printf("Da xoa phan tu tai vi tri %d voi gia tri %d.\n", p, x);
//                 }
//                 break;

//             case 7:
//                 // Kiem tra danh sach rong
//                 if (empty(L)) {
//                     printf("Danh sach rong.\n");
//                 } else {
//                     printf("Danh sach khong rong.\n");
//                 }
//                 break;

//             case 8:
//                 // Do dai danh sach
//                 printf("Do dai cua danh sach la: %d\n", len(L));
//                 break;

//             case 0:
//                 // Thoat chuong trinh
//                 printf("Thoat chuong trinh.\n");
//                 return 0;

//             default:
//                 printf("Lua chon khong hop le! Vui long chon lai.\n");
//                 break;
//         }
//     }
// }
