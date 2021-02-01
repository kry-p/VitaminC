/*
 * 1-4-2. 더졸려 씨가 혼나지 않으려면?
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int digit_counter(int num) {
    int count = 0;
    int temp = num;

    do {
        if (temp % 2 == 1) {
            count += 1;
        }
        temp /= 2;
    } while (temp > 0);

    return count;
}

int main() {
    int workday = 20; // 일하는 날

    long long rep = pow(2, workday);
    long long all = pow(3, workday); // 전체 사건 수
    long long count = 0; // 혼나지 않은 사건 수

    int work = 0; // 지각 여부를 저장(bit 연산용)
    const int LATE = 7; // 연속 지각 판정(3일 연속, bit 111)
    int result; // 지각 판정용 변수
    int temp; // 지각 판정용 변수(bit-shift)

    bool isFailed;

    for (int i = 0; i < rep; i++) {
        isFailed = false;
        temp = work;
        printf("%d에 대해 혼났는지를 판정합니다.\n", temp);
        for (int j = 0; j < workday - 3; j++) {
            result = temp & LATE;

            if (result == 7) {
                isFailed = true;
            }
            temp >>= 1;
        }
        if (!isFailed) {
            count += pow(2, digit_counter(work));
            printf("혼나지 않고 다음으로 넘어갑니다.\n");
        } else
            printf("혼났으므로 다음으로 넘어갑니다.\n");
        work += 1;
    }

    double percentage = (((double) count / all) * 100);

    printf("혼난 사건의 수 : %lld\n", all - count);
    printf("혼나지 않은 사건의 수 : %lld\n", count);

    printf("혼나지 않을 확률 : %.2f%%", percentage);

    return 0;
}