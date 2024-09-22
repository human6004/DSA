#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef int Position;
typedef struct NodeTag{
    ElementType data;
    struct NodeTag *next;
}Node;

typedef Node *List;
typedef Node* PNode;

//khởi tạo ds rỗng
void makeNull (List *L){
     Node*header;
    header = ( Node*)malloc(sizeof(Node));
    header->next = NULL;
    (*L) = header;
}

//trả về vị trí đầu tiên
PNode first (List L){
    List header = L;
    return header;
}


//trả về vị trí cuối cùng
PNode endList(List L){
    List header = L;
    while(header->next != NULL){
        header = header->next;
    }
    return header;
}


//trả về vị trí kế tiếp
PNode next(List L){
    List header = L;
    return header->next;
}


//tính độ dài của danh sách
int len(List L){
    List header = L;
    int count = 0;
    while(header->next != NULL){
        count++;
        header = header->next;
    }
    return count;
}


//check danh sách rỗng
int empty(List L){
    return L->next == NULL;
}


//check danh sách đầy
//int fullList(List L){}



//trả về phần tử ở vị trí p
// int retrieve(Position header, List L){
//     if(header->next != NULL){
//         return header->next->data;
//     }
// }


//in ra danh sách
void print(List L){
    List header = L;
    while(header->next != NULL){
        printf("%d ", header->next->data);
        header= header->next;
    }
    printf ("\n");
}


//Trả về con trỏ trỏ đến vị trí p trong ds
PNode getPosition (int posi, List L){
    List header = L;
    int count = 0;
    while(header->next != NULL){
        count++;
        if(count == posi){
            return header;
        }
        else{
            return header = header->next;
        }
    }
    return header;
}


//Trả về giá trị ở vị trí p
int getAt(int posi, List L){
    List temp = L->next;
    for(int i = 1; i < posi; i++){
        if(temp->next == NULL){
            return -1;
        }
        temp = temp->next;
    }
    return temp->data;
}


//Thay đổi phần tử ở vị trí p bằng 1 giá trị x mới
void setAt(ElementType x, int posi, List *L){
    PNode p = getPosition(posi, *L);
    if (p != NULL){
        p->data = x;
        
    }
}



//Thêm vào vị trí đầu tiên
void insertFirst (ElementType x, List *L){
    List newNode = ( Node*)malloc(sizeof( Node));
    newNode->data = x;  //gán gtri cho node mới
    newNode->next = (*L)->next;  //cho node mới trỏ đến node đầu của ds
    (*L)->next = newNode;        //cập nhật lại ds sau khi đã thêm node mới
}


//Xóa vị trí đầu tiên
ElementType popFirst(List *L){
    if (*L == NULL || (*L)->next == NULL) {
        return -1; // Danh sách rỗng
    }
    Node* temp = (*L)->next;
    ElementType data = temp->data;
    (*L)->next = temp->next;
    free(temp);
    return data;
}


//Thêm vào vị trí bất kỳ
void insertAt(Position posi, ElementType x, List *L){
    List newNode = ( Node*)malloc(sizeof( Node));
    newNode->data = x;
    List temp = *L;
    for(int i = 1; i < posi-1; i++){
        temp = temp->next;
    }
    if(temp != NULL){
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


//Xóa vị trí bất kỳ
ElementType popAt(Position posi, List *L){
    if (*L == NULL || posi <= 0) {
        return -1; // Vị trí không hợp lệ
    }
    List temp = *L; //khai báo biến tạm lưu cả ds
    for(int i = 1; i <posi - 1; i++){  //cho posi = 3
        temp = temp ->next; //nếu i = 1 < 2 thì temp dịch sang phần tử tiếp theo
    }
    if (temp->next == NULL) {
        return -1; // Vị trí không tồn tại
    }

    List del = temp->next; 
    ElementType data = del->data;
    temp->next = del->next;
    free(del); //xóa
    return data;
}


//Xóa vị trí cuối cùng
ElementType popLast(List *L){
    if (*L == NULL || (*L)->next == NULL) {
        return -1; // Danh sách rỗng
    }
    List temp = *L;
    while(temp->next->next != NULL){
        temp= temp->next;
    }
    List last = temp->next;
    ElementType data = last->data;
    last->next = NULL;
    free(last);
    return data;
}


//Thêm 1 phần tử mới vào cuối danh sách
void append(int x, List *L){
    List newNode = ( Node*)malloc(sizeof( Node));
    newNode->data = x;
    newNode->next = NULL;
    List temp = *L;
    while(temp != NULL){
        temp = temp->next;
    }
        temp->next = newNode;
}


//trả về vị trí xuất hiện đầu tiên của x
Position locate(ElementType x, List L){
    List temp = L->next;
    int count = 1;
    while(temp != NULL){
        if(x == temp->data){
            return count;
        }
        temp = temp->next;
        count++;
    }
    return -1;
}


//Trả về con trỏ tham chiếu đến vị trí trước đó của p trong L
PNode previous(Position p, List L){
    List temp = L;
    for(int i = 1; i < p-1; i++){
        temp = temp->next;
    }
    return temp;
}


int main() {
    List L;
    makeNull(&L); // Khoi tao danh sach rong

    int choice, x, pos;

    while(1) {
        printf("\n---MENU---\n");
        printf("1. Them vao dau danh sach\n");
        printf("2. Them vao cuoi danh sach\n");
        printf("3. Them vao vi tri bat ky\n");
        printf("4. Xoa phan tu dau tien\n");
        printf("5. Xoa phan tu cuoi cung\n");
        printf("6. Xoa phan tu o vi tri bat ky\n");
        printf("7. In danh sach\n");
        printf("8. Tim vi tri phan tu dau tien bang gia tri x\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Them phan tu vao dau danh sach
                printf("Nhap gia tri can them: ");
                scanf("%d", &x);
                insertFirst(x, &L);
                break;

            case 2:
                // Them phan tu vao cuoi danh sach
                printf("Nhap gia tri can them: ");
                scanf("%d", &x);
                append(x, &L);
                break;

            case 3:
                // Them phan tu vao vi tri bat ky
                printf("Nhap gia tri can them: ");
                scanf("%d", &x);
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                insertAt(pos, x, &L);
                break;

            case 4:
                // Xoa phan tu dau tien
                x = popFirst(&L);
                if (x == -1)
                    printf("Danh sach rong!\n");
                else
                    printf("Phan tu da xoa: %d\n", x);
                break;

            case 5:
                // Xoa phan tu cuoi cung
                x = popLast(&L);
                if (x == -1)
                    printf("Danh sach rong!\n");
                else
                    printf("Phan tu da xoa: %d\n", x);
                break;

            case 6:
                // Xoa phan tu o vi tri bat ky
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                x = popAt(pos, &L);
                if (x == -1)
                    printf("Vi tri khong hop le!\n");
                else
                    printf("Phan tu da xoa: %d\n", x);
                break;

            case 7:
                // In danh sach
                printf("Danh sach hien tai: ");
                print(L);
                break;

            case 8:
                // Tim vi tri phan tu dau tien bang gia tri x
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);
                pos = locate(x, L);
                if (pos == -1)
                    printf("Khong tim thay gia tri trong danh sach\n");
                else
                    printf("Gia tri xuat hien dau tien tai vi tri: %d\n", pos);
                break;

            case 9:
                // Thoat chuong trinh
                printf("Thoat chuong trinh...\n");
                exit(0);

            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
                break;
        }
    }

    return 0;
}





