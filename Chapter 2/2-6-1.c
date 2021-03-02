/*
 * 2-6-1. 연속부분수열의 합
 * 재귀적으로 해결
 * max_sum1() : M(n)을 계산
 * max_sum2() : M'(n)을 계산 - n번째 요소를 포함하는 부분수열의 최댓값
 *
 * 시간복잡도 O(n^2)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int num1, int num2) {
    if (num1 > num2) return num1;
    else return num2;
}

// 호출 횟수 : size(size-1)/2
int max_sum2(int arr[], int size) {
    if (size == 1) return arr[0];

    // arr[n-1]을 포함한 것 중 최댓값
    return max(max_sum2(arr, size - 1) + arr[size - 1], arr[size - 1]);
}

// 중복 계산으로 인해 느려짐
// 호출 횟수 : size
int max_sum1(int arr[], int size) {
    if (size == 1) return arr[0];

    // arr[n-1]을 포함한 것과 포함하지 않은 것 중 최댓값
    return max(max_sum2(arr, size), max_sum1(arr, size - 1));
}


int main() {
    int size = 10000;
    srand(time(NULL));
    int arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 201 - 100; // -100~100까지의 난수 생성
    }

    printf("result : %d", max_sum1(arr, size));
    return 0;
}

