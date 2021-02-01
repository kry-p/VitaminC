/*
 * 0-c. 추가 문제
 */

#include <stdio.h>

// 0.c ) int 형 정수를 이진수로 변환했을 때의 1의 개수 세기
int digit_counter(int num) {
    int count = 0;
    int temp = num;

    do {
        if (temp % 2 == 1) {
            count += 1;
        }
        temp /= 2;
    } while (temp > 0);

    return count;
}

int main() {
    printf("%d", digit_counter(1000));

    return 0;
}