/*
 * 1-4-1. 나졸려 씨가 혼나지 않으려면?
 */

#include <stdio.h>
#include <math.h>

int main() {
    int workday = 20; // 일하는 날

    int rep = pow(2, workday);
    int count = 0; // 혼난 횟수

    int work = 0; // 지각 여부를 저장(bit 연산용)
    const int LATE = 7; // 연속 지각 판정(3일 연속, bit 111)
    int result; // 지각 판정용 변수
    int temp; // 지각 판정용 변수(bit-shift)

    for (int i = 0; i < rep; i++) {
        temp = work;
//        printf("%d에 대해 혼났는지를 판정합니다.\n", temp);
        for (int j = 0; j < workday - 3; j++) {
            result = temp & LATE;

            if (result == 7) {
                count += 1;
//                printf("혼났으므로 다음으로 넘어갑니다.\n");
                break;
            }
            temp >>= 1;
        }
        work += 1;
    }

    double percentage = (((double) (rep - count) / rep) * 100);

    printf("혼난 사건의 수 : %d\n", count);
    printf("혼나지 않은 사건의 수 : %d\n", rep - count);

    printf("혼나지 않을 확률 : %.2f%%", percentage);

    return 0;
}