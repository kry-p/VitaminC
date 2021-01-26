/*
 * 1.1 팩토리얼 계산
 */

#include <stdio.h>

// 일반적인 방법 (반복문)
long factorial(int n) {
    long r = 1;

    for (int i = 2; i <= n; i++) {
        r *= i;
    }

    return r;
}

// 재귀적 방
long factorial_recursive(int n) {
    if (n == 1) return 1;
    else return n * factorial_recursive(n - 1);
}


int main() {
    printf("%ld\n", factorial(20));
    printf("%ld\n", factorial_recursive(20));
    return 0;
}