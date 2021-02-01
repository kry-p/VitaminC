/*
 * 1.4 피보나치 수열
 */

#define MAXN 200

#include <stdio.h>

long long fibonacci(int n) {
    if (n == 1 || n == 2) return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

long long fibonacci_memoization(int n) {
    static long long memo[MAXN];

    if (memo[n] > 0) return memo[n];

    if (n == 1 || n == 2) return memo[n] = 1;
    else return memo[n] = fibonacci_memoization(n - 1) + fibonacci_memoization(n - 2);
}

long long fibonacci_conventional(int n) {
    long long prev, next, temp;

    if (n == 1 || n == 2) return 1;

    prev = 1;
    next = 1;

    for (int i = 3; i <= n; i++) {
        temp = next;
        next = prev + next;
        prev = temp;
    }

    return next;
}

int main() {
    printf("%lld\n", fibonacci(20));
    printf("%lld\n", fibonacci_memoization(20));
    printf("%lld", fibonacci_conventional(20));

    return 0;

}