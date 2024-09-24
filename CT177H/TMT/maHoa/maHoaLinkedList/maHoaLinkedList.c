#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} CharNode;

typedef struct IntNode {
    int data;
    struct IntNode* next;
} IntNode;

// Hàm tạo nút cho danh sách liên kết chứa ký tự
CharNode* createCharNode(char data) {
    CharNode* newNode = (CharNode*)malloc(sizeof(CharNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm tạo nút cho danh sách liên kết chứa số nguyên
IntNode* createIntNode(int data) {
    IntNode* newNode = (IntNode*)malloc(sizeof(IntNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm phần tử vào danh sách liên kết ký tự
void appendCharNode(CharNode** head, char data) {
    CharNode* newNode = createCharNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        CharNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Hàm thêm phần tử vào danh sách liên kết số nguyên
void appendIntNode(IntNode** head, int data) {
    IntNode* newNode = createIntNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        IntNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Hàm mã hóa
void encode(CharNode* source, IntNode* key, CharNode** dest) {
    CharNode* sourceTemp = source;
    IntNode* keyTemp = key;
    int keyCount = 0;

    while (sourceTemp != NULL) {
        if (keyTemp == NULL) {
            keyTemp = key;  // Quay lại đầu khóa nếu duyệt hết khóa
        }

        // Mã hóa ký tự
        char encodedChar = sourceTemp->data + keyTemp->data;
        appendCharNode(dest, encodedChar);

        sourceTemp = sourceTemp->next;
        keyTemp = keyTemp->next;
    }
}

// Hàm nhập chuỗi bất kỳ thành linked list
void inputString(CharNode** head) {
    char temp[100];
    printf("Nhap chuoi can ma hoa: ");
    fgets(temp, 100, stdin);
    temp[strcspn(temp, "\n")] = '\0';  // Loại bỏ ký tự xuống dòng

    for (int i = 0; i < strlen(temp); i++) {
        appendCharNode(head, temp[i]);
    }
}

// Hàm nhập khóa thành linked list
void inputKey(IntNode** head) {
    int length;
    printf("Nhap so phan tu cua khoa: ");
    scanf("%d", &length);

    printf("Nhap cac gia tri cua khoa: ");
    for (int i = 0; i < length; i++) {
        int value;
        scanf("%d", &value);
        appendIntNode(head, value);
    }
}

// Hàm in danh sách liên kết ký tự
void printCharList(CharNode* head) {
    CharNode* temp = head;
    while (temp != NULL) {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Hàm in danh sách liên kết số nguyên
void printIntList(IntNode* head) {
    IntNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    CharNode* source = NULL; // Danh sách liên kết cho chuỗi nguồn
    IntNode* key = NULL;     // Danh sách liên kết cho khóa
    CharNode* encoded = NULL; // Danh sách liên kết cho chuỗi đã mã hóa


    // Nhập chuỗi và khóa
    // getchar();  // Đọc ký tự xuống dòng sau lệnh scanf trước đó
    inputString(&source);
    inputKey(&key);

    // Mã hóa chuỗi
    encode(source, key, &encoded);

    // In kết quả
    printf("Source: ");
    printCharList(source);

    printf("Encoded: ");
    printCharList(encoded);

    return 0;
}
