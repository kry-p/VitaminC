/*
 * 2-2. 출근길의 개수
 */

#include <stdio.h>
#include <stdlib.h>

long long path_counter(long long **map, int m, int n) {
    if (map[m][n] == 0) return 0;
    if (m == 0 && n == 0) return 1;

    return ((m > 0) ? path_counter(map, m - 1, n) : 0) + ((n > 0) ? path_counter(map, m, n - 1) : 0);
}

long long path_counter_2(long long **map, int m, int n) {
    // 동적 2차원 배열 생성
    long long **path = (long long **) calloc(n, sizeof(long long *));

    for (int i = 0; i < n; i++) {
        path[i] = (long long *) calloc(m, sizeof(long long));
    }

    path[0][0] = map[0][0];

    for (int i = 1; i < m; i++) {
        if (map[i][0] == 0) path[i][0] = 0;
        else path[i][0] = path[i - 1][0];
    }

    for (int j = 1; j < n; j++) {
        if (map[0][j] == 0) path[0][j] = 0;
        else path[0][j] = path[0][j - 1];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (map[i][j] == 0) path[i][j] = 0;
            else path[i][j] = path[i - 1][j] + path[i][j - 1];
        }
    }

    long long result = path[m - 1][n - 1];

    // 동적 할당된 메모리 해제
    for (int i = 0; i < n; i++)
        free(path[i]);

    free(path);

    return result;
}

int main() {
    int m, n;

    scanf("%d %d", &m, &n);

    // 동적 2차원 배열 생성
    long long **map = (long long **) calloc(n, sizeof(long long *));

    for (int i = 0; i < n; i++) {
        map[i] = (long long *) calloc(m, sizeof(long long));
    }

    // 지도 정보 입력
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%lld", &map[i][j]);

    printf("%lld\n", path_counter(map, m - 1, n - 1));
    printf("%lld\n", path_counter_2(map, m, n));

    // 동적 할당된 메모리 해제
    for (int i = 0; i < n; i++)
        free(map[i]);

    free(map);

    return 0;

}