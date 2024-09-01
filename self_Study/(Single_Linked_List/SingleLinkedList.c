#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next; // con trỏ node dùng để trỏ đến địa chỉ của node tiếp theo/ lưu địa chỉ của node tiếp theo
} node;
void duyet(node *head)
{ // truy cập vào bộ nhớ đầu tiên của DSLK
    while (head != NULL)
    {
        printf("%d ", head->data);
        // dịch head sang node bên phải
        head = head->next; // dùng để tham chiếu đến địa chỉ của node tiếp theo trong DSLK
    }
}
int size(node *head)
{ // truy cập vào bộ nhớ đầu tiên của DSLK
    int count = 0;
    while (head != NULL)
    {
        count++;
        // dịch head sang node bên phải
        head = head->next; // dùng để tham chiếu đến địa chỉ của node tiếp theo trong DSLK
    }
    return count; // đếm số lượng phần tử có trong mảng
}
node *makeNode(int n)
{
    // cấp phát 1 dòng node
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}
// thêm node vào đầu DSLK
// pushFront: lm thay đổi DSLK đc quản lí bởi nút head
void pushFront(node **head, int x)
{// **node: truy cập vào địa chỉ của nút node trong DSLK
    node *newNode = makeNode(x);
    newNode->next = (*head);//* head: giải tham chiếu lấy địa chỉ của node hiện tại gán cho next của node mới
    (*head) = newNode;
}
int main(){
    node *head = NULL;
    pushFront(&head,1);
    pushFront(&head,2);
    pushFront(&head,3);
    pushFront(&head,4);
    pushFront(&head,5);
    pushFront(&head,6);
    duyet(head);
    return 0;
}
