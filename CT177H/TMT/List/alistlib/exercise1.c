#include "alistlib.h"
#include <stdio.h>





int main() {
    List L;
    makeNull(&L); // Khởi tạo danh sách rỗng

    int n, x;

    // Nhập số lượng phần tử
    printf("Nhap so luong phan tu trong danh sach: ");
    scanf("%d", &n);

    // Nhập các phần tử vào danh sách
    printf("Nhap cac phan tu:\n");
    for (int i = 1; i <= n; i++) {
        printf("Phan tu thu %d: ", i);
        scanf("%d", &x);
        append(x, &L); // Thêm phần tử vào cuối danh sách
    }

    // In danh sách trước khi sắp xếp
    printf("\nDanh sach truoc khi sap xep: ");
    print(L);

    // Sắp xếp danh sách theo thứ tự tăng dần
    sort(&L);

    // In danh sách sau khi sắp xếp
    printf("\nDanh sach sau khi sap xep: ");
    print(L);

    return 0;
}
