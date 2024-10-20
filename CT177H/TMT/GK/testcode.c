#include <stdio.h>
#include <stdlib.h>
#include "bainop.h"
// Bao gồm toàn bộ mã nguồn danh sách từ trên

int main() {
    List L;
    makeNull(&L);  // Tao danh sach rong
    
    // Kiem tra danh sach rong
    printf("Danh sach rong? %s\n", empty(L) ? "Yes" : "No");
    
    // Them phan tu vao danh sach
    append(10, &L);
    append(20, &L);
    append(30, &L);
    printf("Danh sach sau khi them 10, 20, 30: ");
    print(L);

    // Chen phan tu vao vi tri dau
    insertFirst(5, &L);
    printf("Danh sach sau khi chen 5 vao vi tri dau: ");
    print(L);

    // Chen phan tu vao vi tri giua
    insertAt(3, 15, &L);
    printf("Danh sach sau khi chen 15 vao vi tri thu 3: ");
    print(L);
    
    // Xoa phan tu dau
    popFirst(&L);
    printf("Danh sach sau khi xoa phan tu dau: ");
    print(L);
    
    // Xoa phan tu cuoi
    popLast(&L);
    printf("Danh sach sau khi xoa phan tu cuoi: ");
    print(L);
    
    // Xoa phan tu o vi tri cu the
    popAt(2, &L);
    printf("Danh sach sau khi xoa phan tu o vi tri thu 2: ");
    print(L);

    // Tim vi tri cua mot phan tu
    Position pos = locate(20, L);
    printf("Vi tri cua 20 trong danh sach: %d\n", pos);

    // Kiem tra danh sach day
    printf("Danh sach day? %s\n", fullList(L) ? "Yes" : "No");

    // Cap nhat phan tu tai vi tri
    setAt(1, 100, &L);
    printf("Danh sach sau khi cap nhat vi tri 1 thanh 100: ");
    print(L);

    // Lay do dai danh sach
    printf("Do dai danh sach: %d\n", len(L));

    return 0;
}