#include <stdio.h>
#include <string.h>

// Hàm mã hóa
void encode(char* source, int* key, int key_length, char* dest) {
    int source_length = strlen(source);
    for (int i = 0; i < source_length; i++) {
        // Tính chỉ số khóa theo chu kỳ
        int key_value = key[i % key_length];
        
        // Mã hóa ký tự bằng cách cộng với giá trị khóa
        dest[i] = source[i] + key_value;
    }
    dest[source_length] = '\0'; // Kết thúc chuỗi kết quả
}

// Hàm nhập chuỗi và khóa
void input(char* source, int* key, int* key_length) {
    // Nhập chuỗi
    printf("Nhap chuoi can ma hoa: ");
    fgets(source, 100, stdin);
    source[strcspn(source, "\n")] = '\0'; // Xóa kí tự xuống dòng

    // Nhập độ dài khóa
    printf("Nhap do dai cua khoa: ");
    scanf("%d", key_length);

    // Nhập các giá trị khóa
    printf("Nhap cac gia tri cua khoa: ");
    for (int i = 0; i < *key_length; i++) {
        scanf("%d", &key[i]);
    }
}

int main() {
    // Khai báo biến chuỗi và khóa
    char source[100]; // Chuỗi nguồn
    int key[100];     // Khóa mã hóa
    int key_length;   // Độ dài khóa

    // Chuỗi đích sau khi mã hóa
    char dest[100]; // Đảm bảo đủ bộ nhớ cho chuỗi mã hóa

    // Nhập dữ liệu
    input(source, key, &key_length);

    // Gọi hàm mã hóa
    encode(source, key, key_length, dest);

    // In kết quả
    printf("Source: %s\n", source);
    printf("Encoded: %s\n", dest);

    return 0;
}
