/*
 * 1-b. 파스칼의 삼각형
 */

#include <stdio.h>

int combination(int n, int r) {
    if (n == 0 || r == 0 || n == r) return 1;

    return combination(n - 1, r - 1) + combination(n - 1, r);
}

void print_pascal(int k) {
    int i, j;

    for (i = 0; i < k; i++) {
        for (j = i; j < k - 1; j++) {
            printf("\t");
        }

        for (j = 0; j <= i; j++) {
            printf("%d\t\t", combination(i, j));
        }
        printf("\n");
    }
}

int main() {
    print_pascal(20);
    return 0;
}