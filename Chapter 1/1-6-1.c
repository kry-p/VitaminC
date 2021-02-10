/*
 * 1-6-1. 수분할 - 중복 계산 없애기
 */

#define MAXN 200

#include <stdio.h>

int partition(int div, int max) {
    static int memo[MAXN][MAXN];
    int count = 0;

    // 재귀 종료 조건 (모든 수분할은 최종적으로 div=0이 됨)
    if (div == 0) {
        return 1;
    }

    // 이미 계산했으면 그 값을 반환
    if (memo[div][max] > 0)
        return memo[div][max];

    // 수분할하고자 하는 수보다 최댓값이 커지면 중복이 발생
    if (div < max) {
        max = div;
    }

    for (int i = 1; i <= max; i++) {
        count += partition(div - i, i);
    }

    return memo[div][max] = count;
}

int main() {
    int num1, num2;

    scanf("%d", &num1);
    scanf("%d", &num2);

    printf("total : %d", partition(num1, num2));

    return 0;
}