/*
 * 2-3. 경치의 아름다움
 *
 *
 * sample
5 5
1 2 3 2 1
1 2 3 2 1
1 2 3 2 1
1 2 3 2 1
1 2 3 2 1

 */

#include <stdio.h>
#include <stdlib.h>

enum {
    LEFT, UP
};

// 동적 2차원 배열 생성기
long long **array_generator(int m, int n) {
    long long **array = (long long **) calloc(n, sizeof(long long *));

    for (int i = 0; i < n; i++) {
        array[i] = (long long *) calloc(m, sizeof(long long));
    }

    return array;
}

// 최댓값
long long max(long long m, long long n) {
    if (m > n) return m;
    else return n;
}

void print_path(long long **from, int m, int n) {
    if (m == 0 && n == 0) return;

    printf("(%d %d)", m, n);

    if (from[m][n] == LEFT)
        print_path(from, m - 1, n);
    else
        print_path(from, m, n - 1);
}

long long beautiful_path_counter(long long **map, int m, int n) {
    if (m == 0 && n == 0) return map[0][0];
    if (m == 0) return beautiful_path_counter(map, m, n - 1) + map[m][n];
    if (n == 0) return beautiful_path_counter(map, m - 1, n) + map[m][n];

    return max(beautiful_path_counter(map, m - 1, n), beautiful_path_counter(map, m, n - 1)) + map[m][n];
}

long long beautiful_path_counter_2(long long **map, int m, int n) {
    // 동적 2차원 배열 생성
    long long **path = array_generator(m, n);
    long long **from = array_generator(m, n);

    path[0][0] = map[0][0];

    for (int i = 1; i < m; i++) {
        path[i][0] = path[i - 1][0] + map[i][0];
        from[i][0] = LEFT; // 어디에서 왔는지 기록
    }

    for (int i = 1; i < n; i++) {
        path[0][i] = path[0][i - 1] + map[0][i];
        from[0][i] = UP;
    }

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++) {
            if (path[i - 1][j] > path[i][j - 1]) from[i][j] = LEFT;
            else from[i][j] = UP;

            path[i][j] = max(path[i - 1][j], path[i][j - 1]) + map[i][j];
        }

    print_path(from, m-1, n-1);

    long long result = path[m - 1][n - 1];

    // 동적 할당된 메모리 해제
    for (int i = 0; i < n; i++) {
        free(path[i]);
        free(from[i]);
    }

    free(path);
    free(from);

    return result;
}


int main() {
    int m, n;

    scanf("%d %d", &m, &n);

    // 동적 2차원 배열 생성
    long long **map = array_generator(m, n);

    // 지도 정보 입력
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%lld", &map[i][j]);

    printf("%lld\n", beautiful_path_counter(map, m - 1, n - 1));
    printf("%lld\n", beautiful_path_counter_2(map, m, n));

    // 동적 할당된 메모리 해제
    for (int i = 0; i < n; i++)
        free(map[i]);

    free(map);

    return 0;

}