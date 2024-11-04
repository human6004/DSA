#include "alistlib.h"
// #include "plistlib.h"


void readList(int a[], int sizeArray, List *L);

void swap(Position a, Position b, List* L);

void bubbleSort(List* L);

void selectionSort(List * L);

void insertionSort(List *L);









void readList(int a[], int sizeArray, List *L) {
    while (sizeArray > 0) { 
        insertFirst(a[sizeArray - 1], L); // Thêm phần tử từ mảng vào danh sách
        sizeArray--;
    }
}



void swap(Position a, Position b, List* L) {
    ElementType temp = getAt(a, *L);
    setAt(a, getAt(b, *L), L);
    setAt(b, temp, L);
}

void bubbleSort(List* L) {
    int length = len(*L);
    for(int i = 1; i <= length; i++){
        for(int j = 1; j <= length-1; j++){
            if(getAt(j,*L) > getAt(j+1,*L)){
                swap(j,j+1,L);
            }
        }
    }
}

void selectionSort(List * L){
    int length = len(*L);
    for(int i = 1; i < length; i ++){
        int minPos = i;
        for(int j = i + 1; j < length + 1; j++){
            if(getAt(minPos, (*L)) > getAt(j, (*L))){
                minPos = j; 
            }
        }
        swap(i, minPos, L);
    }
}

void insertionSort(List *L){
    int lenght = len(*L);
    for(int i = 1; i <= lenght; i++){
        int temp = getAt(i,(*L));
        int pos = i;
        // so sánh vị trí a[i] với a[i+1]
        while(pos > 1 && getAt(pos - 1, *L) > temp){
            setAt(pos, getAt(pos - 1, *L),L);
            pos--;
        }
        setAt(pos,temp, L);
    }
}