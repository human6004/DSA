#include "alistlib.h"


void menu(List *L);



int main() {
    List L;
    makeNull(&L); // Khoi tao danh sach rong
    menu(&L); // Goi ham menu
    return 0;
}


void menu(List *L) {
    int choice, position, element;

    while (1) {
        printf("\n\n____________________ MENU ____________________\n");
        printf("1.  Khoi tao danh sach rong (makeNull)\n");
        printf("2.  Kiem tra danh sach rong (empty)\n");
        printf("3.  Kiem tra danh sach day (fullList)\n");
        printf("4.  Them phan tu vao vi tri (InsertAt)\n");
        printf("5.  Xoa phan tu o vi tri (popAt)\n");
        printf("6.  Them phan tu vao dau danh sach (insertFirst)\n");
        printf("7.  Xoa phan tu dau tien (popFirst)\n");
        printf("8.  Them phan tu vao cuoi danh sach (append)\n");
        printf("9.  Xoa phan tu cuoi cung (popLast)\n");
        printf("10. Do dai danh sach (Len)\n");
        printf("11. Tra ve vi tri dau tien (first)\n");
        printf("12. Tra ve vi tri cuoi (end)\n");
        printf("13. Vi tri ke tiep (next)\n");
        printf("14. Tra ve phan tu tai vi tri (getAt)\n");
        printf("15. Thay doi phan tu tai vi tri (setAt)\n");
        printf("16. Tra ve vi tri truoc do (previous)\n");
        printf("17. In danh sach (print)\n");
        printf("18. Sap xep danh sach (sort)\n");
        printf("0.  Thoat\n");
        printf("_____________________________________________\n");

        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Thoat chuong trinh.\n");
                return;

            case 1:
                makeNull(L);
                printf("Danh sach da duoc khoi tao rong.\n");
                break;

            case 2:
                if (empty(*L)) {
                    printf("Danh sach rong.\n");
                } else {
                    printf("Danh sach khong rong.\n");
                }
                break;

            case 3:
                if (fullList(*L)) {
                    printf("Danh sach day.\n");
                } else {
                    printf("Danh sach chua day.\n");
                }
                break;

            case 4:
                printf("Nhap vi tri can chen: ");
                scanf("%d", &position);
                printf("Nhap gia tri can chen: ");
                scanf("%d", &element);
                InsertAt(position, element, L);
                break;

            case 5:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &position);
                printf("Phan tu da xoa: %d\n", popAt(position, L));
                break;

            case 6:
                printf("Nhap gia tri can them vao dau danh sach: ");
                scanf("%d", &element);
                insertFirst(element, L);
                break;

            case 7:
                popFirst(L);
                printf("Da xoa phan tu dau tien.\n");
                break;

            case 8:
                printf("Nhap gia tri can them vao cuoi danh sach: ");
                scanf("%d", &element);
                append(element, L);
                break;

            case 9:
                popLast(L);
                printf("Da xoa phan tu cuoi cung.\n");
                break;

            case 10:
                printf("Do dai cua danh sach la: %d\n", Len(*L));
                break;

            case 11:
                printf("Vi tri dau tien trong danh sach la: %d\n", first(*L));
                break;

            case 12:
                printf("Vi tri cuoi trong danh sach la: %d\n", end(*L));
                break;

            case 13:
                printf("Nhap vi tri hien tai: ");
                scanf("%d", &position);
                printf("Vi tri ke tiep la: %d\n", next(position, *L));
                break;

            case 14:
                printf("Nhap vi tri can lay phan tu: ");
                scanf("%d", &position);
                printf("Phan tu tai vi tri %d la: %d\n", position, getAt(position, *L));
                break;

            case 15:
                printf("Nhap vi tri can thay doi: ");
                scanf("%d", &position);
                printf("Nhap gia tri moi: ");
                scanf("%d", &element);
                setAt(position, element, L);
                break;

            case 16:
                printf("Nhap vi tri hien tai: ");
                scanf("%d", &position);
                printf("Vi tri truoc do la: %d\n", previous(position, *L));
                break;

            case 17:
                print(*L);
                break;

            case 18:
                sort(L);
                printf("Danh sach da duoc sap xep.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
                break;
        }
    }
    return;
}
