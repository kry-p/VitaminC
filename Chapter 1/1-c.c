/*
 * 1-c. m개의 자연수를 더해 n을 만드는 모든 방법
 */

#include <stdio.h>

void calculate_return_all(int m, int n, int *arr, int index) {
    int i;

    // 종료조건
    if (index == m) {
        if (n == 0) {
            for (int j = 0; j < index; j++) {
                printf("%d ", arr[j]);
            }
            printf("\n");
        }

        return; // 종료
    }

    // 재귀적으로 처리 (모든 경우의 수 시도)
    for (i = 1; i <= n; i++) {
        arr[index] = i;
        dist_nat(m, n - i, arr, index + 1);
    }
}

int main() {
    int arr[100];
    int num1 = 5, num2 = 3;

    dist_nat(num2, num1, arr, 0);

    return 0;
}