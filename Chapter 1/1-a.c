/*
 * 1-a. 1^k + 2^k + ... + n^k 계산하기
 *
 */

#include <stdio.h>
#include <math.h>

void sigma(int n, int k) {
    int result = 0;

    for (int i = 1; i <= n; i++) {
        result += pow(i, k);
    }

    printf("result : %d\n", result);
}

int sigma_recursive(int n, int k) {
    static int result = 0;

    if (n == 1) return 1;

    return pow(n, k) + sigma_recursive(n - 1, k);
}

int main() {
    sigma(10, 3);
    printf("result : %d", sigma_recursive(10, 3));
    return 0;
}