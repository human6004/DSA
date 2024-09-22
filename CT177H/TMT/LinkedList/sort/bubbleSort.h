#include"LinkedList"
#include<stdio.h>


void bubbleSort(List *L) {
    if (*L == NULL || (*L)->next == NULL) {
        return; // Danh sách rỗng hoặc chỉ có một phần tử, không cần sắp xếp
    }
    
    int swapped;
    PNode ptr1;
    PNode lptr = NULL; // Dùng để đánh dấu phần tử đã được sắp xếp

    do {
        swapped = 0;
        ptr1 = *L;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Hoán đổi dữ liệu giữa hai phần tử
                ElementType temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                
                swapped = 1; // Đánh dấu đã có sự hoán đổi
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
         /* Giảm bớt phạm vi của danh sách sau mỗi lần lặp,
          cập nhận next của lptr sau mỗi lần lặp là đia chỉ của phẩn tử đã đã được sắp xếp
          (để bỏ qua phần tử cuối đã đc sắp xếp-> tối ưu hiệu suất)
                            */

    } while (swapped);
}