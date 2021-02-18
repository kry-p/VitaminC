/*
 * 2-5. 최대 이익 투자
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
int max_return[MAXN][MAXM];

void calculate_return(int n, int m) {
    int max, temp;

    // 투자할 기업이 하나뿐일 때
    // 기업 0에만 투자함
    for (int i = 0; i <= m; i++){
        max_return[0][i] = r[0][i];
    }

    // i : 투자할 기업번호
    for (int i = 1; i <= n; i++) {
        // j : 투자할 양
        for (int j = 1; j <= m; j++) {
            max = -1; // 최댓값 비교를 위해 초기화
            // k : i번째 기업에 k만큼 투자하는 모든 가짓수
            for (int k = 0; k <= j; k++) {
                temp = max_return[i - 1][k] + r[i][j - k];
                if (temp > max)
                    max = temp;
            }
            max_return[i][j] = max; // 모든 가짓수를 비교해 최댓값을 반환
        }
    }
}

int main() {
    int m, n;

    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++) {
        r[i][0] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &r[j][i]);
        }
    }

    calculate_return(n - 1, m);
    printf("Max return: %d\n", max_return[n - 1][m]);

    return 0;
}
