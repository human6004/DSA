
#include "alistlib.h"

int main()
{
    List L;
    makeNull(&L);

    int n;
    printf("Nhap vao so luong phan tu cua ds: ");
    scanf("%d", &n);
    printf("Nhap cac phan tu: ");
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        InsertAt(i, x, &L);
    }

    while (1)
    {
        printf("\n\n____________________QLSV____________________\n\n");
        printf("1. kiem tra danh sach rong\n");
        printf("2. hien thi vi tri dau tien trong danh sach\n");
        printf("3. hien thi vi tri ke tiep trong danh sach\n");
        printf("0. THoat!!!\n");
        printf("___________________________________________\n\n");

        printf("Nhap lua chon: ");
        int lc;
        scanf("%d", &lc);
        if (lc == 1)
        {

            if (empty(L))
            {
                printf("danh sach rong.");
            }
            else
            {
                printf("danh sach day.");
            }
        }
        else if (lc == 2)
        {
            printf("%d", first(L));
        }

        else if (lc == 3)
        {
            // printf("%d", next(L));
        }
    }

    // print(L);
    // printf ("\n");
    // sort(&L);
    // print(L);
    // return 0;
}