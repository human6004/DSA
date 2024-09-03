
#include "alistlib.h"

int main (){
    List L;
    makeNull(&L);

    int n;
    printf ("Nhap vao so luong phan tu cua ds: ");
    scanf ("%d", &n);

    printf ("Nhap cac phan tu: ");
    for (int i = 1; i <=n ;i++){
        int x; scanf("%d", &x);
        InsertAt(i, x, &L);
    }

    print(L);
    printf ("\n");
    sort(&L);
    print(L);
    return 0;

}