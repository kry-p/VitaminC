/*
 * 2-6. 연속부분수열의 합
 * 수열의 연속된 일부를 선택한 모든 부분수열 중 최댓값을 구하는 프로그램
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 해결은 가능하나 느림 (시간복잡도 O(n^3))
int max_consecutive_sum(int arr[], int size) {
    int sum, max_sum = arr[0];

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            if (sum > max_sum)
                max_sum = sum;
        }
    }

    return max_sum;
}

// 해결은 가능하나 배열이 크면 느림 (시간복잡도 O(n^2))
int max_consecutive_sum_2(int arr[], int size) {
    int sum, max_sum = arr[0];

    for (int i = 0; i < size; i++) {
        sum = 0;
        for (int j = i; j < size; j++) {
            sum += arr[j];
            if (sum > max_sum)
                max_sum = sum;
        }
    }

    return max_sum;
}

int main() {
    int size = 100000;
    srand(time(NULL));
    int arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 201 - 100; // -100~100까지의 난수 생성
    }

    printf("result : %d", max_consecutive_sum_2(arr, size));

    return 0;
}