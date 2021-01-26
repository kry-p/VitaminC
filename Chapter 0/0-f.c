/*
 * 0-f. 다중 for 루프
 */

#define N 10

#include <stdio.h>

int main() {
    int i, j, k, x = 0;

    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) {
            for (k = j; k < N; k++) {
                x++;
            }
        }
    }
    printf("%d\n", x); // 220

    return 0;
}