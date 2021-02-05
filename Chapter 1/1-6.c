/*
 * 1-6. 수분할
 */

#define MAXN 30

#include <stdio.h>

int partition(int div, int max, int arr[], int length) {
    int count = 0;

    // 수분할하고자 하는 수보다 최댓값이 커지면 중복이 발생
    if (div < max) {
        max = div;
    }

    // 재귀 종료 조건 (모든 수분할은 최종적으로 div=0이 됨)
    if (div == 0) {
        for (int i = 0; i < length; i++) {
            printf("%d ", arr[i]);
        }

        printf("\n");
        return 1;
    }

    for (int i = 1; i <= max; i++) {
        arr[length] = i;
        count += partition(div - i, i, arr, length + 1);
    }

    return count;
}

int main() {
    int num1, num2;
    int num[MAXN];

    scanf("%d", &num1);
    scanf("%d", &num2);

    printf("total : %d", partition(num1, num2, num, 0));

    return 0;
}