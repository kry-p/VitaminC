/*
 * 1-6-2. 순서를 구분하는 수분할
 */

#include <stdio.h>

int partition_directional(int n) {
    int count = 0, i;

    for (i = 1; i <= n - 1; i++) {
        count += partition_directional(n - i);
    }

    return count + 1;
}

int main() {
    int num;
    scanf("%d", &num);

    printf("total : %d", partition_directional(num));

    return 0;
}