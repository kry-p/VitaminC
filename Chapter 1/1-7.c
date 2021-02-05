/*
 * 1-7. 그레이 코드 *
 * print_code() : 결과물 출력
 * print_gray() : 그레이 코드 작성
 * print_gray_reverse() : 그레이 코드 작성 (역순)
 */

#define MAXN 20

void print_gray_reverse(int code[], int size, int index);

#include <stdio.h>

void print_code(int code[], int len) {
    for (int i = 0; i < len; i++)
        printf("%d", code[i]);
    printf("\n");
}

void print_gray(int code[], int size, int index) {
    if (index == size) {
        print_code(code, size);
        return;
    }

    // 각 비트에 대해 0과 1로 나눈 다음 하위 그레이 코드를 생성
    code[index] = 0;
    print_gray(code, size, index + 1);

    code[index] = 1;
    print_gray_reverse(code, size, index + 1);
}

void print_gray_reverse(int code[], int size, int index) {
    if (index == size) {
        print_code(code, size);
        return;
    }
    code[index] = 1;
    print_gray(code, size, index + 1);

    code[index] = 0;
    print_gray_reverse(code, size, index + 1);
}

int main() {
    int code[MAXN], size;
    scanf("%d", &size);

    print_gray(code, size, 0);

    return 0;
}