#include <stdio.h>
#include <stdlib.h>

// the maximum size of list
#define MaxLength 100
// the element type of list
typedef int ElementType;
// the position type of elements
typedef int Position;

typedef struct {
    ElementType Elements[MaxLength]; // mảng bao gồm các phần tử của danh sách
    Position Last; // độ dài của danh sách
} List;

// Hàm khai báo
void makeNull(List *L);
int Len(List L);
int empty(List L);
int fullList(List L);
Position first(List L);
Position endList(List L);
Position next(Position P, List L);
ElementType getAt(Position P, List L);
void print(List L);
void setAt(Position P, ElementType x, List *L);
void insertAt(Position P, ElementType X, List *L);
ElementType popAt(Position P, List *L);
int insertFirst(ElementType x, List *L);
void popFirst(List *L);
void append(ElementType x, List *L);
void popLast(List *L);
Position locate(ElementType x, List L);
Position previous(Position p, List L);
void sort(List *L);

// Khởi tạo danh sách rỗng
void makeNull(List *L) {
    L->Last = 0;
}

// Trả về độ dài danh sách
int Len(List L) {
    return L.Last;
}

// Kiểm tra danh sách rỗng
int empty(List L) {
    return L.Last == 0;
}

// Kiểm tra danh sách đầy
int fullList(List L) {
    return L.Last == MaxLength;
}

// Trả về vị trí đầu tiên trong danh sách
Position first(List L) {
    return 1;
}

// Trả về vị trí cuối danh sách
Position endList(List L) {
    return L.Last + 1;
}

// Trả về vị trí kế tiếp
Position next(Position P, List L) {
    return P + 1;
}

// Trả về phần tử ở vị trí P
ElementType getAt(Position P, List L) {
    return L.Elements[P - 1];
}

// Duyệt qua danh sách để in ra tất cả các phần tử
void print(List L) {
    if (empty(L)) {
        printf("List is empty!\n");
        return;
    }
    if (fullList(L)) {
        printf("List is full!\n");
        return;
    }
    for (int i = first(L); i < endList(L); i++) {
        printf("%d ", L.Elements[i - 1]);
    }
    printf("\n");
}

// Thay đổi phần tử ở vị trí P bằng một giá trị mới x
void setAt(Position P, ElementType x, List *L) {
    if (P < 1 || P > Len(*L)) {
        printf("Error: Invalid position!\n");
        return;
    }
    L->Elements[P - 1] = x;
}

// Thêm x vào vị trí P
void insertAt(Position P, ElementType X, List *L) {
    if (fullList(*L)) {
        printf("List is full!\n");
        return;
    }
    if (P < 1 || P > L->Last + 1) {
        printf("Error: Invalid position!\n");
        return;
    }
    for (int i = L->Last; i >= P; i--) {
        L->Elements[i] = L->Elements[i - 1];
    }
    L->Elements[P - 1] = X;
    L->Last++;
}

// Xóa và trả về phần tử ở vị trí P
ElementType popAt(Position P, List *L) {
    if (empty(*L)) {
        printf("List is empty!\n");
        return -1; // Trả về giá trị không hợp lệ khi danh sách rỗng
    }
    if (P < 1 || P > L->Last) {
        printf("Error: Invalid position!\n");
        return -1; // Trả về giá trị không hợp lệ khi vị trí không hợp lệ
    }
    ElementType a = L->Elements[P - 1];
    for (int i = P - 1; i < L->Last - 1; i++) {
        L->Elements[i] = L->Elements[i + 1];
    }
    L->Last--;
    return a;
}

// Thêm x vào vị trí đầu tiên
int insertFirst(ElementType x, List *L) {
    if (fullList(*L)) {
        printf("List is full!\n");
        return 0;
    }
    insertAt(first(*L), x, L);
    return 1;
}

// Xóa và trả về phần tử đầu tiên
void popFirst(List *L) {
    popAt(first(*L), L);
}

// Thêm một phần tử mới vào cuối danh sách
void append(ElementType x, List *L) {
    if (fullList(*L)) {
        printf("List is full!\n");
        return;
    }
    L->Elements[L->Last] = x;
    L->Last++;
}

// Xóa và trả về phần tử cuối cùng
void popLast(List *L) {
    popAt(L->Last, L);
}

// Trả về vị trí xuất hiện đầu tiên của x trong danh sách
Position locate(ElementType x, List L) {
    for (Position p = first(L); p < endList(L); p++) {
        if (L.Elements[p - 1] == x) {
            return p;
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy
}

// Trả về vị trí trước đó của p trong danh sách
Position previous(Position p, List L) {
    return p - 1;
}

// Sắp xếp danh sách theo thứ tự tăng dần

void sort(List *L) {
    for (Position p = first(*L); p < endList(*L) - 1; p = next(p, *L)) {
        for (Position q = next(p, *L); q < endList(*L); q = next(q, *L)) {
            if (getAt(p, *L) > getAt(q, *L)) {
                ElementType temp = L->Elements[p - 1];
                L->Elements[p - 1] = L->Elements[q - 1];
                L->Elements[q - 1] = temp;
            }
        }
    }
}


// void swap(ElementType *x, ElementType *y)
// {
//     ElementType tmp = *x;
//     *x = *y;
//     *y = tmp;
// }



// void sort(List *L) {
//     for (Position p = first(*L); p < endList(*L) - 1; p = next(p, *L)) {
//         for (Position q = next(p, *L); q < endList(*L); q = next(q, *L)) {
//             if (getAt(p, *L) > getAt(q, *L)) {
//                 swap(&p,&q);
//             }
//         }
//     }
// }