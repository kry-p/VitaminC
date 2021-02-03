/*
 * 1-6. 수분할
 */

#include <stdio.h>

int partition(int div, int max) {
    int count = 0;

    // 재귀 종료 조건 (모든 수분할은 최종적으로 div=0이 됨)
    if (div == 0){
        return 1;
    }

    // 수분할하고자 하는 수보다 최댓값이 커지면 중복이 발생
    if (div < max) {
        max = div;
    }

    for (int i = 1; i <= max; i++){
        count += partition(div - i, i);
    }

    return count;
}

int main() {
    int num1, num2;

    scanf("%d", &num1);
    scanf("%d", &num2);

    int arr[num1];
    printf("total : %d", partition(num1, num2));

    return 0;
}