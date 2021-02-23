/*
 * 2-5-2. 최대 이익 투자
 * 모든 투자 방법을 표시하도록 수정
 *
4 3
2 3 1
4 5 3
6 6 7
9 8 9

 */

// 비교할 최대 크기
#define MAXM 10
#define MAXN 10

#include <stdio.h>

int r[MAXN][MAXM];

void calculate_return_all(int m, int n, int arr[], int index) {
    int i, result;

    // 종료조건
    if (index == m) {
        if (n == 0) {
            result = 0;
            for (int j = 0; j < index; j++) {
                printf("%d ", arr[j]);
                result += r[arr[j]][j];
            }
            printf(" return : %d\n", result);
        }

        return; // 종료
    }

    // 재귀적으로 처리 (모든 경우의 수 시도)
    for (i = 0; i <= n; i++) {
        arr[index] = i;
        calculate_return_all(m, n - i, arr, index + 1);
    }
}

int main() {
    int m, n;
    int arr[100];

    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++) {
        r[i][0] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &r[i][j]);
        }
    }

    calculate_return_all(n, m, arr, 0);

    return 0;
}
