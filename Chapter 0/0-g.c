/*
 * 0-g. 10진수 > 2진수 변환
 */

#include <stdio.h>
#include <stdlib.h>

void decimal_to_binary(int num) {
    // 동적 배열 생성
    int size = 1;
    int *result = (int *) calloc(size, sizeof(int));

    // 계산
    int i = 0;

    do {
        result[i] = num % 2;
        num /= 2;
        if (num != 0) {
            size++;
            result = realloc(result, sizeof(int) * size);
        }

        i += 1;
    } while (num != 0);

    // 나머지 계산법이므로 출력 순서는 반전되어야 함
    for (i = size - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    // 메모리 해제
    free(result);
}

int main() {
    decimal_to_binary(256);

    return 0;
}