#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next; // con trỏ node dùng để trỏ đến địa chỉ của node tiếp theo/ lưu địa chỉ của node tiếp theo
} node;

void duyet(node *head);
int size(node *head);
node *makeNode(int n);                  // tạo 1 node mới
void pushFront(node **head, int x);     // them node vao dau
void pushBack(node **head, int x);      // them node vao cuoi
void insert(node **head, int k, int x); // chen vao vi tri k trong DSLK
void deleFront(node **head);            // xóa phần tử ở vị trí đầu
void deleBack(node **head);             // xóa phần tử ở vị trí cuối


int main()
{
    node *head = NULL;
    while (1)
    {
        printf("___________________________________________\n\n");
        printf("1. them phan tu vao cuoi \n");
        printf("2. them phan tu vao dau\n");
        printf("3.chen phan tu vao giua\n");
        printf("4. xoa dau\n");
        printf("5. xoa giua\n");
        printf("6. xoa cuoi\n");
        printf("7. duyet DSLK\n");
        printf("0. exit!!!\n");
        printf("\n___________________________________________\n");
        printf("Enter selection: \n");
        int lc;
        scanf("%d", &lc);
        if (lc == 1)
        {
            printf("nhap gia tri can them: ");
            int x;
            scanf("%d", &x);
            pushBack(&head, x);
        }
        else if (lc == 2)
        {
            printf("nhap gia tri can them: ");
            int x;
            scanf("%d", &x);
            pushFront(&head, x);
        }
        else if (lc == 3)
        {
            printf("nhap vi tri chen: ");
            int k;
            scanf("%d", &k);
            printf("nhap gia tri can them: ");
            int x;
            scanf("%d", &x);
            insert(&head, k, x);
        }
        else if (lc == 4)
        {
            deleFront(&head);
        }


        else if(lc == 6){
            deleBack(&head);
        }

        else if (lc == 7)
        {
            duyet(head);
        }
        else if (lc == 0)
        {
            break;
        }
    }
    return 0;
}

void duyet(node *head)
{ // truy cập vào bộ nhớ đầu tiên của DSLK
    while (head != NULL)
    {
        printf("%d ", head->data);
        // dịch head sang node bên phải
        head = head->next; // dùng để tham chiếu đến địa chỉ của node tiếp theo trong DSLK
    }
    printf("\n");
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
{ // **node: truy cập vào địa chỉ của nút node trong DSLK
    node *newNode = makeNode(x);
    newNode->next = (*head); //* head: giải tham chiếu lấy địa chỉ của node hiện tại gán cho next của node mới
    (*head) = newNode;
}
void pushBack(node **head, int x)
{
    node *newNode = makeNode(x);
    node *tmp = *head;
    if (tmp == NULL)
    {
        *head = newNode;
        return;
    }
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}
void insert(node **head, int k, int x)
{
    int n = size(*head);
    if (k < 1 || k > n + 1)
    {
        printf("vi tri chen ko hop le!!!");
        return;
    }
    if (k == 1)
    {
        pushFront(head, x);
    }
    else if (k == n + 1)
    {
        pushBack(head, x);
    }
    else
    {
        node *temp = (*head);
        for (int i = 1; i < k - 1; i++)
        {
            temp = temp->next;
        }
        node *newNode = makeNode(x);
        // buoc 1;  phần next của newNode lưu địa chỉ/ trỏ vào node thứ k
        newNode->next = temp->next; // temp->next là node thứ k-1 nhưng mà nó đang lưu địa chỉ của node thứ k
        // lệnh trên có tác dụng là lấy địa chỉ của node thứ k thông qua node thứ k-1 được lưu ở biến temp
        // sau đó lưu địa chỉ của biến k vào biến newNode

        // bước 2: phần next cua node thứ K-1 lưu vào địa chỉ của node mới
        temp->next = newNode; // temp bây giờ sẽ lưu địa chỉ của nodeNew
    }
}

void deleFront(node **head)
{
    if (*head == NULL)
        return;
    node *temp = *head;    // dia chi dau tien trong DSLK
    *head = (*head)->next; // head truy cap vao node thu 2 cua DSLK
    free(temp);            // giai phong bo nho cua phan tu dau tien
};

void deleBack(node **head){
    if(*head == NULL){
       return; 
    } 
    node *temp = (*head);
    if(temp->next == NULL)//neu trong DSLK co 1 phan tu --> xoa phan tu do
    {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next->next != NULL)//truy cập đến địa chỉ kế bên địa chỉ cuối cùng
    {
        temp = temp->next;// đến địa chỉ kế bên địa chỉ cuối cùng -> vòng lặp kết thúc
    }
    node *last = temp->next;//truy cập đến địa chỉ cuối cùng
    temp->next =NULL;//cho next của địa chỉ cuối cùng mới của DSLK = null khi mà xóa địa cuối cũ
    free(last);//giải phóng bộ nhớ của địa chỉ cuối cũ
}
