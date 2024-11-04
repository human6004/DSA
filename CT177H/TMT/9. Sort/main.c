#include "sort.h"

int main() {
    List L;
    makeNull(&L);

    int a[] = {3, 7, 8, 5, 4, 2, 6, 1};
    int b[] = {100, 3, 2, 5, 44, 12, 9, 8, 10, 6, 10, 11};
    int c[] = {110};
    int d[] = {0};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int o = sizeof(c) / sizeof(c[0]);
    int p = sizeof(d) / sizeof(d[0]);

    printf("--------------------------------------------------------------------\n");
    
    // Test 1
    printf("Test 1:\n");
    readList(a, n, &L);
    print(L);
    printf("Length of list: %d\n", len(L));
    insertionSort(&L); // Hoặc bất kỳ hàm sắp xếp nào khác
    print(L);

    printf("\n--------------------------------------------------------------------\n");
    makeNull(&L);
    
    // Test 2
    printf("Test 2:\n");
    readList(b, m, &L);
    print(L);
    printf("Length of list: %d\n", len(L));
    insertionSort(&L);
    print(L);

    printf("\n--------------------------------------------------------------------\n");
    makeNull(&L);
    
    // Test 3
    printf("Test 3:\n");
    readList(c, o, &L);
    print(L);
    printf("Length of list: %d\n", len(L));
    insertionSort(&L);
    print(L);

    printf("\n--------------------------------------------------------------------\n");
    makeNull(&L);
    
    // Test 4
    printf("Test 4:\n");
    readList(d, p, &L);
    print(L);
    printf("Length of list: %d\n", len(L));
    insertionSort(&L);
    print(L);

    return 0;
}
