#include "LinkedList.h"
// #include "listlib.h"
#include <stdio.h>

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