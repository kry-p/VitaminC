/*
 * 1-5. 금액 맞추기
 *
 * 이 방법은 pay()의 for 루프에서 중복 계산이 있다.
 * 상위 화폐단위로 모두 지불하지 않았을 때 나머지 하위 화폐단위로 나누어 떨어질 경우 모든 하위 화폐단위에 대해 중복 계산이 발생한다.
 */

#define MAXN 50

#include <stdio.h>

int pay(int money, int bills[], int n) {
    int count = 0, i, t;

    if (n == 1) {
        if (money % bills[0] == 0) {
            printf("%d * %d\n", bills[0], money/bills[0]);
            return 1;
        }
        else{
            return 0;
        }
    }

    t = money / bills[n - 1]; // 현재 계산중인 금액권을 사용할 수 있는 최대 개수

    for (i = 0; i <= t; i++) {
        printf("%d * %d, ",bills[n-1], i);
        count += pay(money - bills[n - 1] * i, bills, n - 1);
    }

    return count;
}

int main() {
    int num_bills, money;
    int bills[MAXN];

    printf("input number of bills : ");
    scanf("%d", &num_bills);

    printf("input bills : ");
    for (int i = 0; i < num_bills; i++) {
        scanf("%d", &bills[i]);
    }

    printf("input money : ");
    scanf("%d", &money);

    printf("%d\n", pay(money, bills, num_bills));

    return 0;
}