/*
 * 1.3 이항계수
 */

#define MAXN 200

#include <stdio.h>

// 일반적인 이항계수 계산(중복 처리 없음)
long long choose(int n, int r) {
    static int count = 0;

    count += 1;
    printf("%d\n", count);

    if (r == 0 || r == n) {
        return 1;
    }

    return choose(n - 1, r - 1) + choose(n - 1, r);
}

// 메모이제이션을 이용한 이항계수 계산
long long choose_memoization(int n, int r) {
    static long long memo[MAXN][MAXN];
    static int count = 0;

    count += 1;
    printf("%d\n", count);

    if (memo[n][r] > 0) return memo[n][r];

    if (r == 0 || r == n) return memo[n][r] = 1;

    return memo[n][r] = choose_memoization(n - 1, r - 1) + choose_memoization(n - 1, r);
}

int main() {
    int n, r;

    scanf("%d %d", &n, &r);
    printf("%d", choose_memoization(n, r));

    return 0;
}